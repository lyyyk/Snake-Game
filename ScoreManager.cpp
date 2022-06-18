#include "ScoreManager.h"
//updates and calculates the score depending on the time elapsed

void ScoreManager::Update(float dt) {
	timer += dt;
	if (timer >= scorePerSec) {
		AddScore(1);
		timer = 0;
	}
}

void ScoreManager::AddScore(int addit) {
	score += addit;
}
