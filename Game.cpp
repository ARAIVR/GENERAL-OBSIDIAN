#include "Game.h"
#include <chrono>
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
//#include "ECS.h"
//#include "Components.h"



//create a pointer to a new game object

GameObject* player;
GameObject* enemy;
GameObject* background;
Map* map;
SDL_GameController *controller = nullptr;
//SDL_Renderer pointer we set to nullptr as we have not started yet
SDL_Renderer* Game::renderer = nullptr;

//We can now call our components like UNITY!!!!



//Game constructor from Game.h header file
Game::Game()
{}
//the deconstructor
Game::~Game()
{}
//Youtube Let's Make Games Tutorial SDL2
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	
	



	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;

	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "subsystems Initialised..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "window created" << std::endl;

			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				std::cout << "renderer created" << std::endl;
			}

			isRunning = true;

		}
		else {
			isRunning = false;
		}
	}
	//call the gameobject pointer  dereference operator
	player = new GameObject("assets/labrish1.png",0,0);
	enemy = new GameObject("assets/monster1.png",64,64);
	//background = new GameObject("assets/bg.png", renderer);
	map = new Map();

	

}

void Game::handleEvents()
{
	//polling is where it is waiting to see what the status of the event is
	SDL_Event event;
	SDL_PollEvent(&event);

	//A switch statement is used depending on the status of the event that has been poll'd

	switch (event.type) {
	case SDL_QUIT:
		//When we click the X in our window the event handler will see that the handlerEvents isRunning is False
		//and stop the game running on its next loop
			isRunning = false;
				break;
	
		default:
			break;



	}
}
void Game::update()
{
	//player calls the Update using the class member access operator->
	player->Update();
	//enemy->Update();
	
	
	
	cnt++;
	
}
// this is called to render our objects to the screen
void Game::render()
{
	SDL_RenderClear(renderer);
	//This is where we add stuff to render
	//We will now call the playerTex
	//This has a layer order. The bottom one will be at the top of the surface
	//as it is rendered last
	map->DrawMap();
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);
	
	

}

void Game::clean()
{
	cnt = 0;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_GameControllerClose(controller);
	controller = NULL;
	SDL_Quit();
	
	std::cout << "Game Cleaned" << std::endl;



}





