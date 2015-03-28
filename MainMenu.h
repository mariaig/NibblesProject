#pragma once

#include <SDL.h>
#include "ConfigMenu.h"
#include "mainMenu_properties.h"
#include "ImageButton.h"


class MainMenu
{
private:
	std::vector<ImageButton*> myButtons;
//	bool exit;
	std::string username;
	std::string color;
	std::string enableSounds;

public:
	MainMenu();
	~MainMenu();
	void show(SDL_Surface* screen);

	int manageMouseDown(SDL_Surface* screen, int mouseX, int mouseY);


private:
	void showButtons(SDL_Surface* screen);
	
	//void manageMouseEvents(SDL_Surface* screen, SDL_Event& event);
	
	void fillBackground(SDL_Surface* screen);

};

