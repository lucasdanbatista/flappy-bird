#pragma once

#include <SDL.h>

class Asset {
	SDL_Renderer* renderer;
	SDL_Texture* texture;

public:
	SDL_Rect source, target;

	Asset(SDL_Renderer* renderer, SDL_Texture* texture);

	virtual void copyToRenderer();
};