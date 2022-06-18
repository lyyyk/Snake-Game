#include "FoodManager.h"
#include <cstdlib>

//determines the position of the food
void FoodManager::UpdatePos() {
	int x = leftTop.x + (rand() % (rightBottom.x - leftTop.x));
	int y = leftTop.y + (rand() % (rightBottom.y - leftTop.y));
	foodPosition.Set(x, y);
}

//member function that sets and updates the position of the food
FoodManager::FoodManager() {
	leftTop = Point (1, 1);
	rightBottom = Point(99, 24);
	UpdatePos();
}
