#pragma once
#include "Game.h"

class Halo1_Monitor{

public:
	//GameObject definition
	Halo1_Monitor(const char* texturesheet, int x, int y, int _halo1state);

	~Halo1_Monitor();

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
	int Halo1_State;




};
