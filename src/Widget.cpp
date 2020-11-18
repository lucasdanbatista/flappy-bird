#include "./include/Widget.h"

Widget::Widget(State* state) : Component(state) {
	Component::Component(state);
}

void Widget::show() {
	copyToRenderer();
}

void Widget::hide() {
	SDL_RenderClear(renderer);
}