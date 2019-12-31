#include "Halo2.h"
#include "TextureManager.h"
#include "ProcessInput.h"



const int FPS = 30;
int frametime3 = 0;




int frame3, sheet3;

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





void Halo2::Update()
{
	//The position of the object called every frame like Unity
















	srcRect.h = 96;
	srcRect.w = 96;



	frametime3++;
	if (FPS / frametime3 == 6)

	{
		frametime3 = 0;
		
		//this controls the movement across the sprite sheet





	}

	switch (frametime3) {
	case 0:

		srcRect.x = 0;
		srcRect.y = 0;
		break;


	case 1:

		srcRect.x = 96;
		srcRect.y = 0;
		break;
	case 2:

		srcRect.x = 192;
		srcRect.y = 0;
		break;

	case 3:

		srcRect.x = 288;
		srcRect.y = 0;
		break;
	case 4:

		srcRect.x = 384;
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


void Halo2::Render()
{
	//&srcRect and &destRect called by reference
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	//Obtain this data of the game object for animating a spritesheet
	SDL_QueryTexture(objTexture, NULL, NULL, &frame3, &sheet3);
	//SDL_RenderCopy(Game::renderer, objTexture,&playerRect,NULL);





}