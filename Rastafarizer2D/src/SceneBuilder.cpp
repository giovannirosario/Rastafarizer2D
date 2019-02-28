#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "SceneBuilder.h"
#include "Color.h"
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

void SceneBuilder::draw_scene(std::string f_name) {
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
}

Color SceneBuilder::hex_to_color(const char * hex_string) {
    int r, g, b;
    sscanf(hex_string, "%02x%02x%02x", &r, &g, &b);
    std::cout << r << g << b << std::endl;
    Color c = Color(r,g,b);
    return c;
}