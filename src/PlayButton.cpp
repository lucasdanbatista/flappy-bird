#include "../headers/PlayButton.h";

PlayButton::PlayButton(SDL_Renderer* renderer, SDL_Texture* texture) : Widget(renderer, texture) {
	Component::Component(renderer, texture);
	source.h = 14;
	source.w = 40;
	source.x = 242;
	source.y = 213;

	target.x = 104;
	target.y = 257;
	target.h = source.h * 2;
	target.w = source.w * 2;
}