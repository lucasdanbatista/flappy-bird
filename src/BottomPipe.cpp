#include "./include/BottomPipe.h"

BottomPipe::BottomPipe(State* state) : Asset(state) {
	type = "bottomPipe";

	source.h = 121;
	source.w = 26;
	source.x = 330;
	source.y = 0;

	target.h = 121 * 2;
	target.w = 26 * 2;

	setTargetInitialPosition();

	collisionBox.height = target.h;
	collisionBox.width = target.w;
}

void BottomPipe::setTargetInitialPosition() {
	target.x = 200;
	target.y = 291;
}

void BottomPipe::updatePosition() {
	position.x = target.x;
	position.y = target.y;
}

void BottomPipe::animate(State* state) {
	target.x -= 8;
	if (target.x < -70) target.x = 300;
}