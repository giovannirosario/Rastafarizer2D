#include "CircleArc.h"
#include "Point2D.h"
#include "Color.h"
#include "Canvas.h"
#include <math.h>

#define PI 3.14159265

CircleArc::CircleArc(){}
CircleArc::CircleArc(Point2D center, Point2D start, double angle, Color stroke_color, int thickness) {
    this->center = center;
    this->start = start;
    this->angle = angle;
    this->stroke_color = stroke_color;
    this->thickness = thickness;
    int d_x = start.get_x() - center.get_x();
    int d_y = start.get_y() - center.get_y();
    this->start_angle = atan(d_y/d_x) * 180.0 / PI;
    this->end_angle = start_angle + angle;
    this->radius = sqrt(d_x * d_x + d_y * d_y);
}

CircleArc::~CircleArc(){}

void CircleArc::draw_shape(Canvas& canvas) {
    int x0 = start.get_x();
    int y0 = start.get_y();
    int x = radius - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y) {
        draw_pixel(x0 + x, y0 + y, stroke_color, canvas);
        draw_pixel(x0 + y, y0 + x, stroke_color, canvas);
        draw_pixel(x0 - y, y0 + x, stroke_color, canvas);
        draw_pixel(x0 - x, y0 + y, stroke_color, canvas);
        draw_pixel(x0 - x, y0 - y, stroke_color, canvas);
        draw_pixel(x0 - y, y0 - x, stroke_color, canvas);
        draw_pixel(x0 + y, y0 - x, stroke_color, canvas);
        draw_pixel(x0 + x, y0 - y, stroke_color, canvas);

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

void CircleArc::draw_pixel(int x, int y, Color color, Canvas& canvas) {
    int d_x = x - center.get_x();
    int d_y = y - center.get_y();

    double angle;

    if (d_x == 0) {
        if (d_y > 0) {
            angle = 90;
        }
        else {
            angle = 180;
        }
    }
    else {
        angle = atan(d_y/d_x) * 180.0 / PI;
    }
    
    if (angle > start_angle && angle < end_angle) {
        canvas.draw_pixel(x,y, color);
    }
}
