#pragma once
#include "Game.h"

class ObsidianTarget
{

public:
	//ObsidianT definition
	ObsidianTarget(const char* texturesheet, int x, int y);

	~ObsidianTarget();

	//Each object will have its own update
	void Update();
	void Render();

private:
	//where the object will be placed on the screen
	int xpos;
	int ypos;

	SDL_Texture*objTexture1;
	SDL_Rect srcRect, destRect;


};
