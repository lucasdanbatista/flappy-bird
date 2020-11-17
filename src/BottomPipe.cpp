#include "../headers/BottomPipe.h"

BottomPipe::BottomPipe(State* state) : Asset(state) {
	type = "bottomPipe";

	source.h = 121;
	source.w = 26;
	source.x = 330;
	source.y = 0;

	target.h = 121 * 2;
	target.w = 26 * 2;

	setTargetInitialPosition();
}

void BottomPipe::setTargetInitialPosition() {
	target.x = 200;
	target.y = 291;
}