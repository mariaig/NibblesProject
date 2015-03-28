#include "Text.h"


Text::Text(std::string font, int size)
{
	this->font = TTF_OpenFont((this->fontsPath + font + this->fontsExtension).c_str(), size);
	this->color = {0,0,0};
	this->location = {0,0,0,0};
	this->size = size;
}


Text::~Text()
{
	delete font;
}


void Text::show(SDL_Surface* screen,std::string text)
{

	SDL_Surface* message = TTF_RenderText_Solid(this->font, text.c_str(), this->color);
	SDL_BlitSurface(message, NULL, screen, &(this->location));
	SDL_Flip(screen);
	SDL_FreeSurface(screen);
	
}

void Text::setTextColor(int R, int G, int B)
{
	this->color = { R, G, B };
}

void Text::setTextLocation(int x, int y)
{
	this->location = { x, y, 0, 0 };
}


int Text::getTextSize()
{
	return size;
}

TTF_Font* Text::getTextFont()
{
	return font;
}

SDL_Color Text::getTextColor()
{
	return color;
}

SDL_Rect Text::getTextLocation()
{
	return location;
}

