#include "GameObject.h"
#include "Processinput.h"

#define MAX_CONTROLLERS 4
SDL_GameController *ControllerHandles[MAX_CONTROLLERS];


int MaxJoysticks = SDL_NumJoysticks();
int ControllerIndex = 0;



void Update()
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



	


	




	/*framewidth = texturewidth / 3;
	frameheight = textureheight / 4;

	playerRect.x = playerRect.y = 0;
	playerRect.w = framewidth;
	playerRect.h = frameheight;*/



	//std::cout << xDir << std::endl;

}

