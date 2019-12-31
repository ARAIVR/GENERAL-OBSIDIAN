#include "Enemy001.h"
#include "TextureManager.h"
#include "ProcessInput.h"



const int FPS = 30;
int frametime9 = 0;
int frametime10 = 0;
int EnemyFrame;
int xvelocity=10;
int yvelocity =10;
int cnt;

int frame9, sheet9;

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





void Enemy001::Update()
{



	srcRect.h = 104;
	srcRect.w = 104;

	

	frametime9++;
	if (FPS / frametime9 == 6)

	{
		frametime9 = 0;

		//this controls the movement across the sprite sheet

		


	}

	

	switch (frametime9) {
	case 0:

		srcRect.x = 0;
		srcRect.y = 0;
		break;


	case 1:

		srcRect.x = 104;
		srcRect.y = 0;
		break;
	case 2:

		srcRect.x = 208;
		srcRect.y = 0;
		break;

	case 3:

		srcRect.x = 312;
		srcRect.y = 0;
		break;
	case 4:

		srcRect.x = 416;
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

	

enum xposition{xorigin=10,xlimit=800};

//xpos = xorigin;
cnt++;


if (cnt > 20) {
	xpos = xpos + xorigin;
	if (xpos > 800)
	{

		cnt = 0;
		xpos = xorigin;
	}
	
}
//for (int xpos = 10; xpos < 800; xpos =xpos-10 ) {}






}

void Enemy001::Render()
{
	//&srcRect and &destRect called by reference
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	//Obtain this data of the game object for animating a spritesheet
	SDL_QueryTexture(objTexture, NULL, NULL, &frame9, &sheet9);
	//SDL_RenderCopy(Game::renderer, objTexture,&playerRect,NULL);





}