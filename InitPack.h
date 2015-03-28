#pragma once

#include <SDL.h>
#include <string>

struct InitData{
	int myId;
	Sint16 startXPosition;
	Sint16 startYPosition;
};

class InitPack{

public:
	InitPack();
	void setData(char* input, size_t len);
	InitData getData()const;
	bool isSet() const;

private:
	InitData data;
	bool initialized;
};