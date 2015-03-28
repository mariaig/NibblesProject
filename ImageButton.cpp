#include "ImageButton.h"


//used for the image button
ImageButton::ImageButton(SDL_Surface* screen,SDL_Rect coords,std::string buttonName)
{
	imageLocation = coords;
	this->lineColor = SDL_MapRGB(screen->format, 0, 0, 0);
	this->screen = screen;
	this->margins = 10;
	this->buttonName = buttonName;
}

ImageButton::~ImageButton()
{
	delete image;
	delete screen;
}


void ImageButton::show()
{
	SDL_Surface* image = IMG_Load((buttonsPath+this->buttonName).c_str());
	SDL_BlitSurface(image, NULL, screen, &this->imageLocation);
	SDL_Flip(screen);
}


bool ImageButton::isPressed(int x, int y)
{
	if (x >= (this->imageLocation).x &&
		x <= (this->imageLocation).x + (this->imageLocation).w &&
		y >= (this->imageLocation).y &&
		y <= (this->imageLocation).y + (this->imageLocation).h)
		return true;
	return false;
}

std::string ImageButton::getButtonName()
{
	size_t poz = this->buttonName.find("/");
	this->buttonName = this->buttonName.substr(poz + 1);
	poz = this->buttonName.find(".");
	this->buttonName = this->buttonName.substr(0,poz);
	return this->buttonName;
}

SDL_Rect ImageButton::getImageLocation()
{
	return this->imageLocation;
}