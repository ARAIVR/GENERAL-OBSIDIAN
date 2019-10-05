#include "GameObject.h"
#include "TextureManager.h"

const int JOYSTICK_DEAD_ZONE = 8000;
const int FPS = 30;
int frametime = 0;
//game object implementation

#define MAX_CONTROLLERS 4
SDL_GameController *ControllerHandles[MAX_CONTROLLERS];
int texturewidth, textureheight;
int framewidth, frameheight;
int frame, sheet;
SDL_Rect playerRect;
GameObject::GameObject(const char* texturesheet, int x, int y)
{

	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;


}

void GameObject::Update()
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



	int MaxJoysticks = SDL_NumJoysticks();
	int ControllerIndex = 0;
	for (int JoystickIndex = 0; JoystickIndex < MaxJoysticks; ++JoystickIndex)
	{
		if (!SDL_IsGameController(JoystickIndex))
		{
			continue;
		}
		if (ControllerIndex >= MAX_CONTROLLERS)
		{
			break;
		}
		ControllerHandles[ControllerIndex] = SDL_GameControllerOpen(JoystickIndex);
		ControllerIndex++;
	}


	for (int ControllerIndex = 0; ControllerIndex < MAX_CONTROLLERS; ++ControllerIndex)
	{
		if (ControllerHandles[ControllerIndex])
		{
			SDL_GameControllerClose(ControllerHandles[ControllerIndex]);
		}
	}

	for (int ControllerIndex = 0;
		ControllerIndex < MAX_CONTROLLERS;
		++ControllerIndex)
	{
		if (ControllerHandles[ControllerIndex] != 0 && SDL_GameControllerGetAttached(ControllerHandles[ControllerIndex]))
		{
			// NOTE: We have a controller with index ControllerIndex.
			bool Up = SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_DPAD_UP);
			bool Down = SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_DPAD_DOWN);
			bool Left = SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_DPAD_LEFT);
			bool Right = SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
			bool Start = SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_START);
			bool Back = SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_BACK);
			bool LeftShoulder = SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_LEFTSHOULDER);
			bool RightShoulder = SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_RIGHTSHOULDER);
			bool AButton = SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_A);
			bool BButton = SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_B);
			bool XButton = SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_X);
			bool YButton = SDL_GameControllerGetButton(ControllerHandles[ControllerIndex], SDL_CONTROLLER_BUTTON_Y);

			Sint16 StickX = SDL_GameControllerGetAxis(ControllerHandles[ControllerIndex], SDL_CONTROLLER_AXIS_LEFTX);
			Sint16 StickY = SDL_GameControllerGetAxis(ControllerHandles[ControllerIndex], SDL_CONTROLLER_AXIS_LEFTY);
		}
		else
		{
			// TODO: This controller is note plugged in.
		}
	}



	//Event handler
	SDL_Event e;
	bool quit;
	int xDir = 0;
	int yDir = 0;


	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}







		else if (e.type == SDL_JOYAXISMOTION)
		{
			//Motion on controller 0
			if (e.jaxis.which == 0)
			{
				//X axis motion
				if (e.jaxis.axis == 0)
				{
					//Left of dead zone
					if (e.jaxis.value < -JOYSTICK_DEAD_ZONE)
					{
						xDir = -1;
						xDir < 0;
						xpos -= 45;



					}
					//Right of dead zone
					else if (e.jaxis.value > JOYSTICK_DEAD_ZONE)
					{
						//xDir = 1;
						xDir > 0;

						xpos += 45;


					}
					else
					{
						xDir = 0;
					}
				}



				//Y axis motion
				else if (e.jaxis.axis == 1)
				{
					//Below of dead zone
					if (e.jaxis.value < -JOYSTICK_DEAD_ZONE)
					{
						yDir = -1;
						ypos -= 45;
					}
					//Above of dead zone
					else if (e.jaxis.value > JOYSTICK_DEAD_ZONE)
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



	frametime++;
	if (FPS / frametime == 4)

	{
		frametime = 0;
		std::cout << "obsidian" << std::endl;
		//this controls the movement across the sprite sheet





	}

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


void GameObject::Render()
{
	//&srcRect and &destRect called by reference
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	//Obtain this data of the game object for animating a spritesheet
	SDL_QueryTexture(objTexture, NULL, NULL, &frame, &sheet);
	//SDL_RenderCopy(Game::renderer, objTexture,&playerRect,NULL);





}