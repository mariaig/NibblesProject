#include "WinLoseMenu.h"

WinLoseMenu::WinLoseMenu()
{
	this->text = new Text(WLtextFont, WLtextSize);
	this->text->setTextColor(WLtextR, WLtextG, WLtextB);
	this->text->setTextLocation(WLtextStartingX, WLtextStartingY);
}


void WinLoseMenu::showWin(SDL_Surface* screen, std::string username)
{
	this->fillBackground(screen);
	if (username != "")
	{
		this->text->show(screen, username + ", you're the winner!!!!!!");
	}
	else
	{
		this->text->show(screen, username + " You're the winner!!!!!!");
	}
	
}

void WinLoseMenu::showLose(SDL_Surface* screen, std::string username)
{
	this->fillBackground(screen);
	if (username != "")
	{
		this->text->show(screen, username + ", you're a loser!!!!!!");
	}
	else
	{
		this->text->show(screen, username + "You're a loser!!!!!!");
	}
}


void WinLoseMenu::fillBackground(SDL_Surface* screen)
{
	/*--fill background with the background color---*/
	SDL_Rect background;
	background.w = screenWidth;
	background.h = screenHeight;
	background.x = background.y = 0;
	Uint32 colorbg = SDL_MapRGB(screen->format, screenBackgroundR, screenBackgroundG, screenBackgroundB);
	SDL_FillRect(screen, &background, colorbg);


	/*----put an image on that background-----*/
	//SDL_Rect location = { 0, 0, 0, 0 };
	//SDL_Surface* image = IMG_Load("image+path");
	//SDL_BlitSurface(image, NULL, screen, &location);
	//SDL_Flip(screen);
}