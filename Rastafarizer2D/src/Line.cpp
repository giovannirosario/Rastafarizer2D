#include "Line.h"
#include "Canvas.h"
#include "Point2D.h"
#include "Object.h"
#include <utility>

Line::Line() {}

Line::Line(Point2D start, Point2D end, Color color) {
    this->start = start;
    this->end = end;
    set_color(color);
}

Line::~Line() {}

Color Line::get_color() {
    return this->color;
}

void Line::set_color(Color color) {
    this->color = color;
}

void Line::draw_shape(Canvas& canvas) {
    unsigned int x1 = start.get_x();
    unsigned int y1 = start.get_y();
    unsigned int x2 = end.get_x();
    unsigned int y2 = end.get_y();
    
    if (x1 > x2) {
        std::swap(x1,x2);
        std::swap(y1,y2);
    }

    float delta_x = x2 - x1;
    float delta_y = y2 - y1;
    float p_k = 2 * (delta_y - delta_x);

    unsigned int x = x1;
    unsigned int y = y1;
    
    canvas.draw_pixel(x,y,color);

    for(x = x + 1; x < x2; x++) {
        if (p_k < 0) {
            p_k += 2 * delta_y;
        }
            
        else {
            y++;
            p_k += 2 * delta_y - 2 * delta_x;
        }
        canvas.draw_pixel(x,y,color);
    }
}