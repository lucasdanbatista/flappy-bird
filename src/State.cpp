#include "./include/State.h"

State::State() {
	TTF_Init();
	font = TTF_OpenFont("FlappyFont.ttf", 24);
	window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 288, 512, 0);
	surface = IMG_Load("sprites.png");
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
}