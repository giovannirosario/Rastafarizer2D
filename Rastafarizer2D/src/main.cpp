#include <iostream>
#include "Canvas.h"
#include "Color.h"
#include "Exporter.h"
#include "Point2D.h"
#include "SceneBuilder.h"

int main () {
    SceneBuilder scene_builder;
    scene_builder.raster("scene.json", "scene");
}