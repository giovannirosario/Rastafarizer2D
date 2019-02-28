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
        std::string scene;
        std::vector<Object> objects; 
        
    public:
        SceneBuilder(); 
        ~SceneBuilder();
        void read_file(std::string f_name);
        void build_scene(std::string f_name);
        void build_line(const char * object_string);
        void draw_scene(Canvas canvas);
        Color hex_to_color(const char * hex_string);

};

#endif