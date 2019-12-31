#include "Halo1.h"
#include "TextureManager.h"
#include "ProcessInput.h"



const int FPS = 30;
int frametime2 = 0;




int frame2, sheet2;

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





void Halo1::Update()
{
	//The position of the object called every frame like Unity
















	srcRect.h = 64;
	srcRect.w =64;



	frametime2++;
	if (FPS / frametime2 == 6)

	{
		frametime2 = 0;
		std::cout << "obsidian" << std::endl;
		//this controls the movement across the sprite sheet





	}

	switch (frametime2) {
	case 0:

		srcRect.x = 0;
		srcRect.y = 0;
		break;


	case 1:

		srcRect.x = 64;
		srcRect.y = 0;
		break;
	case 2:

		srcRect.x = 128;
		srcRect.y = 0;
		break;

	case 3:

		srcRect.x = 192;
		srcRect.y = 0;
		break;
	case 4:

		srcRect.x = 256;
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


void Halo1::Render()
{
	//&srcRect and &destRect called by reference
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	//Obtain this data of the game object for animating a spritesheet
	SDL_QueryTexture(objTexture, NULL, NULL, &frame2, &sheet2);
	//SDL_RenderCopy(Game::renderer, objTexture,&playerRect,NULL);





}