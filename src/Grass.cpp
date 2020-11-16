#pragma once

#include "../headers/Grass.h"

Grass::Grass(SDL_Renderer* renderer, SDL_Texture* texture) : Asset(renderer, texture) {
	source.h = 56;
	source.w = 154;
	source.x = 146;
	source.y = 0;
	target.h = 56 * 2;
	target.w = 154 * 2.5;
	target.x = 0;
	target.y = 400;
}