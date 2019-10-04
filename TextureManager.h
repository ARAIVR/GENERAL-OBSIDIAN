#pragma once
#include "Game.h"


class TextureManager{
public:
	//need to be static this is a class unction do not need to instantiate it is not a class member
	static SDL_Texture* LoadTexture(const char* filename);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
	{

		SDL_RenderCopy(Game::renderer, tex, &src, &dest);
	}

};
