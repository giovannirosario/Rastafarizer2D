#include "Canvas.h"

Canvas::Canvas(unsigned int width, unsigned int height) {

}
Canvas::~Canvas() {}

void Canvas::set_width(unsigned int width) {
    this->width = width;
}
void Canvas::set_height(unsigned int height) {
    this->height = height;
}

unsigned int Canvas::get_width() {
    return this->width;
}

unsigned int Canvas::get_height() {
    return this->height;
}

Color * Canvas::get_canvas() {
    return this->canvas;
}

void Canvas::draw_background(Color bg_color) {
    for(int i = 0; i < get_height() * get_width() ; i++)
    {
        this->canvas[i] = bg_color;
    }
}
void Canvas::draw_line(Point2D start, Point2D end, Color color) {

}