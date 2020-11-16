#include "../headers/Component.h"

Component::Component(SDL_Renderer* renderer, SDL_Texture* texture) {
	this->renderer = renderer;
	this->texture = texture;
}

void Component::copyToRenderer() {
	SDL_RenderCopy(renderer, texture, &source, &target);
}