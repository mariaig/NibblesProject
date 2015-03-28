#include "UsernameMenu.h"


UsernameMenu::UsernameMenu()
{
	this->oldUsername = "";

	this->text = new Text(utextFont, utextSize);
	this->text->setTextColor(utextR, utextG, utextB);
	this->text->setTextLocation(utextStartingX, utextStartingY);

	this->textInput = new Text(utextFont, utextSize);
	this->textInput->setTextColor(utextInputR, utextInputG, utextInputB);
	this->textInput->setTextLocation(uendOfTextWidth, utextStartingY);
	
	this->ti = new TextInput();
}

UsernameMenu::~UsernameMenu()
{
	delete text;
	delete textInput;
	delete ti;
}

void UsernameMenu::show(SDL_Surface* screen)
{
	this->fillBackground(screen);


	if (oldUsername != "")
	{
		this->ti->setInput("");
		this->showEditMenu(screen);
		return;
	}
	
	this->text->show(screen, "Username: ");
	this->textInput->show(screen, ti->getInput());
	
	
}

void UsernameMenu::showEditMenu(SDL_Surface* screen)
{
	this->fillBackground(screen);
	this->text->setTextLocation(utextStartingX, utextStartingY);
	this->text->show(screen, "Old username: ");
	this->text->setTextLocation(uendOfTextWidth, utextStartingY);
	this->text->show(screen, this->oldUsername);
	
	int textY = utextStartingY + utextSize + spaceBetweenTextH;
	this->text->setTextLocation(utextStartingX, textY);
	this->text->show(screen, "New username: ");
	this->textInput->setTextLocation(uendOfTextWidth, textY);
	this->textInput->show(screen, ti->getInput());

}



void UsernameMenu::fillBackground(SDL_Surface* screen)
{


	/*--fill background with the background color---*/
	SDL_Rect background;
	background.w = screenWidth;
	background.h = screenHeight;
	background.x = background.y = 0;
	Uint32 colorbg = SDL_MapRGB(screen->format, screenBackgroundR, screenBackgroundG, screenBackgroundB);
	SDL_FillRect(screen, &background, colorbg);

	/*----put an image on that background-----*/
	SDL_Rect location = { 0, 0, 0, 0 };
	SDL_Surface* image = IMG_Load((buttonsPath + usernameMenuButPath + UMbackgroundImg).c_str());
	SDL_BlitSurface(image, NULL, screen, &location);
	SDL_Flip(screen);
}


void UsernameMenu::setOldUsername(std::string oldUsername)
{
	this->oldUsername = oldUsername;
}