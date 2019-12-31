#include "RedPower.h"
#include "TextureManager.h"
#include "ProcessInput.h"



const int FPS = 30;
int frametime12 = 0;

int cnt3;


int frame12, sheet12;

//GameObject::GameObject(const char* texturesheet, int x, int y, int a, int b)
//{
//
//	objTexture = TextureManager::LoadTexture(texturesheet);
//
//	xpos = x;
//	ypos = y;
//	XboxAxis1 = a;
//	XboxAxis2 = b;
//
//}





void RedPower::Update()
{
	//The position of the object called every frame like Unity
















	srcRect.h = 25;
	srcRect.w = 32;
	
	enum xposition { xorigin = 50, xlimit = 800 };




	switch (frametime12) {
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







	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;






}


void RedPower::Render()
{
	//&srcRect and &destRect called by reference
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	//Obtain this data of the game object for animating a spritesheet
	SDL_QueryTexture(objTexture, NULL, NULL, &frame12, &sheet12);
	//SDL_RenderCopy(Game::renderer, objTexture,&playerRect,NULL);





}