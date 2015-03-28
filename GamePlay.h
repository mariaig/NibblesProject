#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include "Snake.h"
#include "ColorPicker.h"
#include "InPack.h"
#include "OutPack.h"
#include "InitPack.h"
#include "main_properties.h"
#include "Globals.h"

void play(SDL_Surface *screen, std::vector<Snake> & snakes, ColorPicker & colorPicker, Color & color, const int FPS, InPack & inPack, OutPack & outPack, InitPack & initPack, std::vector <Data> & update, SDL_Event & event);