#include "Color.h"

Color::Color(unsigned char red, unsigned char green, unsigned char blue) {
    this->rgb[0] = red;
    this->rgb[1] = green;
    this->rgb[2] = blue;
}

void Color::set(unsigned char red, unsigned char green, unsigned char blue) {
    this->rgb[0] = red;
    this->rgb[1] = green;
    this->rgb[2] = blue;
}

Color::~Color() {}