#pragma once
#include "Game.h"
#include "Enemy002.h"
#include "Map.h"


class GameObject
{

public:
	//GameObject definition
	//obtaining the map dat usingpointers to acces the map tiles and types
	//by passing it to the game object as a parameter
	//this can be applied to the Enemy002 to create collisions with the big bss enemies
	//GameObject(const char* texturesheet,int x, int y, int a, int b, SDL_Rect rec);
	GameObject(const char* texturesheet, int x, int y, int a, int b, SDL_Rect rec, Map *m);

	~GameObject();

	//Each object will have its own update
	void Update();
	void Render();

	//void processinputs(SDL_Event e);
	int yo;
	int GetOriginX();
	int GetOriginY();
	int GetRadius();
	//We want to detect when the player intersects/collides with enemy character
	//bool intersectsWithEnemy(Enemy002 &e);
	bool intersectsWithEnemy(GameObject &g);
	int GetXPos() { return xpos; }
	void SetXPos(int val) { xpos = val; }
	int GetYPos() { return ypos; }
	void SetYPos(int val) { ypos = val; }
	//this is so the renderer will remove the enemy sprites from the window so they do not get rendered
	bool deadobject = false;
	SDL_Rect GetSRCRect() { return srcRect; }
	void SetSRCRect(SDL_Rect val) { srcRect = val; }
	

private:
	//where the object will be placed on the screen
	SDL_bool SDL_IntersectRectAndLine(const SDL_Rect* rect,
		int*            X1,
		int*            Y1,
		int*            X2,
		int*            Y2);

	SDL_Texture*objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Rect PlayerPosition;
	//the variable below enable different objects to be controlled by different joysticks on the controller
	int xpos;
	int ypos;
	int XboxAxis1;
	int XboxAxis2;
	int originX, originY;
	int radius;
	Map* m;

	

};
