#include "ColorPicker.h"
#include <iostream>

ColorPicker::ColorPicker(SDL_Surface *screen)
{
	
	this->colors["red"] = SDL_MapRGB(screen->format, 0xff, 0x00, 0x00);
	this->colors["blue"] = SDL_MapRGB(screen->format, 0x00, 0x00, 0xff);
	this->colors["lime"] = SDL_MapRGB(screen->format, 0x00, 0xff, 0x00);
	this->colors["yellow"] = SDL_MapRGB(screen->format, 0xff, 0xff, 0x00);
	this->colors["aqua"] = SDL_MapRGB(screen->format, 0xf00, 0xff, 0xff);
	this->colors["magenta"] = SDL_MapRGB(screen->format, 0xff, 0x00, 0xff);
	this->colors["green"] = SDL_MapRGB(screen->format, 0x00, 0x80, 0x00);
	this->colors["maroon"] = SDL_MapRGB(screen->format, 0x80, 0x00, 0x00);
	this->colors["purple"] = SDL_MapRGB(screen->format, 0x80, 0x00, 0x80);
	//this->colors["coral"] = SDL_MapRGB(screen->format, 0xff, 0x7f, 0x50);
	this->colors["orange"] = SDL_MapRGB(screen->format, 0xff, 0x45, 0x00);
	this->colors["salmon"] = SDL_MapRGB(screen->format, 0xfa, 0x80, 0x72);
	this->colors["olive"] = SDL_MapRGB(screen->format, 0x80, 0x80, 0x00);
	this->colors["white"] = SDL_MapRGB(screen->format, 0xff, 0xff, 0xff);
	//this->colors["indigo"] = SDL_MapRGB(screen->format, 0x4b, 0x00, 0x82);
	this->colors["zdefault"] = SDL_MapRGB(screen->format, 255, 255, 153);
}

ColorPicker::~ColorPicker()
{
}

void ColorPicker::init(){

	this->iterator = this->colors.begin();
}

Uint32 ColorPicker::getColorByName(const std::string & COLOR){

	std::map<std::string, Uint32>::iterator temp;
	
	this->notAvailableColor = colors[COLOR];
	
	return colors[COLOR];
}

Uint32 ColorPicker::automaticColorGetter(const std::string & COLOR){

	std::map<std::string, Uint32>::iterator temp;
	temp = this->iterator;
	/*if (this->iterator->first == COLOR){
	
		this->iterator++;
	}*/

	if (this->iterator != this->colors.end() && this->iterator->first != this->notAvailableColor){
		temp = iterator;
		iterator++;
		return temp->second;
	}
	else if (this->iterator != this->colors.end() && this->iterator->first == this->notAvailableColor){
		
		this->iterator++;
		temp = iterator;
		if (this->iterator != this->colors.end()){
		
			this->iterator++;
		}
		return temp->second;
	}
	return this->iterator->second;
	//if (this->iterator != this->colors.end() && this->iterator++->first != COLOR){
	//
	//	this->iterator++;
	//}
	//else if (this->iterator->first == COLOR){
	//
	//	this->iterator++;
	//}

	///*if (this->iterator->first == COLOR){
	//
	//	this->iterator++;
	//	
	//}*/
	//if (this->iterator->first == this->notAvailableColor){
	//
	//	this->iterator++;
	//}
	temp = this->iterator;
	return temp->second;
}