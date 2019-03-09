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
        int thickness;
        void draw_lineHigh(Canvas& canvas, int x1, int y1, int x2, int y2);
        void draw_lineLow(Canvas& canvas, int x1, int y1, int x2, int y2);
        
    public:
        Line();
        Line(Point2D start, Point2D end, Color color, int thickness = 1);
        ~Line();
        void draw_shape(Canvas& canvas);
        Color get_color();
        void set_color(Color color);
};

#endif