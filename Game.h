#pragma once
#include "SDL.h"
#include <iostream>
#include <SDL_image.h>



class Game {

public:
	Game();
	~Game();

	// 7 functions are declared/made 
	//Alt+F4 to quit
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();
	// this function is done inline
	bool running() { return isRunning; }

	//create a static instance of the renderer can be called anywhere
	static SDL_Renderer *renderer;
private:
	int cnt=0;
	bool isRunning;
	SDL_Window *window;
	



};