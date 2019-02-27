#include "Canvas.h"
#include "Color.h"

Canvas::Canvas(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
    
    this->canvas = new Color[width * height];
}

Canvas::~Canvas() {}

void Canvas::set_width(unsigned int width) {
    this->width = width;
    this->canvas = new Color[width * height];
}
void Canvas::set_height(unsigned int height) {
    this->height = height;
    this->canvas = new Color[width * height];
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
    for(unsigned int i = 0; i < get_height() * get_width() ; i++)
    {
        this->canvas[i] = bg_color;
    }
}
void Canvas::draw_line(Point2D start, Point2D end, Color color) {
    unsigned int x_1 = start.get_x();
    unsigned int y_1 = start.get_y();
    unsigned int x_2 = end.get_x();
    unsigned int y_2 = end.get_y();


    float delta_x = x_2 - x_1;
    float delta_y = y_2 - y_1;
    float p_k = 2 * (delta_y - delta_x);

    unsigned int x = x_1;
    unsigned int y = y_1;

    this->canvas[y * get_width() + x] = color;

    for(x = x + 1; x < x_2; x++) {
        if (p_k < 0) {
            p_k += 2 * delta_y;
        }
            
        else {
            y++;
            p_k += 2 * delta_y - 2 * delta_x;
        }

        this->canvas[y * get_width() + x] = color;
    }
 }