#ifndef _LINE_H_
#define _LINE_H_

#include "Point2D.h"
#include "Color.h"
#include "Canvas.h"
#include "Object.h"

class Line : public Object {
    private:
        Point2D start;
        Point2D end;
        Color color;
        void draw_lineHigh(Canvas& canvas);
        void draw_lineLow(Canvas& canvas);
        
    public:
        Line();
        Line(Point2D start, Point2D end, Color color);
        ~Line();
        void draw_shape(Canvas& canvas);
        Color get_color();
        void set_color(Color color);
};

#endif