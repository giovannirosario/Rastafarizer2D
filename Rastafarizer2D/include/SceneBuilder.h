#ifndef _SCENE_BUILDER_H_
#define _SCENE_BUILDER_H_

#include <iostream>
#include "rapidjson/document.h"
#include "Canvas.h"
#include "Color.h"
#include "Exporter.h"
#include "Point2D.h"

class SceneBuilder {
    private:
        std::string scene;
        
    public:
        SceneBuilder(); 
        ~SceneBuilder();
        void read_file(std::string f_name);
        void draw_scene(std::string f_name);
        Color hex_to_color(const char * hex_string);
};

#endif