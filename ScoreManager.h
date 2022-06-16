#include "Snake.h"

class ScoreManager {
public:
	int score = 0;
	void Update(float dt);
	void AddScore(int addit);
private:
	float timer = 0;
	float scorePerSec = 1;
	Snake snake;
};