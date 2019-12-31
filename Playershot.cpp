#include "Playershot.h"
#include "TextureManager.h"
#include "ProcessInput.h"



const int FPS = 20;
int frametime4 = 0;




int frame4, sheet4;

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





void Playershot::Update()
{
	//The position of the object called every frame like Unity
















	srcRect.h = 32;
	srcRect.w = 32;



	frametime4++;
	if (FPS / frametime4 == 4)

	{
		frametime4 = 0;
		
		//this controls the movement across the sprite sheet





	}

	switch (frametime4) {
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


void Playershot::Render()
{
	//&srcRect and &destRect called by reference
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	//Obtain this data of the game object for animating a spritesheet
	SDL_QueryTexture(objTexture, NULL, NULL, &frame4, &sheet4);
	//SDL_RenderCopy(Game::renderer, objTexture,&playerRect,NULL);





}