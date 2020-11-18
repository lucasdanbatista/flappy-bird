#include "../headers/TopPipe.h"

TopPipe::TopPipe(State* state) : Asset(state) {
	type = "topPipe";

	source.h = 135;
	source.w = 26;
	source.x = 302;
	source.y = 0;

	target.h = 135 * 2;
	target.w = 26 * 2;

	setTargetInitialPosition();
}

void TopPipe::setTargetInitialPosition() {
	target.x = 200;
	target.y = -50;
}

void TopPipe::animate(State* state) {
	target.x -= 8;
	if (target.x < -70) target.x = 300;
}