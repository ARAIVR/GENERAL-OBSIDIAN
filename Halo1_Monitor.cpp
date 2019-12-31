#include "Halo1_Monitor.h"
#include "TextureManager.h"
#include "ProcessInput.h"



const int FPS = 30;
int frametime7 = 0;
int Halo1_Monitor_Damage;



int frame7, sheet7;

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





void Halo1_Monitor::Update()
{
	//The position of the object called every frame like Unity
















	srcRect.w = 100;
	srcRect.h = 68;



	frametime7++;
	if (FPS / frametime7 == 6)

	{
		frametime7 = 0;

		//this controls the movement across the sprite sheet





	}

	switch (Halo1_State) {
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

		srcRect.x = 500;
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


void Halo1_Monitor::Render()
{
	//&srcRect and &destRect called by reference
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	//Obtain this data of the game object for animating a spritesheet
	SDL_QueryTexture(objTexture, NULL, NULL, &frame7, &sheet7);
	//SDL_RenderCopy(Game::renderer, objTexture,&playerRect,NULL);





}