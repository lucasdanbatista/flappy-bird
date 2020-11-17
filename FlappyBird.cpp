#include <SDL_image.h>
#include "headers/Asset.h"
#include "headers/Bird.h"
#include "headers/Grass.h"
#include "headers/PlayButton.h"
#include "headers/state.h"
#include "headers/BottomPipe.h"
#include "headers/TopPipe.h"

#undef main

Asset* scenario;
Asset* topPipe;
BottomPipe* bottomPipe;
Bird* bird;
Grass* grass;
PlayButton* playButton;
State* state;

void initialize() {
	bird = new Bird(state);
	grass = new Grass(state);
	playButton = new PlayButton(state);
	topPipe = new TopPipe(state);
	bottomPipe = new BottomPipe(state);

	scenario = new Asset(state);
	scenario->source.h = 256;
	scenario->source.w = 144;
	scenario->source.x = 0;
	scenario->source.y = 0;
	scenario->target.w = 144 * 2;
	scenario->target.h = 256 * 2;
	scenario->target.x = 0;
	scenario->target.y = 0;
}

void destroy(SDL_Surface* surface, SDL_Renderer* renderer, SDL_Window* window, SDL_Texture* texture) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(texture);
	SDL_Quit();
	IMG_Quit();
}

void refreshScene() {
	SDL_RenderClear(state->renderer);
	scenario->copyToRenderer();
	topPipe->copyToRenderer();
	bottomPipe->copyToRenderer();
	grass->copyToRenderer();
	bird->copyToRenderer();
}

void pauseGameAndShowPlayButton() {
	state->isPaused = true;
	refreshScene();
	playButton->copyToRenderer();
	SDL_RenderPresent(state->renderer);
}

void restartGame() {
	topPipe->setTargetInitialPosition();
	bird->setTargetInitialPosition();
	bottomPipe->setTargetInitialPosition();
	state->isPaused = false;
}

int main(int argc, char* args[]) {
	auto window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 288, 512, 0);
	auto surface = IMG_Load("sprites.png");
	auto fps = 1000 / 8;

	state = new State;
	state->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	state->texture = SDL_CreateTextureFromSurface(state->renderer, surface);

	SDL_FreeSurface(surface);

	initialize();

	while (state->isRunning) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			SDL_GetMouseState(&state->mouseX, &state->mouseY);
			switch (event.type) {
			case SDL_QUIT:
				state->isRunning = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				bird->fly();
				if (state->isPaused) {
					if (state->mouseX >= 105 && state->mouseX <= 182) {
						if (state->mouseY >= 260 && state->mouseY <= 282) {
							restartGame();
						}
					}
				}
				break;
			}
		}

		if (bird->hasCollidedWith(grass) || bird->hasCollidedWith(bottomPipe)) {
			bird->target.y = grass->target.y - bird->collisionBox.height;
			pauseGameAndShowPlayButton();
		}

		if (!state->isPaused) {
			refreshScene();

			bird->source.y = (state->currentFrame % 3) * 16;

			topPipe->target.x -= 8;
			if (topPipe->target.x < -70) topPipe->target.x = 300;

			bottomPipe->target.x -= 8;
			if (bottomPipe->target.x < -70) bottomPipe->target.x = 300;

			grass->target.x -= 8;
			if (grass->target.x < -70) grass->target.x = 0;

			bird->fall();

			SDL_RenderPresent(state->renderer);
			SDL_Delay(fps);

			state->currentFrame++;
		}
	}

	destroy(surface, state->renderer, window, state->texture);

	return 0;
}