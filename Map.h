#pragma once
#include "Game.h"

class Map
{
public:

	//constructor
	Map();
	//deconstructor
	~Map();


	void LoadMap(int arr[20][25]);
	void DrawMap();



private:

	SDL_Rect src, dest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	//Array of map tiles
	int map[20][25];

};
