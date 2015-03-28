#include "ConfigData.h"

ConfigData::ConfigData()
{
	this->username = "";
	this->color = "";
	this->sounds = "yes";
	this->colorButtonPressedIndex = -1;
	this->soundsButtonPressedIndex = -1;
}



void ConfigData::setData(std::string username, std::string color, std::string sounds, int colorButtonIndex, int soundsButtonIndex)
{
	this->setUsername(username);
	this->setColor(color);
	this->setColorButtonPressedIndex(colorButtonIndex);
	this->setSounds(sounds);
	this->setSoundsButtonPressedIndex(soundsButtonIndex);
	
}

void ConfigData::setUsername(std::string username){	this->username = username;}
void ConfigData::setColor(std::string color){ this->color = color; }
void ConfigData::setSounds(std::string sounds){ this->sounds = sounds; }
void ConfigData::setColorButtonPressedIndex(int colorButtonIndex){ this->colorButtonPressedIndex = colorButtonIndex; }
void ConfigData::setSoundsButtonPressedIndex(int soundsButtonIndex){ this->soundsButtonPressedIndex = soundsButtonIndex; }

void ConfigData::clearData()
{
	this->username = "";
	this->color = "";
	this->sounds = "yes";
	this->colorButtonPressedIndex = -1;
	this->soundsButtonPressedIndex = -1;
}
