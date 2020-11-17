#include "../headers/State.h"

State::State() {
	window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 288, 512, 0);
	surface = IMG_Load("sprites.png");
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
}