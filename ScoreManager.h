#include "Snake.h"

class ScoreManager {
public:
	int score = 0;
	void Update(float dt);
	void AddScore(int addit);
private:
	//others can't change timer or score increased per second
	float timer = 0;
	float scorePerSec = 1;
	Snake snake;
};
