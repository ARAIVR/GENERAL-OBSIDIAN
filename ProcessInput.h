#pragma once
#include "Game.h"
#include "GameObject.h"
#include "SDL.h"
#include "SDL_image.h"
class ProcessInput 

{
public:
	ProcessInput();
	~ProcessInput();
	
	void processinputs(SDL_Event e);
	bool Up;
	bool Down;

	bool Left;
	bool Right;
	bool Start;
	bool Back;
	bool LeftShoulder;
	bool RightShoulder;
	bool AButton;
	bool BButton;
	bool XButton;
	bool YButton;

	bool KeyPressUP;
	bool KeyPressDown;
	bool KeyPressLeft;
	bool KeyPressRight;
	bool KeyPressShoot;

	//Need to send the left axis controller id with this variable
	Sint16 StickX;
	Sint16 StickY;

};
