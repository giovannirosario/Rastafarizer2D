#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Object.h"
#include "Color.h"
#include "Canvas.h"
#include <iostream>

class Object {
    public:
        Object();
        virtual ~Object() {};
        void draw(Canvas& canvas);
        virtual void draw_shape(Canvas& canvas) = 0;
}; 

#endif