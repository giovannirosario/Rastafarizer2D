#include "Point2D.h"

Point2D::Point2D (unsigned int x, unsigned int y) {
	this->x = x;
	this->y = y;
}

void Point2D::set (unsigned int x, unsigned int y) {
	this->x = x;
	this->y = y;
}

Point2D::~Point2D () {}

unsigned int Point2D::get_x() {
	return this->x;
}

unsigned int Point2D::get_y() {
	return this->y;
}

bool Point2D::operator==(const Point2D &Point2D) {
	bool result = (this->x == Point2D.x) && (this->y == Point2D.y);
	return result;
}


