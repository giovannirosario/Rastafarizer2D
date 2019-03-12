#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Canvas.h"
#include "Point2D.h"
#include "Color.h"
#include "Object.h"

class Circle : public Object {
    private:
        Point2D start;
        int radius;
        Color fill_color;
        Color stroke_color;
        int thickness;
        bool fill;
        void fill_line(Canvas& canvas,int x1, int x2, int y, Color color);
        
    public:
        Circle();
        Circle(Point2D start, int radius, Color stroke_color, int thickness = 1);
        Circle(Point2D start, int radius, Color stroke_color, Color fill_color, int thickness = 1);
        ~Circle();
        void draw_shape(Canvas& canvas);
        Color get_color();
        void set_color(Color color);
};

#endif