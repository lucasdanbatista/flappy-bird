#pragma once

#include <SDL.h>
#include <iostream>

using namespace std;

class Component {
protected:
	SDL_Renderer* renderer;
	SDL_Texture* texture;

public:
	SDL_Rect source{}, target{};

	Component(SDL_Renderer* renderer, SDL_Texture* texture);

	virtual void copyToRenderer();
};

