#include "Object.h"
#include "Color.h"

Object::Object() {}

void Object::draw(Canvas& canvas) {
    draw_shape(canvas);
}