#include "ConfigMenu.h"



ConfigMenu::ConfigMenu()
{
	
	this->usernameBtn = NULL;
	this->editUsernameBtn = NULL;
	this->backButton = NULL;
	this->saveButton = NULL;
	this->clearButton = NULL;

	myColorButtons.clear();
	soundsButtons.clear();

	this->text = new Text(textFont, textSize);
	this->text->setTextColor(textR, textG, textB);
	this->text->setTextLocation(textStartingX, textStartingY);

	this->oldData = new ConfigData();
	this->newData = new ConfigData();
	
}

ConfigMenu::~ConfigMenu()
{
	for (unsigned int i = 0; i < nrColorBut; i++)
	{
		delete myColorButtons[i];
	}
	for (unsigned int i = 0; i < soundsButtons.size(); i++)
	{
		delete soundsButtons[i];
	}

	myColorButtons.clear();
	soundsButtons.clear();

	delete text;
	delete usernameBtn;
	delete editUsernameBtn;
	delete backButton;
	delete saveButton;
	delete clearButton;
	
	delete oldData;
	delete newData;
}

void ConfigMenu::show(SDL_Surface* screen)
{
	
	myColorButtons.clear();
	soundsButtons.clear();

	this->fillBackground(screen);

	if (this->newData->username != "" )
	{
		this->showEdit(screen);
		return;
	}
	this->showColors(screen);
	this->showEnableSounds(screen);
	this->showUserNameButton(screen);
	this->showBackButton(screen);
	this->showSaveButton(screen);
	this->showClearButton(screen);


}


void ConfigMenu::showEdit(SDL_Surface* screen)
{
	

	this->fillBackground(screen);
	this->showColors(screen);
	this->showEnableSounds(screen);

	//setlocation
	int textY = textStartingY + spaceBetweenColorTextAndEnableS + yesButtonH + spaceBetweenButtonsH;
	
	this->text->setTextLocation(textStartingX, textY);
	this->text->show(screen, "Username: ");
	//setlocation
	this->text->setTextLocation(endOfTextWidth, textY);
	this->text->show(screen, this->newData->username);
	
	this->showEditUsernameButton(screen);

	this->showBackButton(screen);
	this->showSaveButton(screen);
	this->showClearButton(screen);


}

void ConfigMenu::setUsername(std::string user)
{
	this->oldData->username = user;
}


std::string ConfigMenu::getUsername()
{
	return this->oldData->username;
}

std::string ConfigMenu::getColor()
{
	return this->oldData->color;
}

std::string ConfigMenu::getEnableSounds()
{
	return this->oldData->sounds;
}

int ConfigMenu::getColorButtonPressedIndex()
{
	return this->oldData->colorButtonPressedIndex;
}

int ConfigMenu::getSoundsButtonPressedIndex()
{
	return this->oldData->soundsButtonPressedIndex;
}



/*-------------------------------------SHOW...-----------------------------*/
void ConfigMenu::showColors(SDL_Surface* screen)
{

	//show text for choosing snake color
	this->text->setTextLocation(textStartingX, textStartingY);
	this->text->show(screen, textObj[0]);

	//show color buttons
	SDL_Rect imageLocation ;

	int nextY = textStartingY;

	int i = 0;

	while (i < nrColorBut)
	{
		
		int nextX = endOfTextWidth;
		imageLocation = { nextX, nextY, colorButtonWidth, colorButtonHeight };
		
		
		for (unsigned int j = 0; j < buttonsPerLine; j++)
		{
			if (i == nrColorBut)
			{
				break;
			}
			ImageButton* img = new ImageButton(screen, imageLocation, colorsButPath + colorButtons[i]);
			this->myColorButtons.push_back(img);
			img->show();
			if (newData->colorButtonPressedIndex == i)
			{
				drawRectangle(screen, imageLocation.x, imageLocation.y, imageLocation.w, imageLocation.h, true);
			}
			i++;
			nextX += colorButtonWidth + spaceBetweenButoonsW;
			imageLocation = { nextX, nextY, colorButtonWidth, colorButtonHeight };
			
		}

		nextY += colorButtonHeight + spaceBetweenButtonsH;
	}

}




void ConfigMenu::showEnableSounds(SDL_Surface* screen)
{
	//show "Enable sounds: "
	int textY = textStartingY + spaceBetweenColorTextAndEnableS;
	this->text->setTextLocation(textStartingX,textY);
	this->text->show(screen, textObj[1]);
	
	
	//show buttons yes/no
	
	SDL_Rect imageLocation;
	ImageButton* img;

	imageLocation = { endOfTextWidth, textY, yesButtonW, yesButtonH };
	img = new ImageButton(screen, imageLocation, configMenuButPath + yesSoundsButtonName);
	this->soundsButtons.push_back(img);
	img->show();
	if (newData->soundsButtonPressedIndex == 0)
	{
		drawRectangle(screen, imageLocation.x, imageLocation.y, imageLocation.w, imageLocation.h, true);
	}

	imageLocation = { endOfTextWidth+yesButtonW+spaceBetweenButoonsW, textY, noButtonW, noButtonH };
	img = new ImageButton(screen, imageLocation, configMenuButPath + noSoundsButtonName);
	this->soundsButtons.push_back(img);
	img->show();
	if (newData->soundsButtonPressedIndex == 1)
	{
		drawRectangle(screen, imageLocation.x, imageLocation.y, imageLocation.w, imageLocation.h, true);
	}
}


