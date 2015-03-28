#pragma once
#include "winLoseMenu_properties.h"
#include "Text.h"
#include <string>

class WinLoseMenu
{
private:
	Text* text;
public:
	WinLoseMenu();
	void showWin(SDL_Surface* screen,std::string username);
	void showLose(SDL_Surface* screen, std::string username);

private:
	void fillBackground(SDL_Surface* screen);
};