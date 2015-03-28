#include "WelcomePack.h"

void WelcomePack::parseRecivedData(){

	std::string aux;//variabila auxiliara 
	std::string x;
	std::string y;
	size_t foundColon = recivedData.find(':');//pozitia primei aparitii a :
	size_t foundComma = recivedData.find(',', 4);//pozitia celei de-a 2a aparitie a ,
	size_t foundSemiColon = recivedData.find(';');//pozitia primei aparitii a ;

	aux.append(recivedData, 0, 2);
	setClientId(atoi(aux.c_str()));
	x = recivedData.substr(3, foundColon - 3);
	y = recivedData.substr(foundColon + 1, foundComma - foundColon - 1);
	setCoordonates(atoi(x.c_str()), atoi(y.c_str()));
	setDirectionIn(recivedData[foundSemiColon - 3]);//setez directia
	setStatus(recivedData[foundSemiColon - 1]);//setez statusul
	setRecivedData(recivedData.substr(foundSemiColon + 1));
	updates.push_back(data);
}

void WelcomePack::setClientId(int id)
{
	this->data.snakeId = id;
}

void WelcomePack::setCoordonates(double x, double y)
{
	this->data.x = x;
	this->data.y = y;
}

void WelcomePack::setDirectionIn(char dir)
{
	this->data.direction = dir;
}

void WelcomePack::setStatus(char stts)
{
	this->data.alivStatus = stts;
}

void WelcomePack::setRecivedData(std::string data)
{
	recivedData = data;
}

void WelcomePack::setRecivedData(char* data, size_t len)
{
	recivedData = "";
	recivedData.append(data, len);
}

void WelcomePack::init(char * c, size_t sz){


	this->setRecivedData(c, sz);

	while (this->recivedData != "")
		{
			this->parseRecivedData();//de fiecare data cand se apeleaza, se baga in vector
		}
}