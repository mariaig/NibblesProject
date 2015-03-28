#pragma once

#include "screen_properties.h"
#include <vector>
#include <string>


/*-----Color Buttons prop-----*/
const std::string configMenuButPath = "configMenu/";
const std::string colorsButPath = "colors/";
const std::vector<std::string> colorButtons = { "red.png", "blue.png","lime.png", "yellow.png", "aqua.png", "salmon.png", "magenta.png", "green.png", "maroon.png", "purple.png", "orange.png", "olive.png" };

const int nrColorBut = colorButtons.size();
const int buttonsPerLine = 4;

const int colorButtonWidth = 55;
const int colorButtonHeight = 35;

const int emptySpace = (screenWidth)/2 - buttonsPerLine*colorButtonWidth;

const int spaceBetweenButoonsW = (emptySpace - border) / (buttonsPerLine - 1);
const int spaceBetweenButtonsH = 20;

const int buttonBorderWidth = 4;
const int buttonBorderR = 134;
const int buttonBorderG = 215;
const int buttonBorderB = 148;

const std::string yesSoundsButtonName = "yes.png";
const int yesButtonW = 80;
const int yesButtonH = 40;

const std::string noSoundsButtonName = "no.png";
const int noButtonW = 80;
const int noButtonH = 40;

const std::string usernameButtonName = "chooseUsername.png";
const int usernameButtonW = 245;
const int usernameButtonH = 40;

const std::string editUsernameButtonName = "editUsername.png";
const int editUsernameButtonW = 190;
const int editUsernameButtonH = 35;

const std::string backButtonName = "back.png";
const int backButtonW = 100;
const int backButtonH = 35;

const std::string saveButtonName = "save.png";
const int saveButtonW = 120;
const int saveButtonH = 35;

const std::string clearButtonName = "clear.png";
const int clearButtonW = 120;
const int clearButtonH = 35;


/*------TEXT PROPERTIES-----*/

const std::vector<std::string> textObj = { "Snake Color: ", "Enable sounds: " };

const int textStartingY = border;
const int textStartingX = border;

const std::string textFont = "MSSansSerif";
const int textSize = 30;
const int spaceBetweenColorTextAndEnableS = (nrColorBut%buttonsPerLine == 0) ? 
							(nrColorBut / buttonsPerLine) * (colorButtonHeight + spaceBetweenButtonsH) : 
							(nrColorBut / buttonsPerLine + 1)* (colorButtonHeight + spaceBetweenButtonsH);

const int textR = 181;
const int textG = 230;
const int textB = 29;

const int maxWordLength = 10;

const int endOfTextWidth = screenWidth / 2;