void ConfigMenu::showUserNameButton(SDL_Surface* screen)
{
	int y = textStartingY + spaceBetweenColorTextAndEnableS + yesButtonH + spaceBetweenButtonsH;
	SDL_Rect imageLocation = { textStartingX, y, usernameButtonW, usernameButtonH };
	this->usernameBtn = new ImageButton(screen, imageLocation, configMenuButPath + usernameButtonName);
	this->usernameBtn->show();
}

void ConfigMenu::showEditUsernameButton(SDL_Surface* screen)
{
	int y = textStartingY + spaceBetweenColorTextAndEnableS + yesButtonH + spaceBetweenButtonsH*2+textSize;
	SDL_Rect imageLocation = { textStartingX, y, editUsernameButtonW, editUsernameButtonH };
	this->editUsernameBtn = new ImageButton(screen, imageLocation, configMenuButPath + editUsernameButtonName);
	this->editUsernameBtn->show();
}

void ConfigMenu::showBackButton(SDL_Surface* screen)
{
	int x = border;
	int y = screenHeight - border - backButtonH;
	SDL_Rect imageLocation = { x, y, backButtonW, backButtonH };
	this->backButton = new ImageButton(screen, imageLocation, configMenuButPath + backButtonName);
	this->backButton->show();
}

void ConfigMenu::showSaveButton(SDL_Surface* screen)
{
	int x = screenWidth-border-saveButtonW;
	int y = screenHeight - border - saveButtonH;
	SDL_Rect imageLocation = { x, y, backButtonW, backButtonH };
	this->saveButton = new ImageButton(screen, imageLocation, configMenuButPath + saveButtonName);
	this->saveButton->show();
}

void ConfigMenu::showClearButton(SDL_Surface* screen)
{
	int x = screenWidth - border - clearButtonW;
	int y = screenHeight - border - clearButtonH-spaceBetweenButtonsH-saveButtonH;
	SDL_Rect imageLocation = { x, y, backButtonW, backButtonH };
	this->clearButton = new ImageButton(screen, imageLocation, configMenuButPath + clearButtonName);
	this->clearButton->show();
}
/*---------------------------------------FILL------------------------------------------------*/
void ConfigMenu::fillBackground(SDL_Surface* screen)
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


/*---------------------------------------MOUSE EVENTS----------------------------------------*/

int ConfigMenu::manageMouseDown(SDL_Surface* screen, int mouseX, int mouseY)
{
	if (this->isColorsArea(mouseX, mouseY))
	{
		for (unsigned i = 0; i < nrColorBut; i++)
		{
			if (this->myColorButtons[i]->isPressed(mouseX, mouseY))
			{
				// if it's presed draw a rectangle around 
				colorButtonPressedUnpressed(screen, i);
				return 0;
				
			}
		}
	}
	else if (this->isSoundsArea(mouseX, mouseY))
	{
		for (unsigned i = 0; i < soundsButtons.size(); i++)
		{
			if (this->soundsButtons[i]->isPressed(mouseX, mouseY))
			{
				// if it's presed draw a rectangle around 
				soundsButtonPressedUnpressed(screen, i);
				return 0;
			}
		}
	}
	else if (this->usernameBtn!=NULL && this->usernameBtn->isPressed(mouseX, mouseY))
	{
		return 1;
	}
	else if (this->editUsernameBtn != NULL && this->editUsernameBtn->isPressed(mouseX, mouseY))
	{
		return 2;
	}
	else if (this->backButton != NULL && this->backButton->isPressed(mouseX, mouseY))
	{
		newData->clearData();
		
		return 3;
	}
	else if (this->saveButton != NULL && this->saveButton->isPressed(mouseX, mouseY))
	{
		oldData->setData(newData->username, newData->color, newData->sounds, newData->colorButtonPressedIndex, newData->soundsButtonPressedIndex);
		
		this->show(screen);
		return 4;
	}
	else if (this->clearButton != NULL && this->clearButton->isPressed(mouseX, mouseY))
	{
		newData->clearData();
		oldData->clearData();

		this->show(screen);
		return 5;
	}
	return 0;
}


