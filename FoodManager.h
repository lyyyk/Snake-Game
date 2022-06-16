#include "Point.h"

class FoodManager {
public:
	Point foodPosition;
	void UpdatePos();
	Point leftTop;
	Point rightBottom;
	FoodManager();
};