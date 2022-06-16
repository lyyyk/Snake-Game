#include "ScreenManager.h"
#include <conio.h>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

#define UP_ARROW 72
#define DOWN_ARROW 80
#define RIGHT_ARROW 77
#define LEFT_ARROW 75
#define SPACE_BAR 32
#define ENTER 13


// Note: 초기화
void ScreenManager::Init()
{
	screen.ScreenInit();
}

// Note: 데이터 갱신
int ScreenManager::Update(float delta)
{
	if (isGameOver) return 0;

	snake.Update(delta);
	if (snake.positions[0].Compare(foodManager.foodPosition)) {
		snake.nodeLength += 1;
		foodManager.UpdatePos();
		scoreManager.AddScore(10);
	}

	bool gameOver = false;

	if ((snake.positions[0].x <= 0 || snake.positions[0].x >= 100) || (snake.positions[0].y <= 0 || snake.positions[0].y >= 25)) {
		gameOver = true;
	}
	
	for (int i = 1; i < snake.nodeLength; i++) {
		if (snake.positions[0].x == snake.positions[i].x && snake.positions[0].y == snake.positions[i].y) {
			gameOver = true;
		}
	}

	if (gameOver) {
		GameOver();
	}

	scoreManager.Update(delta);
	if (scoreManager.score >= 100 * level) {
		level += 1;
		snake.movePerSec *= 0.9;
		curScene = Scene::LevelUpScene;
	}

	return 0;
}

int ScreenManager::LevelUpUpdate(float delta) {
	levelUpShowTimer += delta;
	if (levelUpShowTimer >= levelUpShowTime) {
		levelUpShowTimer = 0;
		curScene = Scene::GameScene;
	}
	return 0;
}

// Note: 렌더링
void ScreenManager::Render()
{
	screen.ScreenClear();
	//Rendering

	screen.ScreenPrint(foodManager.foodPosition.x, foodManager.foodPosition.y, "@");

	for (int i = 0; i < snake.nodeLength; i++) {
		Point pos = snake.positions[i];
		screen.ScreenPrint(pos.x, pos.y, "*");
	}

	for (int y = 0; y < 25; y++) {
		for (int x = 0; x < 100; x++) {
			if (y == 0 || x == 0 || x == 99 || y == 24) {
				screen.ScreenPrint(x, y, "#");
			}
		}
	}

	for (int y = 0; y < 25; y++) {
		for (int x = 100; x < 120; x++) {
			if (y == 0 || x == 100 || x == 119 || y == 24) {
				screen.ScreenPrint(x, y, "#");
			}
		}
	}
	
	screen.ScreenPrint(105, 5, "Points: ");
	screen.ScreenPrint(113, 5, to_string(scoreManager.score).c_str());
	if (isGameOver) {
		screen.ScreenClear();
		screen.ScreenPrint(25, 8, "++++++  ++++++  +++ +++  ++++++      ++++++  +   +  ++++++  ++++++");
		screen.ScreenPrint(25, 9, "+    +  +    +  +  +  +  +           +    +  +   +  +       +    +");
		screen.ScreenPrint(25, 10, "+       ++++++  +  +  +  ++++++      +    +  +   +  ++++++  ++++++");
		screen.ScreenPrint(25, 11, "+  +++  +    +  +     +  +           +    +  +   +  +       +");
		screen.ScreenPrint(25, 12, "+    +  +    +  +     +  +           +    +   + +   +       +  +");
		screen.ScreenPrint(25, 13, "++++++  +    +  +     +  ++++++      ++++++    +    ++++++  +    +");

		screen.ScreenPrint(25, 15, "Points Earned: ");
		screen.ScreenPrint(40, 15, to_string(scoreManager.score).c_str());
	}

	screen.ScreenFlipping();
}

void ScreenManager::LevelUpRender() {


	screen.ScreenClear();
	screen.ScreenPrint(25, 8, "+       ++++++  +   +  ++++++  +           +    +  ++++++  +");
	screen.ScreenPrint(25, 9, "+       +       +   +  +       +           +    +  +    +  +");
	screen.ScreenPrint(25, 10, "+       ++++++  +   +  ++++++  +           +    +  ++++++  +");
	screen.ScreenPrint(25, 11, "+       +       +   +  +       +           +    +  +       +");
	screen.ScreenPrint(25, 12, "+       +        + +   +       +           +    +  +         ");
	screen.ScreenPrint(25, 13, "++++++  ++++++    +    ++++++  ++++++      ++++++  +       +");

	screen.ScreenPrint(25, 15, "Level: ");
	screen.ScreenPrint(32, 15, to_string(level).c_str());

	screen.ScreenFlipping();
}

// Note: 해제
void ScreenManager::Release()
{
	screen.ScreenRelease();
}

ScreenManager::ScreenManager() {

}

void ScreenManager::GameOver() {
	isGameOver = true;
}