#pragma once

#include <iostream>
class ConfigData
{
public:
	std::string username;
	std::string color;
	std::string sounds;
	int colorButtonPressedIndex;
	int soundsButtonPressedIndex;

public:
	ConfigData();

	void setData(std::string username, std::string color, std::string sounds, int colorButtonIndex, int soundsButtonIndex);

	void setUsername(std::string username);
	void setColor(std::string color);
	void setSounds(std::string sounds);
	void setColorButtonPressedIndex(int colorButtonIndex);
	void setSoundsButtonPressedIndex(int soundsButtonIndex);

	void clearData();

};