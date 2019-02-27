#ifndef _CANVAS_H_
#define _CANVAS_H_

class Canvas {
    private:
        Color * canvas;
        unsigned int width;
        unsigned int height;

    public:
        Canvas();
        Canvas(unsigned int width, unsigned int height);
        ~Canvas();
        void set_width(unsigned int width);
        void set_height(unsigned int height);
        unsigned int get_width();
        unsigned int get_height();
        Color * get_canvas();
        void draw_background(Color bg_color);
        void draw_line(Point2D start, Point2D end, Color color);
}

