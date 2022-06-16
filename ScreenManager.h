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
	// Note: �ʱ�ȭ
	void Init();
	// Note: ������ ����
	int Update(float delta);
	int LevelUpUpdate(float delta);
	// Note: ������
	void Render();
	void LevelUpRender();
	// Note: ����
	void Release();
	void GameOver();
};
#endif