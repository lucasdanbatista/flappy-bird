#pragma once

#include <SDL.h>
#include <iostream>
#include "State.h"

using namespace std;

class Component {
protected:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	State* state;

public:
	SDL_Rect source{}, target{};

	Component(State* state);

	virtual void copyToRenderer();
};

