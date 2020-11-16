#include "../headers/Asset.h"

bool Asset::hasCollidedWith(Asset asset) {
	return false;
}

Asset::Asset(SDL_Renderer* renderer, SDL_Texture* texture) : Component(renderer, texture) {
	Component::Component(renderer, texture);
}