#include "Line.h"
#include "Canvas.h"
#include "Point2D.h"
#include "Object.h"
#include <stdlib.h> 
#include <utility>

Line::Line() {}

Line::Line(Point2D start, Point2D end, Color color, int thickness) {
    this->start = start;
    this->end = end;
    this->color = color;
    this->thickness = thickness;
}

Line::~Line() {}

Color Line::get_color() {
    return this->color;
}

void Line::set_color(Color color) {
    this->color = color;
}

void Line::draw_shape(Canvas& canvas) {
    int x1 = start.get_x();
    int y1 = start.get_y();
    int x2 = end.get_x();
    int y2 = end.get_y();
    
    if (std::abs(y2 - y1) < std::abs(x2 - x1)){
        if (x1 > x2)
            draw_lineLow(canvas, x2, y2, x1, y1);
        else 
            draw_lineLow(canvas, x1, y1, x2, y2);
    } else {
        if (y1 > y2)
            draw_lineHigh(canvas, x2, y2, x1, y1);
        else
            draw_lineHigh(canvas, x1, y1, x2, y2);
    }
}


void Line::draw_lineHigh(Canvas& canvas, int x1, int y1, int x2, int y2) {
    float delta_x = x2 - x1;
    float delta_y = y2 - y1;

    unsigned int x = x1;
    unsigned int y = y1;
    
    int dir = 1;

    if (delta_x < 0) {
        dir = -1;
        delta_x = -delta_x;
    }

    float p_k = 2 * (delta_x - delta_y);
    

    canvas.draw_pixel(x,y,color);

    for(int i = 1; i < thickness; i++) {
        canvas.draw_pixel(x+i,y,color);
        canvas.draw_pixel(x-i,y,color);
    }

    for(y = y + 1; y <= y2; y++) {
        if (p_k < 0) {
            p_k += 2 * delta_x;
        }
            
        else {
            x = x + dir;
            p_k += 2 * delta_x - 2 * delta_y;
        }
        canvas.draw_pixel(x,y,color);

        for(int i = 1; i < thickness; i++) {
            canvas.draw_pixel(x+i,y,color);
            canvas.draw_pixel(x-i,y,color);
        }
    }
}

void Line::draw_lineLow(Canvas& canvas, int x1, int y1, int x2, int y2) {
    float delta_x = x2 - x1;
    float delta_y = y2 - y1;
    unsigned int x = x1;
    unsigned int y = y1;
    
    int dir = 1;

    if (delta_y < 0) {
        dir = -1;
        delta_y = -delta_y;
    }

    float p_k = 2 * (delta_y - delta_x);

    canvas.draw_pixel(x,y,color);
    for(int i = 1; i < thickness; i++) {
        canvas.draw_pixel(x,y-i,color);
        canvas.draw_pixel(x,y+i,color);
    }

    for(x = x + 1; x <= x2; x++) {
        if (p_k < 0) {
            p_k += 2 * delta_y;
        }
            
        else {
            y = y + dir;
            p_k += 2 * delta_y - 2 * delta_x;
        }
        canvas.draw_pixel(x,y,color);
        for(int i = 1; i < thickness; i++) {
            canvas.draw_pixel(x,y-i,color);
            canvas.draw_pixel(x,y+i,color);
        }
    }
}