#include "ObsidianTarget.h"
#include "TextureManager.h"

const int JOYSTICK_DEAD_ZONE2 = 8000;
const int FPS2 = 12;
int frametime2 = 0;
//game object implementation

#define MAX_CONTROLLERS 4
SDL_GameController *ControllerHandles1[MAX_CONTROLLERS];
int texturewidth1, textureheight1;
int framewidth1, frameheight1;
int frame2, sheet2;
SDL_Rect ObsidianTargetRect;
ObsidianTarget::ObsidianTarget(const char* texturesheet, int x, int y)
{

	objTexture1 = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;


}

void ObsidianTarget::Update()
{
	//The position of the object called every frame like Unity

	//SDL_GameController *controller = nullptr;
	////xpos++;
	////ypos++;
	//SDL_bool SDL_GameControllerGetAttached(SDL_GameController* gamecontroller);
	//Sint16 StickX = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY);
	//std::cout << StickX << std::endl;
	//SDL_Event event;
	//SDL_PollEvent(&event);

	//if (event.type == 1)
	//
	//{
	//
	//}

	//else if (event.type == 0)
	//{

	//}



	



	//Event handler
	SDL_Event e1;
	bool quit;
	int xDir = 0;
	int yDir = 0;


	while (SDL_PollEvent(&e1) != 0)
	{
		//User requests quit
		if (e1.type == SDL_QUIT)
		{
			quit = true;
		}







		else if (e1.type == SDL_JOYAXISMOTION)
		{
			//Motion on controller 0
			if (e1.jaxis.which == 0)
			{
				//X axis motion
				if (e1.jaxis.axis == 0)
				{
					//Left of dead zone
					if (e1.jaxis.value < -JOYSTICK_DEAD_ZONE2)
					{
						xDir = -1;
						xDir < 0;
						xpos -= 15;



					}
					//Right of dead zone
					else if (e1.jaxis.value > JOYSTICK_DEAD_ZONE2)
					{
						//xDir = 1;
						xDir > 0;

						xpos += 15;


					}
					else
					{
						xDir = 0;
					}
				}



				//Y axis motion
				else if (e1.jaxis.axis == 1)
				{
					//Below of dead zone
					if (e1.jaxis.value < -JOYSTICK_DEAD_ZONE2)
					{
						yDir = -1;
						ypos -= 45;
					}
					//Above of dead zone
					else if (e1.jaxis.value > JOYSTICK_DEAD_ZONE2)
					{
						yDir = 1;
						ypos += 45;
					}
					else
					{
						yDir = 0;
					}
				}
			}
		}
	}






	srcRect.h = 32;
	srcRect.w = 32;



	frametime2++;
	if (FPS2 / frametime2 == 4)

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




	/*framewidth = texturewidth / 3;
	frameheight = textureheight / 4;

	playerRect.x = playerRect.y = 0;
	playerRect.w = framewidth;
	playerRect.h = frameheight;*/



	//std::cout << xDir << std::endl;

}


void ObsidianTarget::Render()
{
	//&srcRect and &destRect called by reference
	SDL_RenderCopy(Game::renderer, objTexture1, &srcRect, &destRect);
	//Obtain this data of the game object for animating a spritesheet
	SDL_QueryTexture(objTexture1, NULL, NULL, &frame2, &sheet2);
	//SDL_RenderCopy(Game::renderer, objTexture,&playerRect,NULL);





}