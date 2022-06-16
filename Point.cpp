#include <iostream>
#include <Windows.h>
#include "Point.h"

Point::Point(int x, int y)
	:x(x), y(y) {

}

void Point::Set(int x, int y) {
	this->x = x;
	this->y = y;
}

Point::Point(Point& copy) {
	this->x = copy.x;
	this->y = copy.y;
}

bool Point::Compare(Point p) {
	return x == p.x && y == p.y;
}