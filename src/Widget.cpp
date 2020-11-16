#include "../headers/Widget.h"

Widget::Widget(SDL_Renderer* renderer, SDL_Texture* texture) : Component(renderer, texture) {
	Component::Component(renderer, texture);
}