#include "Enemy002.h"
#include "TextureManager.h"
#include "ProcessInput.h"



const int FPS = 30;

int frametime11 = 0;
int EnemyFrame2;
int xvelocity2 = 10;
int yvelocity2 = 10;
int cnt2;

int frame11, sheet11;


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
//keep the functions for your objects in their cpp files Aston!!!!! K






void Enemy002::Update()
{



	srcRect.h = 104;
	srcRect.w = 104;



	frametime11++;
	if (FPS / frametime11 == 6)

	{
		frametime11 = 0;

		//this controls the movement across the sprite sheet




	}



	switch (frametime11) {
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



	enum xposition { xorigin = 50, xlimit = 800 };

	//xpos = xorigin;
	cnt2++;


	if (cnt2 > 20) {
		ypos = ypos + xorigin;
		if (ypos > 800)
		{

			cnt2 = 0;
			ypos = xorigin;
		}

	}
	//for (int xpos = 10; xpos < 800; xpos =xpos-10 ) {}






}

void Enemy002::Render()
{
	//&srcRect and &destRect called by reference
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	//Obtain this data of the game object for animating a spritesheet
	SDL_QueryTexture(objTexture, NULL, NULL, &frame11, &sheet11);
	//SDL_RenderCopy(Game::renderer, objTexture,&playerRect,NULL);





}