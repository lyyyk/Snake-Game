#pragma once
#include "Point.h"
#include "Screen.h"
#ifndef __SNAKE_H__
#define __SNAKE_H__

class Snake {
private:
    void Keyboard();
    float timer = 0;
    Point direction;
    Point position;
public:
    Snake();
    float movePerSec = 0.2;
    void Update(float dt);
    Point positions[300];
    int length = 1;
    int nodeLength = 1;
 };

#endif