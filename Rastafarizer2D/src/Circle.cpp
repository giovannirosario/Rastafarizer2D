#include "Circle.h"
#include "Canvas.h"
#include "Point2D.h"
#include "Color.h"

Circle::Circle() {}

Circle::Circle(Point2D start, int radius, Color color) {
    this->start = start;
    this->radius = radius;
    this->color = color;
}

Circle::~Circle() {}

void Circle::draw_shape(Canvas& canvas) {
    int x0 = start.get_x();
    int y0 = start.get_y();
    int x = radius - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y) {
        canvas.draw_pixel(x0 + x, y0 + y, color);
        canvas.draw_pixel(x0 + y, y0 + x, color);
        canvas.draw_pixel(x0 - y, y0 + x, color);
        canvas.draw_pixel(x0 - x, y0 + y, color);
        canvas.draw_pixel(x0 - x, y0 - y, color);
        canvas.draw_pixel(x0 - y, y0 - x, color);
        canvas.draw_pixel(x0 + y, y0 - x, color);
        canvas.draw_pixel(x0 + x, y0 - y, color);

        if (err <= 0)
        {
            y++;
            err += dy;
            dy += 2;
        }
        
        if (err > 0)
        {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}

Color Circle::get_color() {
    return this->color;
}

void Circle::set_color(Color color) {
    this->color = color;
}