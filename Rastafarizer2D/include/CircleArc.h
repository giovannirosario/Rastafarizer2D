#ifndef _CIRCLEARC_H_
#define _CIRCLEARC_H_

#include "Point2D.h"
#include "Color.h"
#include "Canvas.h"
#include "Object.h"

class CircleArc : public Object {
    private:
        Point2D center;
        Point2D start;
        Color fill_color;
        Color stroke_color;
        int radius;
        int thickness;
        int angle;
        int start_angle;
        int end_angle;

        bool isAngleBetween(int angle);
        void draw_pixel(int x, int y, Color color, Canvas& canvas);

    public:
        CircleArc();
        CircleArc(Point2D center, Point2D start, int angle, Color stroke_color, int thickness = 1);
        void draw_shape(Canvas& canvas);
        ~CircleArc();
};

#endif