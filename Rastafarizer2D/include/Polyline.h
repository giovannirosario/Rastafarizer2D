#ifndef _POLYLINE_H
#define _POLYLINE_H

#include "Canvas.h"
#include "Point2D.h"
#include "Color.h"
#include "Object.h"
#include <vector>

class Polyline : public Object {
    private:
        std::vector<Point2D> points;
        Color stroke_color;
        int thickness;

    public:
        Polyline();
        Polyline(std::vector<Point2D> points, Color stroke_color, int thickness = 1);
        ~Polyline();
        void draw_shape(Canvas& canvas);
};

#endif