#include <iostream>
#include <SDL.h>
#include <SDL_gamecontroller.h>
//Here we can now add our Game Class which will make all the c
#include "Game.h"

//add instance of game as a pointer for use with the Class member Access operator ->
Game *game = nullptr;
//SDL_GameController *controller = nullptr;
int main(int argc, char *argv[])
{
	//THE GAME LOOP
	//while (game is running)
	//{

		//We will handle any user input
		//Update all objects eg. position, scores, health, timer etc
		//Render changes to the display

	//}

	//Controlling frame rate
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);

	
	SDL_GameController *controller = nullptr;

	for (int i = 0; i< SDL_NumJoysticks(); i++)
	{
		if (SDL_IsGameController(i))
		{
			controller = SDL_GameControllerOpen(i);
			break;
		}
	}
	





	const int FPS = 60;
	const int frameDelay = 10000 / FPS;
	Uint32 frameStart;
	int frameTime;


	//Declare our game pointer
	game = new Game();
	//ALT+F4 to quit

	//A class member operator -> is used. If used its return type must be a pointer or an onject of a class
	//to which you can apply


	game->init("ARAIVR SYSTEMS ENGINE", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 800, 640, false );
	//This is where we can add the Game Loop
	while (game->running())
	{
		frameStart = SDL_GetTicks();


		game->handleEvents();
		//This is where we handle the game logic
		game->update();
		game->render();
		//this gives us how long it take to go through handling our events handling events and rendering
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{

			SDL_Delay(frameDelay - frameTime);
		}

	}

	game->clean();
		return 0;
}