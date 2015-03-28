#include "OutPack.h"

OutPack::OutPack(){

	this->output = "N";
	this->isSet = false;
}
std::string OutPack::accessOutPutData(std::string direction){

	std::lock_guard<std::mutex> locker(mu);

	if (this->isSet == true){
		
		this->isSet = false;
		return output;
	}

	if (direction.length()>0 && direction.compare("L") == 0 || direction.compare("R") == 0){
		
		output = direction;
		this->isSet = true;
	}
	
	return output;
}

bool OutPack::wasSet()const{

	return this->isSet;
}