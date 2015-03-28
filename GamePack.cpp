#include "GamePack.h"
#include <iostream>
GamePack::GamePack()
{
	recivedData = "";
	coordonates.x = 0;
	coordonates.y = 0;
	clientId = 0;
	status = 0;
	directionIn = "";
	directionIn = "";
}
GamePack::GamePack(std::string data)
{
	recivedData = data;
	coordonates.x = 0;
	coordonates.y = 0;
	clientId = 0;
	status = 0;
	directionIn = "";
	directionOut = "";
}
void GamePack::setClientId(int id)
{
	clientId = id;
}
void GamePack::setCoordonates(double x, double y)
{
	coordonates.x = x;
	coordonates.y = y;
}
void GamePack::setDirectionIn(char dir)
{
	directionIn = dir;
}
void GamePack::setDirectionOut(char dir)
{
	
	directionOut = dir;
}
void GamePack::setStatus(char stts)
{
	status = stts;
}
void GamePack::setRecivedData(std::string data)
{
	recivedData = data;
}
void GamePack::setRecivedData(char* data, size_t len)
{
	recivedData = "";
	recivedData.append(data, len);
}
Point GamePack::getCoordonates()
{
	return coordonates;
}
int GamePack::getClientId()
{
	return clientId;
}
std::string GamePack::getDirectionIn()
{
	return directionIn;
}
std::string GamePack::getDirectionOut()
{
	return directionOut;
}
char GamePack::getStatus()
{
	return status;
}
std::string GamePack::getRecivedData()
{
	return recivedData;
}
void GamePack::parseRecivedData()
{
	std::string aux;//variabila auxiliara 
	std::string x;
	std::string y;
	size_t foundColon = recivedData.find(':');//pozitia primei aparitii a :
	size_t foundComma = recivedData.find(',', 4);//pozitia celei de-a 2a aparitie a ,
	size_t foundSemiColon = recivedData.find(';');//pozitia primei aparitii a ;

	aux.append(recivedData, 0, 2);
	setClientId(atof(aux.c_str()));
	x = recivedData.substr(3, foundColon - 3);
	y = recivedData.substr(foundColon + 1, foundComma - foundColon - 1);
	setCoordonates(atof(x.c_str()), atof(y.c_str()));
	setDirectionIn(recivedData[foundSemiColon - 3]);//setez directia
	setStatus(recivedData[foundSemiColon - 1]);//setez statusul
	setRecivedData(recivedData.substr(foundSemiColon + 1));
	snakeData.push_back(*this);
}
std::vector <GamePack> GamePack::getVector()
{
	return snakeData;
}
void GamePack::empty()
{
	snakeData.clear();
}