#ifndef _CIRCLEARC_H_
#define _CIRCLEARC_H_

class CircleArc : public Object {
    private:
        Point2D center;
        Point2D start;
        Color fill_color;
        Color stroke_color;
        int radius;
        int thickness;
        bool fill;
        double angle;

    public:
        CircleArc();
        CircleArc(Point2D center, Point2D start, double angle, Color stroke_color, int thickness = 1);
        CircleArc(Point2D center, Point2D start, double angle, Color stroke_color, Color fill_color, int thickness = 1);
        void draw_shape(Canvas& canvas);
        ~CircleArc();
};

#endif