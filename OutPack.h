#pragma once

#include <string>
#include <vector>
#include "Snake.h"
#include <mutex>

class OutPack{

public:
	OutPack();
	std::string accessOutPutData(std::string direction = std::string());
	bool wasSet()const;
private:

	std::string output;
	std::mutex mu;
	bool isSet;
};