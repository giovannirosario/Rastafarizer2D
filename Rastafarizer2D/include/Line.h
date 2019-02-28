#ifndef _LINE_H_
#define _LINE_H_

class Line {
    private:
        Point2D start;
        Point2D end;
        Color color;

    private:
        Line();
        ~Line();
        void draw(Canvas canvas);
};

#endif