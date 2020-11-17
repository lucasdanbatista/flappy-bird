#include <SDL_image.h>
#include "headers/Asset.h"
#include "headers/Bird.h"
#include "headers/Grass.h"
#include "headers/PlayButton.h"
#include "headers/State.h"
#include"headers/BottomPipe.h"

#undef main

Asset* scenario;
Asset* topPipe;
BottomPipe* bottomPipe;
Bird* bird;
Grass* grass;

void initialize(State state) {
	bird = new Bird(state);
	grass = new Grass(state);

	scenario = new Asset(state);
	scenario->source.h = 256;
	scenario->source.w = 144;
	scenario->source.x = 0;
	scenario->source.y = 0;
	scenario->target.w = 144 * 2;
	scenario->target.h = 256 * 2;
	scenario->target.x = 0;
	scenario->target.y = 0;

	bottomPipe = new BottomPipe(state);
	bottomPipe->source.h = 121;
	bottomPipe->source.w = 26;
	bottomPipe->source.x = 330;
	bottomPipe->source.y = 0;
	bottomPipe->target.h = 121 * 2;
	bottomPipe->target.w = 26 * 2;
	bottomPipe->target.x = 200;
	bottomPipe->target.y = 291;

	topPipe = new Asset(state);
	topPipe->source.h = 135;
	topPipe->source.w = 26;
	topPipe->source.x = 302;
	topPipe->source.y = 0;
	topPipe->target.h = 135 * 2;
	topPipe->target.w = 26 * 2;
	topPipe->target.x = 200;
	topPipe->target.y = -50;
}

void destroy(SDL_Surface* surface, SDL_Renderer* renderer, SDL_Window* window, SDL_Texture* texture) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(texture);
	SDL_Quit();
	IMG_Quit();
}

int main(int argc, char* args[]) {
	auto window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 288, 512, 0);
	auto surface = IMG_Load("sprites.png");
	auto fps = 1000 / 8;

	State state{};
	state.renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	state.texture = SDL_CreateTextureFromSurface(state.renderer, surface);

	SDL_FreeSurface(surface);

	initialize(state);

	PlayButton playButton(state);

	while (state.isRunning) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			SDL_GetMouseState(&state.mouseX, &state.mouseY);
			switch (event.type) {
			case SDL_QUIT:
				state.isRunning = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				bird->fly();
				if (state.isPaused) {
					if (state.mouseX >= 105 && state.mouseX <= 182) {
						if (state.mouseY >= 260 && state.mouseY <= 282) {
							bird->target.y = 250;
							state.isPaused = false;
						}
					}
				}
				break;
			}
		}

		if (bird->hasCollidedWith(grass)) {
			bird->target.y = grass->target.y - bird->collisionBox.height;
			state.isPaused = true;

			SDL_RenderClear(state.renderer);

			scenario->copyToRenderer();
			topPipe->copyToRenderer();
			bottomPipe->copyToRenderer();
			grass->copyToRenderer();
			bird->copyToRenderer();
			playButton.copyToRenderer();

			SDL_RenderPresent(state.renderer);
		}

		if (!state.isPaused) {
			SDL_RenderClear(state.renderer);

			scenario->copyToRenderer();
			topPipe->copyToRenderer();
			bottomPipe->copyToRenderer();
			grass->copyToRenderer();
			bird->copyToRenderer();

			bird->source.y = (state.currentFrame % 3) * 16;

			topPipe->target.x -= 8;
			if (topPipe->target.x < -70) topPipe->target.x = 300;

			bottomPipe->target.x -= 8;
			if (bottomPipe->target.x < -70) bottomPipe->target.x = 300;

			grass->target.x -= 8;
			if (grass->target.x < -70) grass->target.x = 0;

			bird->fall();

			SDL_RenderPresent(state.renderer);
			SDL_Delay(fps);

			state.currentFrame++;
		}
	}

	destroy(surface, state.renderer, window, state.texture);

	return 0;
}