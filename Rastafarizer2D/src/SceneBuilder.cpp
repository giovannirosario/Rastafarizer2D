#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"

#include "SceneBuilder.h"
#include "Color.h"
#include "Line.h"
#include "Exporter.h"
#include "Canvas.h"
#include "Circle.h"

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

void SceneBuilder::write_file(std::string f_name) {
    Exporter exporter;
    exporter.export_ppm(canvas, f_name);
}

void SceneBuilder::build_scene() {
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
       for (auto& obj : scene_json["objects"].GetArray()) {
           if(obj.HasMember("type")) {
               std::string type = obj["type"].GetString();
               if (type == "line") {
                   build_line(obj);
               }
               else if (type == "circle") {
                   build_circle(obj);
               }
           }
       }
    }

    canvas.set_size(width, height);
    canvas.draw_background(bg_color);
}

void SceneBuilder::build_line(const rapidjson::Value& _pt) {
    int x1, y1;
    int x2, y2;
    Color color;

    if (_pt.HasMember("color")) {
        color = hex_to_color(_pt["color"].GetString());
    }

    if (_pt.HasMember("start")) {
        const rapidjson::Value& values = _pt["start"];
        x1 = values[0].GetInt();
        y1 = values[1].GetInt();
    }
    
    if (_pt.HasMember("end")) {
        const rapidjson::Value& values = _pt["end"];
        x2 = values[0].GetInt();
        y2 = values[1].GetInt();
    }

    Object * obj = new Line(Point2D(x1,y1), Point2D(x2,y2), color);
    objects.push_back(obj);
}

void SceneBuilder::build_circle(const rapidjson::Value& _pt) {
    int x1, y1;
    int radius;
    Color color;

    if (_pt.HasMember("color")) {
        color = hex_to_color(_pt["color"].GetString());
    }

    if (_pt.HasMember("start")) {
        const rapidjson::Value& values = _pt["start"];
        x1 = values[0].GetInt();
        y1 = values[1].GetInt();
    }
    
    if (_pt.HasMember("radius")) {
       radius = _pt["radius"].GetInt();
    }

    Object * obj = new Circle(Point2D(x1,y1), radius, color);
    objects.push_back(obj);
}

void SceneBuilder::draw_scene() {
    for (unsigned int i = 0; i < objects.size(); i++) {
        objects[i]->draw(canvas);
    }
}

Color SceneBuilder::hex_to_color(const char * hex_string) {
    int r, g, b;
    sscanf(hex_string, "%02x%02x%02x", &r, &g, &b);
    Color c = Color(r,g,b);
    return c;
}

void SceneBuilder::raster(std::string f_in, std::string f_out) {
    read_file(f_in);
    build_scene();
    draw_scene();
    write_file(f_out);
}