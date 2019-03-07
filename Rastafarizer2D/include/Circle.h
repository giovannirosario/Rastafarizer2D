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
        Color color;
        
    public:
        Circle();
        Circle(Point2D start, int radius, Color color);
        ~Circle();
        void draw_shape(Canvas& canvas);
        Color get_color();
        void set_color(Color color);
};

#endif