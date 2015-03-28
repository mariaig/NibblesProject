#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Text{
private:
	const std::string fontsExtension = ".ttf";
	const std::string fontsPath = "Usage/sdl_fonts/";
	TTF_Font* font;
	SDL_Color color;
	SDL_Rect location;
	int size;

public:
	Text(std::string font, int size);
	~Text();
	void show(SDL_Surface* screen, std::string text);


	
	void setTextColor(int R, int G, int B);
	void setTextLocation(int x, int y);

	TTF_Font* getTextFont();
	SDL_Color getTextColor();
	SDL_Rect getTextLocation();
	int getTextSize();
};

