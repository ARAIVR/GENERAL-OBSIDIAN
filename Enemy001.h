#pragma once
#include "Game.h"

class Enemy001
{

public:
	//GameObject definition
	Enemy001(const char* texturesheet, int x, int y);

	~Enemy001();

	//Each object will have its own update
	void Update();
	void Render();

	void processinputs(SDL_Event e);
	int yo;



private:
	//where the object will be placed on the screen


	SDL_Texture*objTexture;
	SDL_Rect srcRect, destRect;
	//the variable below enable different objects to be controlled by different joysticks on the controller
	int xpos;
	int ypos;
	



};
