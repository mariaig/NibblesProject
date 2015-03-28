#include "Snake.h"
#include <iostream>
#include <fstream>


Snake::Snake(Sint16 x, Sint16 y, Uint16 w, Uint16 h, Uint32 color, Sint16 speed, unsigned short int startDirection, int id){

	this->snakeHead.x = x;
	this->snakeHead.y = y;
	this->snakeHead.w = w;
	this->snakeHead.h = h;
	this->color = color;
	this->speed = speed;
	this->direction[0] = this->direction[1] = this->direction[2] = this->direction[3] = 0;
	this->direction[startDirection] = 1;
	this->id;
	this->deleted = false;
	this->isSetColor = false;
	
};

void Snake::Draw(SDL_Surface *screen){

	std::ofstream myFile("maria.txt",std::fstream::out|std::fstream::app);
	if (myFile)
	{
		myFile <<"Draw Snake: "<< this->color << " " << this->snakeHead.x << " " << this->snakeHead.y << "\n";
	}
	

	myFile.close();
	SDL_FillRect(screen, &this->snakeHead, this->color);
}

void Snake::changeDirectionByEvent(SDL_Event & event){

	switch (event.key.keysym.sym) {
	case SDLK_UP:
		this->direction[0] = 1;
		this->direction[1] = 0;
		this->direction[2] = 0;
		this->direction[3] = 0;
		break;
	case SDLK_RIGHT:
		this->direction[1] = 1;
		this->direction[0] = 0;
		this->direction[2] = 0;
		this->direction[3] = 0;
		break;
	case SDLK_DOWN:
		this->direction[2] = 1;
		this->direction[0] = 0;
		this->direction[1] = 0;
		this->direction[3] = 0;
		break;
	case SDLK_LEFT:
		this->direction[3] = 1;
		this->direction[0] = 0;
		this->direction[1] = 0;
		this->direction[2] = 0;
		break;

	}
}

void Snake::changeDirectionByParam(const char direction){

	if (direction == '0'){
		
		this->direction[0] = 1;
		this->direction[1] = 0;
		this->direction[2] = 0;
		this->direction[3] = 0;
		return;
	}

	if (direction == '1'){
	
		this->direction[1] = 1;
		this->direction[0] = 0;
		this->direction[2] = 0;
		this->direction[3] = 0;
		return;
	}

	if (direction == '2'){
	
		this->direction[2] = 1;
		this->direction[0] = 0;
		this->direction[1] = 0;
		this->direction[3] = 0;
		return;
	}

	if (direction == '3'){
	
		this->direction[3] = 1;
		this->direction[0] = 0;
		this->direction[1] = 0;
		this->direction[2] = 0;
		return;
	}
	return;
}

void Snake::move(){

	if (this->direction[0])
		this->snakeHead.y -= 5;
	if (this->direction[1])
		this->snakeHead.x += 5;
	if (this->direction[2])
		this->snakeHead.y += 5;
	if (this->direction[3])
		this->snakeHead.x -= 5;
}

void Snake::move(const Sint16 & x, const Sint16 & y){

	this->snakeHead.x = x ;
	this->snakeHead.y = y;
}

Sint16 Snake::getXPositon() const{

	return this->snakeHead.x;
}
Sint16 Snake::getYPositon() const{

	return this->snakeHead.y;
}

int Snake::getId() const{

	return this->id;
}

void Snake::deleteFromScreen(SDL_Surface *screen, const Uint32 & screenColor){

	Uint32 * pixels = (Uint32 *)screen->pixels;
	Uint32 * pixel;
	//307200
	for (int y = 0; y <490000 ; y++){


		pixel = pixels + y;
		if (*pixel == this->color){

			*pixel = screenColor;
		}

	}
	this->deleted = true;
}

bool Snake::isAlive() const{

	if (this->livingStatus == '1'){
	
		return true;
	}

	return false;
}

std::string Snake::geDirection() const{

	if (this->direction[0]){
	
		return "N";
	}
	if (this->direction[1]){

		return "E";
	}
	if (this->direction[2]){

		return "S";
	}
	if (this->direction[3]){

		return "V";
	}
}

void Snake::setLivingStatus(const char & status){

	this->livingStatus = status;
}

bool Snake::wasDeleted() const{

	return this->deleted;
}


void Snake::setColor(Uint32 color)
{
	this->color = color;
	this->isSetColor = true;
}
//int Snake::getId() const
//{
//	return this->id;
//}

void Snake::setId(int id)
{
	this->id = id;
}