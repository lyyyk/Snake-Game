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
	system("mode con cols=120lines=25");//�ܼ� ũ�� ����
	ScreenManager manager;
	manager.Init();
	//�ʱ�ȭ���� ���⼭
	clock_t prev = clock();
	while (1)
	{
		//������ ��Ÿ ����
		clock_t now = clock();
		int deltaMs = now - prev;
		prev = now;
		float delta = deltaMs / 1000.0;
		//

		//�Ʒ��� ���� ���� ����
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