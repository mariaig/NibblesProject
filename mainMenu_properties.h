#pragma once

#include <vector>
#include <string>

#include "screen_properties.h"

const std::string mainMenuButPath = "mainMenu/";
const std::string mainMenuBackgroundImg = "backgroundImg.png";

const int bkgImgWidth = 640;
const int bkgImgHeight = 480;

//the number of buttonson the screen
const int nrButtons = 3;

const int borderDown = screenHeight / 4;

// dimensions of the image which shoud be the button
const int buttonWidth = 250;
const int buttonHeight = 55;


const int emptySpaceMM = screenHeight - nrButtons*buttonHeight-borderDown;
const int distBetweenButtons = emptySpaceMM / (2 * nrButtons);

const int startingX = screenWidth / 2;
const int startingY = emptySpaceMM / nrButtons;


//the name of the images wich should be loaded (in order) as buttons
const std::vector<std::string> imagesName = { "play.png", "settings.png", "exit2.png"};