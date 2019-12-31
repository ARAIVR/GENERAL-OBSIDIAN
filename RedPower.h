#pragma once
#include "Game.h"

class RedPower
{

public:
	//GameObject definition
	RedPower(const char* texturesheet, int x, int y);

	~RedPower();

	//Each object will have its own update
	void Update();
	void Render();





private:
	//where the object will be placed on the screen


	SDL_Texture*objTexture;
	SDL_Rect srcRect, destRect;
	//the variable below enable different objects to be controlled by different joysticks on the controller
	int xpos;
	int ypos;




};
