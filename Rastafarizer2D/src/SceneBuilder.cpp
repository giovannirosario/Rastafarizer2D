#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "SceneBuilder.h"
#include "Color.h"
#include "Line.h"
#include <iostream>
#include <fstream>
#include <sstream>

SceneBuilder::SceneBuilder() {}

SceneBuilder::~SceneBuilder() {}

void SceneBuilder::read_file(std::string f_name) {
    std::ifstream t(f_name);
    std::stringstream buffer;
    buffer << t.rdbuf();
    scene = buffer.str();
}

void SceneBuilder::build_scene(std::string f_name) {
    rapidjson::Document scene_json;
    scene_json.Parse(scene.c_str());

    Color bg_color;
    int width, height;

    if (scene_json.HasMember("width")) {
        width = scene_json["width"].GetInt();
    }

    if (scene_json.HasMember("height")) {
        height = scene_json["height"].GetInt();
    }

    if (scene_json.HasMember("background_color")) {
        bg_color = hex_to_color(scene_json["background_color"].GetString());
    }

    if (scene_json.HasMember("objects")) {
        const rapidjson::Value& objects = scene_json["objects"];
        for (rapidjson::SizeType i = 0; i < objects.Size(); i++) {
            rapidjson::Document scene_object;
            scene_object.Parse(objects[i].GetString());
            if (scene_object.HasMember("type")) {
                std::string object_type (scene_object["type"].GetString());
                if (object_type == "line") {
                    build_line(objects[i].GetString());
                }
            }
        }
    }
}

void SceneBuilder::build_line(const char * object_string) {
    rapidjson::Document object_json;
    object_json.Parse(object_string);
    int x1, y1;
    int x2, y2;
    Color color;

    if (object_json.HasMember("color")) {
        color = hex_to_color(object_json["color"].GetString());
    }

    if (object_json.HasMember("start")) {
        const rapidjson::Value& values = object_json["start"];
        x1 = values[0].GetInt();
        y1 = values[1].GetInt();
    }
    
    if (object_json.HasMember("end")) {
        const rapidjson::Value& values = object_json["end"];
        x2 = values[0].GetInt();
        y2 = values[1].GetInt();
    }

    Line line = Line(Point2D(x1,y1), Point2D(x2,y2), color);
    objects.push_back(line);
}

void SceneBuilder::draw_scene(Canvas canvas) {
    for ( auto obj = objects.begin(); obj != objects.end(); obj++ ) {
        obj->draw(canvas);
    }
}

Color SceneBuilder::hex_to_color(const char * hex_string) {
    int r, g, b;
    sscanf(hex_string, "%02x%02x%02x", &r, &g, &b);
    std::cout << r << g << b << std::endl;
    Color c = Color(r,g,b);
    return c;
}