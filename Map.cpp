#include "Map.h"
#include "TextureManager.h"
#include <chrono>
#include <thread>
#include<iostream>
#include "Blockchain.h"

//Score needs to be a global public variable across the classes
int GlobalVariableSCORE = 0;
int GameOverScore = 0;
int frame1, sheet1;
const int FPS1 = 30;
int frametime1 = 0;
//extract the position of the ones during the game and if the player collides with the 1's then
//this reduces health
//and will be interactivity with the tile map.







Map::Map()
{
	dirt = TextureManager::LoadTexture("assets/dirt.png");
	grass = TextureManager::LoadTexture("assets/grass.png");
	//based off a sprite sheet for efficiency water are the stars effect
	water = TextureManager::LoadTexture("assets/stars2.png");
	
	
	/*using namespace std::chrono_literals;
	
	std::cout << "Hello waiter\n" << std::flush;
	auto start = std::chrono::high_resolution_clock::now();

	
	std::this_thread::sleep_for(2s);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed = end - start;
	std::cout << "Waited " << elapsed.count();
	LoadMap(lvl2);*/
	//map starts from zero 0
	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;
	dest.x = dest.y = 0;

	SDL_RenderCopy(Game::renderer, water, &src, &dest);
	SDL_QueryTexture(water, NULL, NULL, &frame1, &sheet1);
}


void Map::LoadMap(int arr[20][25])

{

	
	
	
	
	
	
	
	//for loop for iterating over a grid
	for (int row = 0; row < 20; row++)
	{
		//then it iterates over the column
		for (int column = 0; column < 25; column++)
		{

			//this needs looking at for better understanding
			map[row][column] = arr[row][column];
		}


	}


}

void Map::DrawMap()


{
	// Design 
	frametime1++;
	if (FPS1 / frametime1 == 6)

	{
		frametime1 = 0;
		//std::cout << "water will change" << std::endl;




	}



	//levels based on enemies killed
	//new map backgrounds
	//if 100 points case

	//LEVELS
	//swap this with game over variable to control game background
	if (GlobalVariableSCORE <= 300) {
		switch (frametime1) {
		case 0:

			//this controls the movement across the sprite sheet
			LoadMap(lvl1);
			src.x = 0;
			src.y = 0;
			break;


		case 1:
			LoadMap(lvl2);
			src.x = 32;
			src.y = 32;
			break;
		case 2:
			LoadMap(lvl3);
			src.x = 64;
			src.y = 64;
			break;


		case 3:
			LoadMap(lvl4);
			src.x = 64;
			src.y = 64;
			break;


		case 4:
			LoadMap(lvl4);
			src.x = 64;
			src.y = 64;
			break;
		case 5:
			LoadMap(lvl4);
			src.x = 64;
			src.y = 64;
			break;
		case 6:
			LoadMap(lvl5);
			src.x = 64;
			src.y = 64;
			break;

		default: // compilation error: jump to default: would enter the scope of 'x'
				 // without initializing it
			std::cout << "default\n";
			break;
		}


		int type = 0;
		for (int row = 0; row < 20; row++)
		{
			//then it iterates over the column
			//std::cout << "updated" << std::endl;
			for (int column = 0; column < 25; column++)
			{

				//this needs looking at for better understanding
				type = map[row][column];
				dest.x = column * 32;
				dest.y = row * 32;
				switch (type)
				{
				case 0:
					TextureManager::Draw(water, src, dest);
					break;
				case 1:
					TextureManager::Draw(grass, src, dest);
					break;
				case 2:
					TextureManager::Draw(dirt, src, dest);
					break;

				default:
					break;

				}
			}


		}
	}
	
	if (GlobalVariableSCORE > 301 & GlobalVariableSCORE < 800 )
	{
		
		
		
		
		switch (frametime1) {
		case 0:

			//this controls the movement across the sprite sheet
			LoadMap(lvlGameWin);
			src.x = 0;
			src.y = 0;
			break;


		case 1:
			LoadMap(lvlGameWin);
			src.x = 32;
			src.y = 32;
			break;
		case 2:
			LoadMap(lvlGameWin);
			src.x = 64;
			src.y = 64;
			break;


		case 3:
			LoadMap(lvlGameWin);
			src.x = 64;
			src.y = 64;
			break;


		case 4:
			LoadMap(lvlGameWin);
			src.x = 64;
			src.y = 64;
			break;
		case 5:
			LoadMap(lvlGameWin);
			src.x = 64;
			src.y = 64;
			break;
		case 6:
			LoadMap(lvlGameWin);
			src.x = 64;
			src.y = 64;
			break;

		default: // compilation error: jump to default: would enter the scope of 'x'
				 // without initializing it
			std::cout << "default\n";
			break;
		}


		int type = 0;
		for (int row = 0; row < 20; row++)
		{
			//then it iterates over the column
			//std::cout << "updated" << std::endl;
			for (int column = 0; column < 25; column++)
			{

				//this needs looking at for better understanding
				type = map[row][column];
				dest.x = column * 32;
				dest.y = row * 32;
				switch (type)
				{
				case 0:
					TextureManager::Draw(water, src, dest);
					break;
				case 1:
					TextureManager::Draw(grass, src, dest);
					break;
				case 2:
					TextureManager::Draw(dirt, src, dest);
					break;

				default:
					break;

				}
			}


		}
	}
	if (GlobalVariableSCORE > 10000)
	{
		switch (frametime1) {
		case 0:

			//this controls the movement across the sprite sheet
			LoadMap(lvlGameOver);
			src.x = 0;
			src.y = 0;
			break;


		case 1:
			LoadMap(lvlGameOver);
			src.x = 32;
			src.y = 32;
			break;
		case 2:
			LoadMap(lvlGameOver);
			src.x = 64;
			src.y = 64;
			break;


		case 3:
			LoadMap(lvlGameOver);
			src.x = 64;
			src.y = 64;
			break;


		case 4:
			LoadMap(lvlGameOver);
			src.x = 64;
			src.y = 64;
			break;
		case 5:
			LoadMap(lvlGameOver);
			src.x = 64;
			src.y = 64;
			break;
		case 6:
			LoadMap(lvlGameOver);
			src.x = 64;
			src.y = 64;
			break;

		default: // compilation error: jump to default: would enter the scope of 'x'
				 // without initializing it
			std::cout << "default\n";
			break;
		}


		int type = 0;
		for (int row = 0; row < 20; row++)
		{
			//then it iterates over the column
			//std::cout << "updated" << std::endl;
			for (int column = 0; column < 25; column++)
			{

				//As this iterates and builds it checks with the DrawMAp for the design
				//by identifying the type a collision with the player can be initiated.
				type = map[row][column];
				dest.x = column * 32;
				dest.y = row * 32;
				switch (type)
				{
				case 0:
					TextureManager::Draw(water, src, dest);
					break;
				case 1:
					TextureManager::Draw(grass, src, dest);
					break;
				case 2:
					TextureManager::Draw(dirt, src, dest);
					break;

				default:
					break;

				}
			}


		}
	}
	
}

