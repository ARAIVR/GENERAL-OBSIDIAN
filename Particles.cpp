#include "stdafx.h"
#include "Particles.h"

Particles::Particles()
{
	particleSurface = IMG_Load("snow.png");

}

Particles::~Particles() {
	//deconstructor to destroy the particle
	SDL_FreeSurface(particleSurface);
}


void Particles::Update()
{

	if (SDL_GetTicks() - lastParticleSpawn >= nextParticleSpawn) {

		lastParticleSpawn = SDL_GetTicks();
		nextParticleSpawn = emissionRate + (rand() % emissionRange);
		SDL_Rect r;
		r.x = (rand() % 768);
		r.y = 0;
		particlePositions.push_back(r);
	}
	//update all particles
	for (auto& particle : particlePositions) {

		particle.y += Gravity;
	}

	/*particlePositions.remove_if([](SDL_Rect r) { return r.x >= 768 || r.y >= 768; }*/

}

void Particles::Render(SDL_Surface* renderframe)
{

	for (auto& particle : particlePositions) {

		SDL_BlitSurface(particleSurface, NULL, renderframe, &particle);
	}
}