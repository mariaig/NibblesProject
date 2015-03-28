#pragma once

#include <SDL.h>
#include <string>

#define UP 'N'
#define RIGHT 'E'
#define DOWN 'S'
#define LEFT 'V'

class Snake{

	private:
		SDL_Rect snakeHead;
		bool direction[4];
		Sint16 speed;
		Uint32 color;
		int id;
		char livingStatus;
		bool deleted;

	public:
		bool isSetColor;
		Snake(Sint16, Sint16, Uint16, Uint16, Uint32, Sint16, unsigned short int, int);
		void Draw(SDL_Surface *screen);
		void changeDirectionByEvent(SDL_Event &);
		void changeDirectionByParam(const char);
		void move();
		void move(const Sint16 &, const Sint16 &);
		Sint16 getXPositon() const;
		Sint16 getYPositon() const;
		void deleteFromScreen(SDL_Surface *, const Uint32 &);
		int getId() const;
		bool isAlive() const ;
		std::string geDirection() const;
		void setLivingStatus(const char &);
		bool wasDeleted() const;
		void setColor(Uint32);
		/*int getId()const;*/
		void setId(int);
		
};