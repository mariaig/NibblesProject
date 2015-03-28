#pragma once
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <vector>
#include <mutex>
struct Point
{
	double x;
	double y;
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(double a, double b)
	{
		x = a;
		y = b;
	}
};

class GamePack
{
private:
	std::vector <GamePack> snakeData;
	Point coordonates;
	int clientId;//id-ul clientului
	char status;/*   0/1-mort/viu    */
	std::string directionIn;
	std::string directionOut;
	std::string recivedData;
	
public:
	GamePack(std::string data);
	GamePack();

	void setRecivedData(char * data, size_t len);
	void setCoordonates(double x, double y);
	void setClientId(int id);
	void setDirectionIn(char dir);
	void setDirectionOut(char dir);
	void setStatus(char stts);
	void setRecivedData(std::string data);

	Point getCoordonates();
	int getClientId();
	char getStatus();
	std::string getRecivedData();
	std::string getDirectionIn();
	std::string getDirectionOut();
	std::vector<GamePack> getVector();

	void empty();
	void parseRecivedData();


};