#pragma once

class Screen
{
private:
	Screen& operator=(const Screen&) {}
public:
	Screen() {}
	Screen(const Screen&) {}
	void ScreenInit();
	void ScreenFlipping();
	void ScreenClear();
	void ScreenRelease();
	void ScreenPrint(int x, int y, const char* string);
	void SetColor(unsigned short color);
};