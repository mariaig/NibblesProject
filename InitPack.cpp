#include "InitPack.h"


InitPack::InitPack(){

	this->initialized = false;
}

void InitPack::setData(char* input, size_t len){

	std::string temp(input, len);
	std::string aux = "";
	int i;
	for (i = 0; temp[i] != ','; i++){
	
		aux.push_back(temp[i]);
	}

	this->data.myId = atoi(aux.c_str());
	aux = "";

	for (++i; temp[i] != ':'; i++){
		
		aux.push_back(temp[i]);
		
	}

	this->data.startXPosition = atoi(aux.c_str());
	aux = "";

	for (++i; temp[i] != ';'; i++){

		aux.push_back(temp[i]);
	}
	this->data.startYPosition = atoi(aux.c_str());

	this->initialized = true;
}

InitData InitPack::getData() const{

	return this->data;
}

bool InitPack::isSet() const{

	return this->initialized;
}