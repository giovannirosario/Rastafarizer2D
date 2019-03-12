#include "FloodFill.h"
#include "Color.h"
#include "Canvas.h"

FloodFill::FloodFill(Canvas& canvas, int x, int y, Color new_color) {
    this->canvas = &canvas;
    this->x = x;
    this->y = y;
    this->new_color = new_color;

    Color * pixels = canvas.get_canvas();
    this->old_color = pixels[y * canvas.get_width() + x];

    fill(x,y);
}

FloodFill::~FloodFill() {}

void FloodFill::fill(int x, int y){
    Color * pixels = canvas->get_canvas();
    Color current = pixels[y * canvas->get_width() + x];
    int width = canvas->get_width();
    int height = canvas->get_height();

    if ((x < 0) || (x > width)) return;
    if ((y < 0) || (y > height)) return;

    if ((current == old_color) && !(current == new_color)) {
        canvas->draw_pixel(x,y,this->new_color);
        fill(x+1,y);
        fill(x,y+1);
        fill(x-1,y);
        fill(x,y-1);
    } else return;
}