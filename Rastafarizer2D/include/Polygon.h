#ifndef _POLYGON_H_
#define _POLYGON_H_

#include "Canvas.h"
#include "Point2D.h"
#include "Color.h"
#include "Object.h"
#include <vector>

class Polygon : public Object {
    private:
        std::vector<Point2D> points;
        Color fill_color;
        Color stroke_color;
        int thickness;
        bool fill;

    public:
        Polygon();
        Polygon(std::vector<Point2D> points, Color stroke_color, int thickness = 1);
        Polygon(std::vector<Point2D> points, Color stroke_color, Color fill_color, int thickness = 1);
        ~Polygon();
        void draw_shape(Canvas& canvas);
};

#endif