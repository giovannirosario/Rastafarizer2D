#include "Circle.h"
#include "Canvas.h"
#include "Point2D.h"
#include "Color.h"
#include "Line.h"

Circle::Circle() {}

Circle::Circle(Point2D start, int radius, Color stroke_color, int thickness) {
    this->start = start;
    this->radius = radius;
    this->stroke_color = stroke_color;
    this->thickness = thickness;
}

Circle::Circle(Point2D start, int radius, Color stroke_color, Color fill_color, int thickness) {
    this->start = start;
    this->radius = radius;
    this->stroke_color = stroke_color;
    this->fill_color = fill_color;
    this->thickness = thickness;
    this->fill = true;
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
        if (fill) {
            fill_line(canvas, x0 - y, x0 + y, y0 + x, fill_color);
            fill_line(canvas, x0 - x, x0 + x, y0 + y, fill_color);
            fill_line(canvas, x0 - y, x0 + y, y0 - x, fill_color);
            fill_line(canvas, x0 - x, x0 + x, y0 - y, fill_color);
        }
        
        canvas.draw_pixel(x0 + x, y0 + y, stroke_color);
        canvas.draw_pixel(x0 + y, y0 + x, stroke_color);
        canvas.draw_pixel(x0 - y, y0 + x, stroke_color);
        canvas.draw_pixel(x0 - x, y0 + y, stroke_color);
        canvas.draw_pixel(x0 - x, y0 - y, stroke_color);
        canvas.draw_pixel(x0 - y, y0 - x, stroke_color);
        canvas.draw_pixel(x0 + y, y0 - x, stroke_color);
        canvas.draw_pixel(x0 + x, y0 - y, stroke_color);

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
    return this->stroke_color;
}

void Circle::set_color(Color color) {
    this->stroke_color = color;
}

void Circle::fill_line(Canvas& canvas,int x1, int x2, int y, Color color) {
    for (int i = x1; i < x2; i++) {
        canvas.draw_pixel(i,y,color);
    }
}