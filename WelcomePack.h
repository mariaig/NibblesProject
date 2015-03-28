#pragma once

#include <SDL.h>
#include <string>
#include <vector>
#include <boost/array.hpp>
#include <boost/asio.hpp>

struct Data1{

	std::string direction;
	char alivStatus;
	Sint16 x;
	Sint16 y;
	int snakeId;
};

class WelcomePack{

private:
	std::vector<Data1> updates;
	Data1 data;
	std::string recivedData;
public:
	void parseRecivedData();
	void init(char *, size_t);
	void setClientId(int id);
	void setCoordonates(double x, double y);
	void setDirectionIn(char dir);
	void setStatus(char stts);
	void setRecivedData(std::string data);
	void setRecivedData(char* data, size_t len);
};