#include "Map.h"
#include "TextureManager.h"
int frame1, sheet1;
const int FPS1 = 30;
int frametime1 = 0;

int lvl1[20][25] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

};


Map::Map()
{
	dirt = TextureManager::LoadTexture("assets/dirt.png");
	grass = TextureManager::LoadTexture("assets/grass.png");
	water = TextureManager::LoadTexture("assets/stars.png");

	LoadMap(lvl1);
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
	
	frametime1++;
	if (FPS1 / frametime1 == 4)

	{
		frametime1 = 0;
		std::cout << "water will change" << std::endl;
		//this controls the movement across the sprite sheet





	}

	switch (frametime1) {
	case 0:

		src.x = 0;
		src.y = 0;
		break;


	case 1:

		src.x = 32;
		src.y = 32;
		break;
	case 2:

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
		std::cout << "updated" << std::endl;
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

