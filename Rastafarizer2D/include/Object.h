#ifndef _OBJECT_H_
#define _OBJECT_H_
#include "Color.h"
#include "Canvas.h"
#include <iostream>

class Object {
    private: 
        Color color;
    public:
        Object();
        ~Object();
        virtual void draw(Canvas canvas) {};
        Color get_color();
        void set_color(Color color);
}; 

#endif