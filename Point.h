#pragma once
#include <iostream>
#include <Windows.h>

class Point {
public:
	int x;
	int y;
	void Set(int x, int y);
	Point(int x = 0, int y = 0);
	Point(Point& copy);
	bool Compare(Point p);
};
