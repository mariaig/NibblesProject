#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>


class TextInput
{
private:
	const static int MAXLENGTH = 12;
	const std::string acceptedChars = "0123456789abcdefghijklmnopqrstuvwxyz";
	std::string input;
	bool ctrl;
	bool shift;

public:
	TextInput();
	bool manageKeyDown(SDL_Event event);
	bool manageKeyUp(SDL_Event event);
	void setInput(std::string input);
	std::string getInput();

private:
	bool isValid(std::string strKey);
	bool isEnter(std::string strKey);
	bool isSpace(std::string strKey);
	bool isBackspace(std::string strKey);
	void checkCtrl(std::string strKey,SDL_Event event);
	void checkShift(std::string strKey, SDL_Event event);
};



