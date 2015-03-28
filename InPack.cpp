#include "InPack.h"
#include <fstream>

InPack::InPack()
{
	
}

InPack::~InPack()
{
}
void InPack::setId(int id){

	this->data.snakeId = id;
}

void InPack::setCoord(Sint16 x, Sint16 y){

	this->data.x = x*10;
	this->data.y = y*10;
}

void InPack::setDirection(char direction){

	
	this->data.direction = direction;
}

void InPack::setStatus(char status){

	this->data.alivStatus = status;
}



void InPack::setSnakesData(char* input, size_t len){

	std::string recivedData = "";
	recivedData.append(input, len);
	
	while (recivedData != ""){
		std::string aux;//variabila auxiliara 
		std::string x;
		std::string y;
		size_t foundColon = recivedData.find(':');//pozitia primei aparitii a :
		size_t foundComma = recivedData.find(',', 4);//pozitia celei de-a 2a aparitie a ,
		size_t foundSemiColon = recivedData.find(';');//pozitia primei aparitii a ;

		aux.append(recivedData, 0, 2);
		this->setId(atoi(aux.c_str()));
		x = recivedData.substr(3, foundColon - 3);
		y = recivedData.substr(foundColon + 1, foundComma - foundColon - 1);
		this->setCoord(atoi(x.c_str()), atoi(y.c_str()));
		this->setDirection(recivedData[foundSemiColon - 3]);//setez directia
		setStatus(recivedData[foundSemiColon - 1]);//setez statusul
		recivedData = recivedData.substr(foundSemiColon + 1);
		this->snakesData.push_back(this->data);
	}
}

std::vector<Data> InPack::accessSnakesData(std::string dt){
	// clean-up
	this->snakesData.clear();

	std::lock_guard<std::mutex> locker(mu);
	std::string recivedData = dt;

	
	if (recivedData[0] == 'S' && recivedData[1] == 'T')
	{
		return this->snakesData;
	}

	if (this->stringIsOk(dt)){
		
		this->snakesData.clear();
		
		std::ofstream myFile("log.txt", std::fstream::out);
		if (myFile)
		{
			myFile << "-----> " << dt << "\n";
		}
		myFile.close();
		
		while (recivedData.length() >1){
			
			std::string aux;//variabila auxiliara 
			std::string x;
			std::string y;

			size_t foundColon = recivedData.find(':');//pozitia primei aparitii a :
			size_t foundComma = recivedData.find(',', 4);//pozitia celei de-a 2a aparitie a ,
			size_t foundSemiColon = recivedData.find(';');//pozitia primei aparitii a ;

			if (foundColon != std::string::npos && foundComma != std::string::npos && foundSemiColon != std::string::npos)
			{
				aux.append(recivedData, 0, 2);
				this->setId(atoi(aux.c_str()));
				x = recivedData.substr(3, foundColon - 3);
				y = recivedData.substr(foundColon + 1, foundComma - foundColon - 1);
				this->setCoord(atoi(x.c_str()), atoi(y.c_str()));
				this->setDirection(recivedData[foundSemiColon - 3]);//setez directia
				setStatus(recivedData[foundSemiColon - 1]);//setez statusul
				recivedData = recivedData.substr(foundSemiColon + 1);
				this->snakesData.push_back(this->data);
			}
		} 
		
	}

	return this->snakesData;
}

std::vector<Data> InPack::getSnakesData() const{

	return this->snakesData;
}

void InPack::print(){

	for (int i = 0; i < this->snakesData.size(); i++){
	
		std::cout << "\n" << snakesData[i].snakeId << " " << snakesData[i].direction << " " << snakesData[i].x << " " << snakesData[i].y << " " << snakesData[i].alivStatus;
	}
}

//"01,112:33,N,1;11,1:333,S,0;21,17:2,E,0;"

bool InPack::stringIsOk(std::string check)
{
	if (check == "")
	{
		return 0;
	}
	if (std::regex_match(check, std::regex("([[:digit:]]+,[[:digit:]]+:[[:digit:]]+,[[:digit:]]+,[[:digit:]]+;)+")))
	{
		return 1;
	}
	return 0;
}