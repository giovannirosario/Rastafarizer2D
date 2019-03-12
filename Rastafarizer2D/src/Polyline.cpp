#include "Polyline.h"
#include "Canvas.h"
#include "Point2D.h"
#include "Color.h"
#include "Line.h"
#include "ScanlineFill.h"

Polyline::Polyline() {}

Polyline::Polyline(std::vector<Point2D> points, Color stroke_color, int thickness) {
    this->stroke_color = stroke_color;
    this->points = points;
    this->thickness = thickness;
}

Polyline::~Polyline() {}

void Polyline::draw_shape(Canvas& canvas) {
    for(unsigned int i = 0; i < points.size()-1; i++){
        Line temp_line = Line(points[i], points[i+1], this->stroke_color, thickness);
        temp_line.draw_shape(canvas);
    }
}