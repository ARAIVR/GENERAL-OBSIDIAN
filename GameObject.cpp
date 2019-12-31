#include "GameObject.h"
#include "TextureManager.h"
#include "ProcessInput.h"
#include "cmath"
#include "Enemy002.h"



const int JOYSTICK_DEAD_ZONE = 8000;
const int FPS = 30;
int frametime =0;
int deathCNT=0;
//game object implementation

//#define MAX_CONTROLLERS 4
//SDL_GameController *ControllerHandles[MAX_CONTROLLERS];
int texturewidth, textureheight;
int framewidth, frameheight;
int frame, sheet;
SDL_Rect playerRect;



SDL_bool GameObject::SDL_IntersectRectAndLine(const SDL_Rect* rect,
	int*            X1,
	int*            Y1,
	int*            X2,
	int*            Y2)

{

	return SDL_TRUE;
}

bool GameObject::intersectsWithEnemy(GameObject &g) {

	//if (g.GetOriginX() >= 100)

	if(sqrt(pow(GetOriginX() - g.GetOriginX(),2) + pow(GetOriginY() - g.GetOriginY(),2)) >= radius + g.GetRadius() )
	{
	SDL_SetTextureColorMod(objTexture, 255,255,255);
	std::cout << "___________________________________________________________________________" << std::endl;
	return false;
	}
	SDL_SetTextureColorMod(objTexture, 255, 0, 0);
	std::cout << "CCCOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOLLLLISIONNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN" << std::endl;
	int haloDMG =-10;
	g.deadobject = true;
	srcRect.x = 32;
	srcRect.y = 32;
	SDL_SetTextureColorMod(objTexture, 0, 0, 255);
	
	//this is where we check for collision with the 1 on the tilemap
	//if the 
	this->m = m;
	





	return true,haloDMG;


}





int GameObject::GetOriginX()
{
	return destRect.x + originX;
}


int GameObject::GetOriginY()
{
	return destRect.y + originY;
}

int GameObject::GetRadius()
{

	return radius;
}







void GameObject::Update()
{
	//The position of the object called every frame like Unity

	

	
	
	

	//m->

	


	



	srcRect.h = 32;
	srcRect.w = 32;

	originX = srcRect.h / 2;
	originY = srcRect.w / 2;
	radius = originX / 2;

	frametime++;
	if (FPS / frametime == 4)

	{
		frametime = 0;
		
		//this controls the movement across the sprite sheet





	}

	if (deadobject == true) {
		switch (frametime) {
		case 0:

			srcRect.x = 0;
			srcRect.y = 32;
			break;


		case 1:

			srcRect.x = 0;
			srcRect.y = 32;
			break;
		case 2:

			srcRect.x = 0;
			srcRect.y = 32;
			break;

		default: // compilation error: jump to default: would enter the scope of 'x'
				 // without initializing it
			std::cout << "default\n";
			break;
		}
	}

	if (deadobject == false) {
		switch (frametime) {
		case 0:

			srcRect.x = 0;
			srcRect.y = 0;
			break;


		case 1:

			srcRect.x = 32;
			srcRect.y = 0;
			break;
		case 2:

			srcRect.x = 64;
			srcRect.y = 0;
			break;

		default: // compilation error: jump to default: would enter the scope of 'x'
				 // without initializing it
			std::cout << "default\n";
			break;
		}



	}

	



	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;




	

}


void GameObject::Render()
{
	//&srcRect and &destRect called by reference
	//render of object returns nothing enemy is not rendered
	if (deadobject == true) {
		
		return;
	}
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	//Obtain this data of the game object for animating a spritesheet
	SDL_QueryTexture(objTexture, NULL, NULL, &frame, &sheet);
	//SDL_RenderCopy(Game::renderer, objTexture,&playerRect,NULL);





}