void ConfigMenu::colorButtonPressedUnpressed(SDL_Surface* screen, int index)
{ 
	SDL_Rect location;
	if (newData->colorButtonPressedIndex != -1)
	{
		if (newData->colorButtonPressedIndex == index)
		{
			//if we press the second time thesame color => unpressed button
			location = myColorButtons[newData->colorButtonPressedIndex]->getImageLocation();
			newData->colorButtonPressedIndex = -1;
			newData->color = "";
			drawRectangle(screen, location.x, location.y, location.w, location.h, false);
		}
		else
		{
			//if we press another button while another one is pressed, the onethat was pressed become unpressed

			//the one pressed before is at the index colorButtonPressedIndex
			location = myColorButtons[newData->colorButtonPressedIndex]->getImageLocation();
			drawRectangle(screen, location.x, location.y, location.w, location.h, false);
			

			//remember the last pressed button
			newData->colorButtonPressedIndex = index;
			newData->color = myColorButtons[index]->getButtonName();

			//draw a rectangle around the pressed button
			location = myColorButtons[index]->getImageLocation();
			drawRectangle(screen, location.x, location.y, location.w, location.h, true);


		}
	}
	else
	{  // pressed a button for the first time
		newData->colorButtonPressedIndex = index;
		newData->color = myColorButtons[index]->getButtonName();
		location = myColorButtons[index]->getImageLocation();
		drawRectangle(screen, location.x, location.y, location.w, location.h, true);
	}

}

void ConfigMenu::soundsButtonPressedUnpressed(SDL_Surface* screen, int index)
{
	SDL_Rect location;
	if (newData->soundsButtonPressedIndex != -1)
	{
		if (newData->soundsButtonPressedIndex == index)
		{
			//if we press the second time thesame color => unpressed button
			location = soundsButtons[newData->soundsButtonPressedIndex]->getImageLocation();
			newData->soundsButtonPressedIndex = -1;
			newData->sounds = "";
			drawRectangle(screen, location.x, location.y, location.w, location.h, false);
		}
		else
		{
			//if we press another button while another one is pressed, the one that was pressed became unpressed

			//the one pressed before is at the index soundsButtonPressedIndex
			location = soundsButtons[newData->soundsButtonPressedIndex]->getImageLocation();
			drawRectangle(screen, location.x, location.y, location.w, location.h, false);

			//remember the last pressed button
			newData->soundsButtonPressedIndex = index;
			newData->sounds = soundsButtons[index]->getButtonName();

			//draw a rectangle around the pressed button
			location = soundsButtons[index]->getImageLocation();
			drawRectangle(screen, location.x, location.y, location.w, location.h, true);

		}
	}
	else
	{
		// pressed a button for the first time
		newData->soundsButtonPressedIndex = index;
		newData->sounds = soundsButtons[index]->getButtonName();
		location = soundsButtons[index]->getImageLocation();
		drawRectangle(screen, location.x, location.y, location.w, location.h, true);


	}

}


/*-----------------------------------------is...Area-------------------------------------*/
bool ConfigMenu::isColorsArea(int x, int y)
{

	int colorsAreaStartX = endOfTextWidth;
	int colorsAreaLastX = screenWidth - border;
	int colorsAreaStartY = textStartingY;
	int colorsAreaLastY = textStartingY + spaceBetweenColorTextAndEnableS;

	if (x >= colorsAreaStartX && x <= colorsAreaLastX &&
		y >= colorsAreaStartY && y <= colorsAreaLastY)
	{
		return true;
	}
	return false;
}

bool ConfigMenu::isSoundsArea(int x, int y)
{
	int soundsAreaStartingX = endOfTextWidth;
	int soundsAreaLastX = screenWidth - border;
	int soundsAreaStartingY = textStartingY + spaceBetweenColorTextAndEnableS+1;
	int soundsAreaLastY = soundsAreaStartingY + yesButtonH + spaceBetweenButtonsH;

	if (x >= soundsAreaStartingX && x <= soundsAreaLastX &&
		y >= soundsAreaStartingY && y <= soundsAreaLastY)
	{
		return true;
	}
	return false;
}




/*----------------------------DRAW BUTTON PRESSED-UNPRESSED------------------------------------*/

void ConfigMenu::drawRectangle(SDL_Surface* screen,int x, int y, int w, int h,bool pressed)
{
	Uint32 color;
	if (pressed)
	{
		 color = SDL_MapRGB(screen->format, buttonBorderR, buttonBorderG, buttonBorderB);
	}
	else
	{
		color = SDL_MapRGB(screen->format, screenBackgroundR, screenBackgroundG, screenBackgroundB);
	}

	this->drawLine(screen, x, y, x + w, y, color); //------ up
	this->drawLine(screen, x, y + h, x + w, y + h, color); //---down
	this->drawLine(screen, x, y, x, y + h, color); // | left
	this->drawLine(screen, x + w, y, x + w, y + h, color); // | right
}


//auxiliary function which draws a line between dwo points (x1,y1) and (x2,y2)
//with a specific color 
void ConfigMenu::drawLine(SDL_Surface* screen, int x1, int y1, int x2, int y2,Uint32 color)
{


	SDL_Rect lineBg;
	
	for (int i = x1; i <= x2; i++)
	{
		for (int j = y1; j <= y2; j++)
		{
			lineBg = { i, j, buttonBorderWidth, buttonBorderWidth };
			SDL_FillRect(screen, &lineBg, color);
		}
	}

	SDL_Flip(screen);
	SDL_FreeSurface(screen);
}