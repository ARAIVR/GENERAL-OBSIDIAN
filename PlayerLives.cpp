#include "PlayerLives.h"
#include "TextureManager.h"
#include "ProcessInput.h"




//SDL_Rect playerlivesRect;

int frame8;
int sheet8;




void PlayerLives::Update()
{
	//The position of the object called every frame like Unity


	

	srcRect.h = srcH;
	srcRect.w = srcW;
	//srcRect.h = 32;
	//srcRect.w = 96;
	srcRect.x = 0;
	srcRect.y = 0;









	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;






}


void PlayerLives::Render()
{
	//&srcRect and &destRect called by reference
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	//Obtain this data of the game object for animating a spritesheet
	SDL_QueryTexture(objTexture, NULL, NULL, &frame8, &sheet8);
	//SDL_RenderCopy(Game::renderer, objTexture,&playerRect,NULL);





}