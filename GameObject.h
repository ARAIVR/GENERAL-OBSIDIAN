#pragma once
#include "Game.h"

class GameObject
{

public:
	//GameObject definition
	GameObject(const char* texturesheet,int x, int y);

	~GameObject();

	//Each object will have its own update
	void Update();
	void Render();

private:
	//where the object will be placed on the screen
	int xpos;
	int ypos;

	SDL_Texture*objTexture;
	SDL_Rect srcRect, destRect;
	

};
