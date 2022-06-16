#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include "Screen.h"
#include <iostream>
#include "ScreenManager.h"

using namespace std;

#define ENTER 10

int main(void)
{
	srand(time(NULL));
	system("mode con cols=120lines=25");//콘솔 크기 조정
	ScreenManager manager;
	manager.Init();
	//초기화면은 여기서
	clock_t prev = clock();
	while (1)
	{
		//프레임 델타 계산식
		clock_t now = clock();
		int deltaMs = now - prev;
		prev = now;
		float delta = deltaMs / 1000.0;
		//

		//아랫줄 부터 구현 시작
		if (manager.curScene == ScreenManager::Scene::GameScene) {
			manager.Update(delta);
			manager.Render();
		}
		else if (manager.curScene == ScreenManager::Scene::LevelUpScene) {
			manager.LevelUpUpdate(delta);
			manager.LevelUpRender();
		}
	}
	manager.Release();
	return 0;
}