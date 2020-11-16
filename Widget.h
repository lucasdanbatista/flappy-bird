#pragma once

#include <SDL.h>

class Widget {
	SDL_Rect source{}, target{};

public:
	Widget(SDL_Renderer* renderer, SDL_Texture* texture);
};

