#pragma once

#include <SDL.h>
#include <map>
#include <string>

#include "Color.h"

class ColorPicker
{
public:
	ColorPicker(SDL_Surface *screen);
	~ColorPicker();
	void init();
	Uint32 getColorByName(const std::string & );
	Uint32 automaticColorGetter(const std::string &);
private:
	std::map<std::string, Uint32> colors;
	std::map<std::string, Uint32>::iterator iterator;
	std::string notAvailableColor;
};

