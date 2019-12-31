#pragma once
#include "Game.h"
#include "GameObject.h"


class Enemy002
{

public:
	//GameObject definition
	Enemy002(const char* texturesheet, int x, int y, SDL_Rect rec);

	~Enemy002();

	//Each object will have its own update
	void Update();
	void Render();

	void processinputs(SDL_Event e);
	int yo;
	//this is a function called GetXpos
	//Correct way to access x and y position when oobject is created!!!!
	
	int GetXPos() { return xpos; }
	void SetXPos(int val) { xpos = val; }
	int GetYPos() { return ypos; }
	void SetYPos(int val) { ypos = val; }

	int GetOriginX();
	int GetOriginY();
	int GetRadius();
	SDL_Rect GetSRCRect() { return srcRect; }
	void SetSRCRect(SDL_Rect val) { srcRect = val; }

private:
	//where the object will be placed on the screen


	SDL_Texture*objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Rect EnemyPosition;
	//the variable below enable different objects to be controlled by different joysticks on the controller
	int xpos;
	int ypos;
	int originX, originY;
	int radius;



};
