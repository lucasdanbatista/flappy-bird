#pragma once

#include "./include/Component.h"

Component::Component(State* state) {
	this->renderer = state->renderer;
	this->texture = state->texture;
}

void Component::copyToRenderer() {
	SDL_RenderCopy(renderer, texture, &source, &target);
}