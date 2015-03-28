#pragma once

#include "Text.h"
#include "TextInput.h"
#include "ConfigMenu.h"
#include "usernameMenu_properties.h"

class UsernameMenu
{
private:
	Text* text;
	Text* textInput;
	std::string oldUsername;

public:
	TextInput* ti;

public:
	UsernameMenu();
	~UsernameMenu();
	
	//used when you introduce for the first time the username
	void show(SDL_Surface* screen);
	//used when you just want to edit your username
	void showEditMenu(SDL_Surface* screen);

	//used when you already have an username and you just want to edit it
	//when you showEdit.. you show your old username and the new one
	void setOldUsername(std::string oldUsername);

private:
	void fillBackground(SDL_Surface* screen);
	void showUsername(SDL_Surface* screen);
};