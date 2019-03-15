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
        if ((y * get_width() + x) < (get_width() * get_height())-1) {
            canvas[y * get_width() + x] = color;

            if (anti_aliasing) {
                draw_antiAliased_neighboors(x,y,color);
            }
        }
    }
 }

 void Canvas::draw_antiAliased_neighboors(int x, int y, Color color) {
     for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1;j++) {
            if (i == 0 && j == 0) {j++;}
            int new_x = x + j;
            int new_y = y + i;
            Color avg_color;
            avg_color = this->get_average_color(new_x, new_y);
            if ((new_y * get_width() + new_x) < (get_width() * get_height())-1) {
                Color current = canvas[new_y * get_width() + new_x];
                if (!(color==current)) {
                    canvas[new_y * get_width() + new_x] = avg_color;
                }
            }
        }
    }
 }


Color Canvas::get_average_color(int x, int y) {
    int sum_r = 0;
    int sum_g = 0;
    int sum_b = 0;

    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1;j++) {
            if (i == 0 && j == 0) {j++;}
            int new_x = x + j;
            int new_y = y + i;
            if(new_x >= 0 && new_y >= 0) { 
                if ((new_y * get_width() + new_x) <= (get_width() * get_height())-1) {
                    sum_r += canvas[new_y * get_width() + new_x].get_r();
                    sum_g += canvas[new_y * get_width() + new_x].get_g();
                    sum_b += canvas[new_y * get_width() + new_x].get_b();
                }
            }
        }
    }

    return Color(sum_r/8, sum_g/8, sum_b/8);
 }

void Canvas::set_antiAliasing(bool s) {
    anti_aliasing = s;
}

bool Canvas::is_antiAliasing() {
    return anti_aliasing;
}