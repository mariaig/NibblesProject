#pragma once

#include<iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "screen_properties.h"

class ImageButton{

private:
	SDL_Rect imageLocation;
	int margins;
	Uint32 lineColor;
	SDL_Surface* image;
	SDL_Surface* screen;
	std::string buttonName;


public:
	//used for the image button
	ImageButton(SDL_Surface* screen, SDL_Rect coords, std::string buttonName);
	~ImageButton();
	//show the image button
	void show();

	void setLineColor(int R, int G, int B);
	SDL_Rect getImageLocation();


	bool isPressed(int x, int y);
	std::string getButtonName();

private:
	//auxiliary function which draws a line between dwo points (x1,y1) and (x2,y2)
	//with a specific color 
	void DrawLine(int x1, int y1, int x2, int y2, Uint32 color);

};


