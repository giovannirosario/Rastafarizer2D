#include "CircleArc.h"
#include "Point2D.h"
#include "Color.h"
#include <math.h>

CircleArc::CircleArc(){}
CircleArc::CircleArc(Point2D center, Point2D start, double angle, Color stroke_color, int thickness = 1){
    this->center = center;
    this->start = start;
    this->angle = angle;
    this->stroke_color = stroke_color;
    this->thickness = thickness;
    int d_x = start.get_x() - center.get_x();
    int d_y = start.get_y() - center.get_y();
    this->angle = sqrt(pow(d_x) + pow(d_y));
}
CircleArc::CircleArc(Point2D center, Point2D start, double angle, Color stroke_color, Color fill_color, int thickness = 1){
    this->center = center;
    this->start = start;
    this->angle = angle;
    this->stroke_color = stroke_color;
    this->fill_color = fill_color;
    this->thickness = thickness;
    int d_x = start.get_x() - center.get_x();
    int d_y = start.get_y() - center.get_y();
    this->angle = sqrt(pow(d_x) + pow(d_y));
}
~CircleArc::CircleArc(){}

void draw_shape(Canvas& canvas) {
}
