#pragma once
#include "Text.h"
#include "ImageButton.h"
#include <vector>
#include "configMenu_properties.h"
#include "UsernameMenu.h"
#include "MainMenu.h"
#include "ConfigData.h"

class ConfigMenu
{
private:
	Text* text;
	std::vector<ImageButton*> myColorButtons;
	std::vector<ImageButton* > soundsButtons;
	ImageButton* usernameBtn;
	ImageButton* editUsernameBtn;
	ImageButton* backButton;
	ImageButton* saveButton;
	ImageButton* clearButton;

public:	
	ConfigData* oldData;
	ConfigData* newData;
	


public:
	ConfigMenu();
	~ConfigMenu();

	void show(SDL_Surface* screen);
	
	void setUsername(std::string user);
	std::string getUsername();
	std::string getColor();
	std::string getEnableSounds();
	int getColorButtonPressedIndex();
	int getSoundsButtonPressedIndex();

	int manageMouseDown(SDL_Surface* screen, int mouseX, int mouseY);


private:
	void showEdit(SDL_Surface* screen);

	void showColors(SDL_Surface* screen);
	void showEnableSounds(SDL_Surface* screen);
	void showUserNameButton(SDL_Surface* screen);
	void showEditUsernameButton(SDL_Surface* screen);
	void showBackButton(SDL_Surface* screen);
	void showSaveButton(SDL_Surface* screen);
	void showClearButton(SDL_Surface* screen);

	void fillBackground(SDL_Surface* screen);
	
	bool isColorsArea(int x, int y);
	bool isSoundsArea(int x, int y);

	void colorButtonPressedUnpressed(SDL_Surface* screen, int index);
	void soundsButtonPressedUnpressed(SDL_Surface* screen, int index);
	void drawRectangle(SDL_Surface* screen, int x, int y, int w, int h, bool pressed);
	void drawLine(SDL_Surface* screen, int x1, int y1, int x2, int y2, Uint32 color);

};

