#ifndef __SCREENMANAGER__
#define __SCREENMANAGER__
#include "Screen.h"
#include "Snake.h"
#include "FoodManager.h"
#include "ScoreManager.h"

class ScreenManager
{
private:
	Screen screen;
	Snake snake;
	FoodManager foodManager;
	ScoreManager scoreManager;
	bool isGameOver = false;
	float levelUpShowTime = 3;
	float levelUpShowTimer = 0;
	int level = 1;

	//SaveLoadFile file;
	//char* timeStr;
	//char* loadFileInfo[FILE_NUM];
	ScreenManager(const ScreenManager&) {}
	ScreenManager& operator=(const ScreenManager&) {}
public:
	enum Scene {
		GameScene,
		LevelUpScene
	};
	Scene curScene = Scene::GameScene;
	ScreenManager();
	// Note: 초기화
	void Init();
	// Note: 데이터 갱신
	int Update(float delta);
	int LevelUpUpdate(float delta);
	// Note: 렌더링
	void Render();
	void LevelUpRender();
	// Note: 해제
	void Release();
	void GameOver();
};
#endif