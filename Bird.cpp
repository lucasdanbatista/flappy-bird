#include "Bird.h"

Bird::Bird(SDL_Renderer* renderer, SDL_Texture* texture) : Asset(renderer, texture) {
	source.h = 12;
	source.w = 17;
	source.x = 392;
	target.h = 12 * 2;
	target.w = 17 * 2;
	target.x = 100;
	target.y = 256;
}

void Bird::fly() {
	isFlypping = true;
	target.y -= 40;
}
