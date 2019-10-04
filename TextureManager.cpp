#include "TextureManager.h"
//now we call the non class memeber function that we do not have to instantiate LoadTexture
SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
	//We have to call the surface for the texture
	SDL_Surface* tempSurface = IMG_Load(texture);
	//now apply the texture to the surface
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	return tex;

}