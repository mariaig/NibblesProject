#include "GamePlay.h"

#include "Globals.h"


void play(SDL_Surface *screen, std::vector<Snake> & snakes, ColorPicker & colorPicker, Color & color, const int FPS, InPack & inPack, OutPack & outPack, InitPack & initPack, std::vector <Data> & update, SDL_Event & event){

	
	Mix_Music *music;
	Mix_Chunk *dieEffect;
	
	bool right = false;
	bool left = false;
	
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	
	music = Mix_LoadMUS("253-overworld-bgm.wav");
	dieEffect = Mix_LoadWAV("boxing_bell_multiple.wav");

	if (enableSounds=="yes")
	{
		Mix_PlayMusic(music, -1);
	}
	

	Uint32 start;
	
	while (globalRunning) {
	//	start = SDL_GetTicks();
		
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				globalRunning = false;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_UP:
					outPack.accessOutPutData("N");

					break;
				case SDLK_RIGHT:
					outPack.accessOutPutData("R");

					break;
				case SDLK_DOWN:
					outPack.accessOutPutData("S");

					break;
				case SDLK_LEFT:
					outPack.accessOutPutData("L");

					break;
				}

				break;
			}
		}
		
		update = inPack.accessSnakesData();


		if (update.size()==3){
			////HNDLE SNAKES
			for (int i = 0; i < update.size(); i++)
			{
				snakes[i].setId(update[i].snakeId);
				if (!snakes[i].isSetColor)
				{
					if (snakes[i].getId()==initPack.getData().myId)
					{
						snakes[i].setColor(colorPicker.getColorByName(myColor));
					}
					else
					{
						snakes[i].setColor(colorPicker.automaticColorGetter(color.DEFAULT));
					}
				}
			
				snakes[i].setLivingStatus(update[i].alivStatus);
				

				if (snakes[i].isAlive())
				{
					snakes[i].move(update[i].x, update[i].y);
					snakes[i].Draw(screen);
				}
				else {
					if (snakes[i].wasDeleted() == false)
					{
						if (enableSounds == "yes")
						{
							Mix_PlayChannel(-1, dieEffect, 0);
						}
						snakes[i].deleteFromScreen(screen, SDL_MapRGB(screen->format, gameR, gameG, gameB));
					}
				}
			}

		}
		
		SDL_Flip(screen);
	}
	Mix_FreeChunk(dieEffect);
	Mix_FreeMusic(music);
	Mix_CloseAudio();
}
