#pragma once

#include <SDL.h>
#include <string>
#include <vector>
#include <iostream>
#include <mutex>
#include <regex>

struct Data{

	char direction;
	char alivStatus;
	Sint16 x;
	Sint16 y;
	int snakeId;
};

class  InPack
{
public:
	 InPack();
	~ InPack();
	void setSnakesData(char* input, size_t len);
	std::vector<Data> getSnakesData() const;
	void print();
	std::vector<Data> accessSnakesData(std::string dt = std::string());
	
private:
	Data data;
	std::vector<Data> snakesData;
	void setId(int id);
	void setCoord(Sint16, Sint16);
	void setDirection(char);
	void setStatus(char);
	std::mutex mu;
	//check if string does not match the regex pattern
	bool stringIsOk(std::string check);

};

