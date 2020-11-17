#pragma once

#include <SDL.h>
#include <SDL_image.h>

struct State {
	SDL_Surface* surface;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Window* window;
	bool isRunning = true;
	bool isPaused = false;
	int mouseX = 0;
	int mouseY = 0;
	int currentFrame = 0;

	State();
};