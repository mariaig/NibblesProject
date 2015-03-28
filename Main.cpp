#include <SDL.h>
#include <SDL_mixer.h>
#include <thread>
#include <iostream>
#include "main_properties.h"
#include "WinLoseMenu.h"

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <stdio.h>

#include "MainMenu.h"
#include "screen_properties.h"
#include <SDL_ttf.h>

#include "Snake.h"
#include "ColorPicker.h"
#include "InPack.h"
#include "OutPack.h"
#include "InitPack.h"
#include "Networking.h"
#include "GamePlay.h"

using boost::asio::ip::tcp;

#include "Globals.h"


void showImages(std::string imageName, SDL_Surface* screen);
void initGame(boost::asio::ip::tcp::socket &socket, InitPack& pack, SDL_Surface* screen);



int main(int argc, char** argv)
{

	try
	{
		if (argc != 2)
		{
			std::cerr << "Usage: client <host>" << std::endl;
			return 1;
		}


		boost::asio::io_service io_service;
		tcp::resolver resolver(io_service);
		tcp::resolver::query query(argv[1], "daytime");
		tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
		tcp::socket socket(io_service);


		SDL_Init(SDL_INIT_EVERYTHING);
		TTF_Init();


		SDL_Surface* screen = SDL_SetVideoMode(screenWidth, screenHeight, 32, SDL_HWSURFACE);
		SDL_WM_SetCaption("Nibbles", NULL);

		ColorPicker colorPicker(screen);
		colorPicker.init();
		Color color;
		InPack inPack;
		OutPack outPack;
		InitPack initPack;

		SDL_Event event;


		SDL_Rect background;
		background.w = screenWidth;
		background.h = screenHeight;
		background.x = background.y = 0;

		Uint32 colorbg = SDL_MapRGB(screen->format, screenBackgroundR, screenBackgroundG, screenBackgroundB);

		SDL_FillRect(screen, &background, colorbg);

		MainMenu* mainMenu = new MainMenu();
		ConfigMenu* configMenu = new ConfigMenu();
		UsernameMenu* usernameMenu = new UsernameMenu();
		WinLoseMenu* winLoseMenu = new WinLoseMenu();

		mainMenu->show(screen);

		bool run = true;
		bool edit = false;
		bool saved = false;
		int result = 0;

		enum CurrentState { MAINMENU, CONFIGMENU, USERNAMEMENU, WAITING, GAME,GAMEOVER };
		CurrentState currentState = MAINMENU;

		while (run)
		{
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_MOUSEBUTTONDOWN:
					if (currentState == CurrentState::MAINMENU)
					{
						result = mainMenu->manageMouseDown(screen, event.motion.x, event.motion.y);
					}
					else if (currentState == CurrentState::CONFIGMENU)
					{
						result = configMenu->manageMouseDown(screen, event.motion.x, event.motion.y);
					}
					break;
				case SDL_MOUSEBUTTONUP:
					if (currentState == CurrentState::MAINMENU)
					{
						switch (result)
						{
						case 0:
							//play game

							//std::cout << "\n-----------------------------------------";
							//std::cout << "\n----->Username: " << configMenu->getUsername();
							//std::cout << "\n----->Color: " << configMenu->getColor();
							//std::cout << "\n----->ES: " << configMenu->getEnableSounds();
							//std::cout << "\n-----------------------------------------";
							currentState = WAITING;
							break;
						case 1:
							//settings 
							configMenu->newData->setData(configMenu->getUsername(), configMenu->getColor(), configMenu->getEnableSounds(), configMenu->getColorButtonPressedIndex(), configMenu->getSoundsButtonPressedIndex());
							configMenu->show(screen);
							currentState = CurrentState::CONFIGMENU;
							saved = false;
							break;
						case 2:
							//exit
							run = false;
							break;
						}
					}
					else if (currentState == CurrentState::CONFIGMENU)
					{
						switch (result)
						{
						case 0:
							// pressed color||sounds button
							break;
						case 1:
							//choose your own username
							usernameMenu->ti->setInput("");
							usernameMenu->show(screen);
							currentState = CurrentState::USERNAMEMENU;
							break;
						case 2:
							//edit your username
							usernameMenu->ti->setInput("");
							usernameMenu->setOldUsername(configMenu->getUsername());
							usernameMenu->show(screen);
							currentState = CurrentState::USERNAMEMENU;
							edit = true;
							break;
						case 3:
							//go back to mainMenu
							mainMenu->show(screen);
							currentState = CurrentState::MAINMENU;
							break;
						case 4:
							//save button pressed:
							saved = true;
							break;
						case 5:
							//clear button pressed:
							usernameMenu->ti->setInput("");
							edit = false;
							saved = false;
							break;
						}
					}
					break;
				case SDL_KEYDOWN:
					if (currentState == CurrentState::USERNAMEMENU)
					{
						if (!usernameMenu->ti->manageKeyDown(event))
						{
							//if false => pressed enter => go to configMenu
							configMenu->newData->username = usernameMenu->ti->getInput();
							configMenu->show(screen);
							currentState = CurrentState::CONFIGMENU;
							break;
						}
						if (edit)
						{
							//was pressed the edit button
							if (saved || configMenu->oldData->username != "")
							{
								//if an username was already saved show the edit menu
								usernameMenu->showEditMenu(screen);
							}
							else
							{
								//but if the username was not saved, show the username menu
								usernameMenu->show(screen);
							}
						}
						else
						{
							//choose your username button pressed
							usernameMenu->show(screen);
						}
					}
					break;
				case SDL_KEYUP:
					if (currentState == CurrentState::USERNAMEMENU)
					{
						usernameMenu->ti->manageKeyUp(event);
					}
					break;
				case SDL_QUIT:
					//SDL_QUIT event => close everything
					run = false;
					break;
				}

				//if waiting
				if (currentState == WAITING){
					boost::asio::connect(socket, endpoint_iterator);
					initGame(socket, initPack, screen);
					screen = SDL_SetVideoMode(gameScreenWidth, gameScreenHeight, 32, SDL_HWSURFACE);
					currentState = GAME;
				}
				//if gameplay
				if (currentState == GAME){

					const int FPS = 30;
					std::vector<Snake> snakes; //vectorul de serpi
					std::vector <Data> update;//va primii updaturile pt serpi din inPack

					//myColor poate fi acum "" sau o culoare din cele selectate (ex: "green")
					myColor = configMenu->getColor();
					
					if (myColor == "")
					{
						myColor = color.DEFAULT;
					}

					enableSounds = configMenu->getEnableSounds();

					Snake snake1(5, 350, 10, 10, colorPicker.getColorByName(color.WHITE), 10, 2, 1);
					Snake snake2(690, 350, 10, 10, colorPicker.automaticColorGetter(color.WHITE), 10, 2, 2);
					Snake snake3(690, 350, 10, 10, colorPicker.automaticColorGetter(color.WHITE), 10, 2, 2);


					snakes.push_back(snake1);
					snakes.push_back(snake2);
					snakes.push_back(snake3);

					//START GAME
					globalRunning = true;

					std::thread t1(networking, std::ref(inPack), std::ref(outPack), std::ref(socket), std::ref(event));

					//////////////////////////////////////////////////////DRAW


					Uint32 screenColor = SDL_MapRGB(screen->format, gameR, gameG, gameB);
					SDL_FillRect(screen, &screen->clip_rect, screenColor);



					play(screen, snakes, colorPicker, color, FPS, inPack, outPack, initPack, update, event);
					////////////////////////////////////////////////////////////


					t1.join();
					//at the end it's game over:)
					currentState = GAMEOVER;
					
				}
				if (currentState == CurrentState::GAMEOVER)
				{
					screen = SDL_SetVideoMode(screenWidth, screenHeight, 32, SDL_HWSURFACE);
					if (winLose.compare("L") == 0)
					{
						winLoseMenu->showLose(screen, configMenu->getUsername());
					}
					else
					{
						winLoseMenu->showWin(screen, configMenu->getUsername());
					}
					SDL_Delay(5000);
					currentState = MAINMENU;
					mainMenu->show(screen);
				}
			}
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	TTF_Quit();
	SDL_Quit();
	return 0;
}


