#include "Canvas.h"
#include "Color.h"
#include <iostream>

Canvas::Canvas() {}

Canvas::Canvas(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
    
    canvas = new Color[width * height];
}

Canvas::~Canvas() {}

void Canvas::set_size(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;;
    canvas = new Color[width * height];
}

unsigned int Canvas::get_width() {
    return this->width;
}

unsigned int Canvas::get_height() {
    return this->height;
}

Color * Canvas::get_canvas() {
    return canvas;
}

void Canvas::draw_background(Color bg_color) {
    for(unsigned int i = 0; i < get_height() * get_width() ; i++)
    {
        this->canvas[i] = bg_color;
    }
}
void Canvas::draw_pixel(int x, int y, Color color) {
    if(x >= 0 && y >= 0) {
        canvas[y * get_width() + x] = color;
    }
 }