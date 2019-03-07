#ifndef _SCENE_BUILDER_H_
#define _SCENE_BUILDER_H_

#include <iostream>
#include "rapidjson/document.h"
#include "Canvas.h"
#include "Color.h"
#include "Exporter.h"
#include "Point2D.h"
#include "Object.h"
#include <vector>

class SceneBuilder {
    private:
        Canvas canvas;
        std::string scene;
        std::vector<Object*> objects; 
        
    public:
        SceneBuilder();
        ~SceneBuilder();
        void read_file(std::string f_name);
        void write_file(std::string f_name);
        void build_scene();
        void build_line(const rapidjson::Value& _pt);
        void build_circle(const rapidjson::Value& _pt);
        void draw_scene();
        Color hex_to_color(const char * hex_string);
        void raster(std::string f_in, std::string f_out);
};

#endif