#include <conio.h>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
//bring snake class
#include "Snake.h"

using namespace std;

Snake::Snake() {
	position.Set(1, 1);
	positions[0] = Point(position);
}

//updates snake's position
void Snake::Update(float dt) {
	Keyboard();
	timer += dt;
	if (timer >= movePerSec) {
		timer = 0;
		position.x += direction.x;
		position.y += direction.y;
		for (int i = length; i > 0; i--) {
			positions[i] = positions[i - 1];
		}
		positions[0] = Point(position);
		if (length < (sizeof(positions) / sizeof(Point)) - 1) {
			length += 1;
		}
	}
}

//receives input from keyboard
void Snake::Keyboard() {
	if (_kbhit()) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();

			if (direction.x == 0 && direction.y == 1 && key == 72) {
				return;
			}
			else if (direction.x == 0 && direction.y == -1 && key == 80) {
				return;
			}
			else if (direction.x == 1 && direction.y == 0 && key == 75) {
				return;
			}
			else if (direction.x == -1 && direction.y == 0 && key == 77) {
				return;
			}

			switch (key) {
			case 72:
				direction.Set(0, -1);
				break;
			case 80:
				direction.Set(0, 1);
				break;
			case 75:
				direction.Set(-1, 0);
				break;
			case 77:
				direction.Set(1, 0);
				break;
			}
		}
	}
}
