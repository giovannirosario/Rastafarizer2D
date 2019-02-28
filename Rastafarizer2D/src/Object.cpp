#include "Object.h"
#include "Color.h"

Object::Object() {}

Object::~Object() {} 

Color Object::get_color() {
    return this->color;
}

void Object::set_color(Color color) {
    this->color = color;
}