#ifndef _CANVAS_H_
#define _CANVAS_H_

#include "Color.h"
#include "Point2D.h"

class Canvas {
    private:
        Color * canvas;
        unsigned int width;
        unsigned int height;

    public:
        Canvas();
        Canvas(unsigned int width, unsigned int height);
        ~Canvas();
        void set_size(unsigned int width, unsigned int height);
        unsigned int get_width();
        unsigned int get_height();
        Color * get_canvas();
        void draw_background(Color bg_color);
        void draw_pixel(int x, int y, Color color);
};

#endif