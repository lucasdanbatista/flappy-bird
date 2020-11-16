#pragma once

#include "../headers/Grass.h"

#include <iostream>

using namespace std;

Grass::Grass(SDL_Renderer* renderer, SDL_Texture* texture) : Asset(renderer, texture) {
	type = "grass";
	
	source.h = 56;
	source.w = 154;
	source.x = 146;
	source.y = 0;
	target.h = 56 * 2;
	target.w = 154 * 2.5;
	target.x = 0;
	target.y = 400;

	collisionBox.height = target.h;
	collisionBox.width = target.w;
}