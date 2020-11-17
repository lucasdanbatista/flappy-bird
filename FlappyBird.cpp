#include <SDL_image.h>
#include "headers/Asset.h"
#include "headers/Bird.h"
#include "headers/Grass.h"
#include "headers/PlayButton.h"

#undef main

struct MouseCoordinates {
	int* x = 0, y = 0;
};

void destroy(SDL_Surface* surface, SDL_Renderer* renderer, SDL_Window* window, SDL_Texture* texture) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(texture);
	SDL_Quit();
	IMG_Quit();
}

int main(int argc, char* args[]) {
	auto window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 288, 512, 0);
	auto renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	auto surface = IMG_Load("sprites.png");
	auto texture = SDL_CreateTextureFromSurface(renderer, surface);
	auto fps = 1000 / 8;

	SDL_FreeSurface(surface);

	PlayButton playButton(renderer, texture);

	Asset scenario(renderer, texture);
	scenario.source.h = 256;
	scenario.source.w = 144;
	scenario.source.x = 0;
	scenario.source.y = 0;
	scenario.target.w = 144 * 2;
	scenario.target.h = 256 * 2;
	scenario.target.x = 0;
	scenario.target.y = 0;

	Bird bird(renderer, texture);

	Asset bottomPipe(renderer, texture);
	bottomPipe.source.h = 121;
	bottomPipe.source.w = 26;
	bottomPipe.source.x = 330;
	bottomPipe.source.y = 0;
	bottomPipe.target.h = 121 * 2;
	bottomPipe.target.w = 26 * 2;
	bottomPipe.target.x = 200;
	bottomPipe.target.y = 291;

	Asset topPipe(renderer, texture);
	topPipe.source.h = 135;
	topPipe.source.w = 26;
	topPipe.source.x = 302;
	topPipe.source.y = 0;
	topPipe.target.h = 135 * 2;
	topPipe.target.w = 26 * 2;
	topPipe.target.x = 200;
	topPipe.target.y = -50;

	Grass grass(renderer, texture);

	int mouseX, mouseY;
	auto currentFrame = 0;
	auto isRunning = true, isPaused = false;
	while (isRunning) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			SDL_GetMouseState(&mouseX, &mouseY);
			switch (event.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				bird.fly();
				cout << "Mouse button down" << endl;
				cout << "mouseX: " << mouseX << "\tmouseY: " << mouseY << endl;
				if (isPaused) {
					if (mouseX >= 105 && mouseX <= 182) {
						if (mouseY >= 260 && mouseY <= 282) {
							bird.target.y = 250;
							isPaused = false;
						}
					}
				}
				break;
			}
		}

		if (bird.hasCollidedWith(grass)) {
			bird.target.y = grass.target.y - bird.collisionBox.height;
			isPaused = true;

			SDL_RenderClear(renderer);

			scenario.copyToRenderer();
			topPipe.copyToRenderer();
			bottomPipe.copyToRenderer();
			grass.copyToRenderer();
			bird.copyToRenderer();
			playButton.copyToRenderer();

			SDL_RenderPresent(renderer);
		}

		if (!isPaused) {
			SDL_RenderClear(renderer);

			scenario.copyToRenderer();
			topPipe.copyToRenderer();
			bottomPipe.copyToRenderer();
			grass.copyToRenderer();
			bird.copyToRenderer();

			bird.source.y = (currentFrame % 3) * 16;

			topPipe.target.x -= 8;
			if (topPipe.target.x < -70) topPipe.target.x = 300;

			bottomPipe.target.x -= 8;
			if (bottomPipe.target.x < -70) bottomPipe.target.x = 300;

			grass.target.x -= 8;
			if (grass.target.x < -70) grass.target.x = 0;

			bird.fall();

			SDL_RenderPresent(renderer);
			SDL_Delay(fps);

			currentFrame++;
		}
	}

	destroy(surface, renderer, window, texture);

	return 0;
}