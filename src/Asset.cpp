#include "../headers/Asset.h"

Asset::Asset(SDL_Renderer* renderer, SDL_Texture* texture) {
	this->renderer = renderer;
	this->texture = texture;
}

void Asset::copyToRenderer() {
	SDL_RenderCopy(renderer, texture, &source, &target);
}