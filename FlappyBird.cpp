#include <SDL_image.h>
#include "headers/Asset.h"
#include "headers/Bird.h"
#include "headers/Grass.h"
#include "headers/PlayButton.h"
#include "headers/state.h"
#include "headers/BottomPipe.h"
#include "headers/TopPipe.h"
#include "headers/Scenario.h"

#undef main

Scenario* scenario;
TopPipe* topPipe;
BottomPipe* bottomPipe;
Bird* bird;
Grass* grass;
PlayButton* playButton;
State* state;
const int fps = (1000 / 8);

void initialize() {
	state = new State;
	bird = new Bird(state);
	grass = new Grass(state);
	playButton = new PlayButton(state);
	topPipe = new TopPipe(state);
	bottomPipe = new BottomPipe(state);
	scenario = new Scenario(state);
}

void destroy() {
	SDL_FreeSurface(state->surface);
	SDL_DestroyRenderer(state->renderer);
	SDL_DestroyWindow(state->window);
	SDL_DestroyTexture(state->texture);
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

			bird->animate(state);
			topPipe->animate(state);
			bottomPipe->animate(state);
			grass->animate(state);

			bird->fall();

			bottomPipe->updatePosition();

			SDL_RenderPresent(state->renderer);
			SDL_Delay(fps);

			state->currentFrame++;
		}
	}

	destroy();

	return 0;
}