void showImages(std::string imageName, SDL_Surface* screen)
{
	SDL_Rect location = { 0, 0, 0, 0 };
	SDL_Surface* image = IMG_Load((imagesPath + imageName + imagesExtensions).c_str());
	SDL_BlitSurface(image, NULL, screen, &location);
	SDL_Flip(screen);
}

void initGame(boost::asio::ip::tcp::socket &socket, InitPack& pack, SDL_Surface* screen)
{
	boost::array<char, 128> buf;
	boost::system::error_code error;
	boost::system::error_code ignored_error;


	int flag = 3;

	std::string temp("ceva");
	while (temp[0] != 'S' && temp[1] != 'T')
	{
		temp = "";

		if (flag == 0)
		{
			flag = 3;
		}
		boost::asio::write(socket, boost::asio::buffer("N"), ignored_error);
		size_t len = socket.read_some(boost::asio::buffer(buf), error);

		temp.append(buf.data(), len - 1);

		if (temp == "")
		{
			boost::asio::write(socket, boost::asio::buffer("N"), ignored_error);
			len = socket.read_some(boost::asio::buffer(buf), error);
		}
		if (pack.isSet() == false)
			pack.setData(buf.data(), len);

		showImages(waitImage + std::to_string(flag), screen);
		Sleep(100);
		SDL_Delay(100);
		flag--;
	}


	flag = readyTime - 1;
	while (flag >= 0)
	{
		showImages(readyImage + std::to_string(flag), screen);
		Sleep(100);
		SDL_Delay(100);
		flag--;
	}

	return;

}