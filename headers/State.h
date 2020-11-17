#pragma once

struct State {
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	bool isRunning = true;
	bool isPaused = false;
	int mouseX = 0;
	int mouseY = 0;
	int currentFrame = 0;
};