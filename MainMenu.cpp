#include "MainMenu.h"

MainMenu::MainMenu()
{

}

MainMenu::~MainMenu()
{
	for (unsigned int i = 0; i < myButtons.size(); i++)
	{
		delete myButtons[i];
	}
	myButtons.clear();
}

void MainMenu::show(SDL_Surface* screen)
{
	this->fillBackground(screen);
	this->showButtons(screen);
}

void MainMenu::showButtons(SDL_Surface* screen)
{
	SDL_Rect imagelocation = { startingX, startingY, buttonWidth, buttonHeight };

	int nextY = startingY;
	
	//populate screen with buttons
	for (unsigned i = 0; i < nrButtons; i++)
	{

		ImageButton* but = new ImageButton(screen, imagelocation, mainMenuButPath + imagesName[i]);
		myButtons.push_back(but);
		nextY += buttonHeight + distBetweenButtons;
		imagelocation = { startingX, nextY, buttonWidth, buttonHeight };
		but->show();

	}
}



int MainMenu::manageMouseDown(SDL_Surface* screen, int mouseX, int mouseY)
{
	for (unsigned i = 0; i < nrButtons; i++)
	{
		if (this->myButtons[i]->isPressed(mouseX, mouseY))
		{
			return i;
		}
	}
}



/*---------------------------------------FILL------------------------------------------------*/
void MainMenu::fillBackground(SDL_Surface* screen)
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
	SDL_Surface* image = IMG_Load((buttonsPath + mainMenuButPath+mainMenuBackgroundImg).c_str());
	SDL_BlitSurface(image, NULL, screen, &location);
	SDL_Flip(screen);
}