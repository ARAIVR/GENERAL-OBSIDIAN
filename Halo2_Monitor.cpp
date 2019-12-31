#include "Halo2_Monitor.h"
#include "TextureManager.h"
#include "ProcessInput.h"



const int FPS = 30;
int frametime6 = 0;
int Halo2_Monitor_Damage;



int frame6, sheet6;

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





void Halo2_Monitor::Update()
{
	//The position of the object called every frame like Unity
















	srcRect.w = 100;
	srcRect.h = 68;



	frametime6++;
	if (FPS / frametime6 == 6)

	{
		frametime6 = 0;

		//this controls the movement across the sprite sheet





	}

	switch (Halo2_State) {
	case 100:

		srcRect.x = 0;
		srcRect.y = 0;
		break;


	case 80:

		srcRect.x = 100;
		srcRect.y = 0;
		break;
	case 60:

		srcRect.x = 200;
		srcRect.y = 0;
		break;

	case 40:

		srcRect.x = 300;
		srcRect.y = 0;
		break;
	case 20:

		srcRect.x = 400;
		srcRect.y = 0;
		break;

	case 0:

		srcRect.x = 400;
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


void Halo2_Monitor::Render()
{
	//&srcRect and &destRect called by reference
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	//Obtain this data of the game object for animating a spritesheet
	SDL_QueryTexture(objTexture, NULL, NULL, &frame6, &sheet6);
	//SDL_RenderCopy(Game::renderer, objTexture,&playerRect,NULL);





}