#ifndef _FLOODFILL_H_
#define _FLOODFILL_H_

#include "Canvas.h"
#include "Color.h"

class FloodFill {
    private:
        Canvas * canvas;
        Color old_color;
        Color new_color;
        int x;
        int y;
        void fill(int x, int y);
    
    public:
        FloodFill(Canvas& canvas, int x, int y, Color new_color);
        ~FloodFill();
};
 
#endif