#pragma once
#include <SDL.h>
#include <SDL_Image.h>
#include <list>


using namespace std;

class Particles {
public:
	Particles();
	virtual ~Particles();

	void Update();

	void Render(SDL_Surface* renderFrame);

private:
	SDL_Surface* particleSurface;
	list<SDL_Rect> particlePositions;

	Uint32 emissionRate = 200;
	Uint32 emissionRange = 90;
	Uint32 Gravity = 2;

	Uint32 lastParticleSpawn;
	Uint32 nextParticleSpawn;

};