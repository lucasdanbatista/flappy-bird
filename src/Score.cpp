#include <string>
#include "include/Score.h"

using namespace std;

Score::Score(State* state) : Component(state) {
	Component::Component(state);
	this->state = state;
	target.x = 15;
	target.y = 15;
}

void Score::increment() {
	currentValue++;
	auto text = to_string(currentValue);
	createTextureFromText(text.c_str());
}

void Score::copyToRenderer() {
	SDL_RenderCopy(renderer, texture, NULL, &target);
}

void Score::createTextureFromText(const char* text) {
	auto surface = TTF_RenderText_Solid(state->font, text, textColor);
	target.w = surface->w;
	target.h = surface->h;
	texture = SDL_CreateTextureFromSurface(renderer, surface);
}