#include "./include/PlayButton.h"

PlayButton::PlayButton(State* state) : Widget(state) {
	Component::Component(state);
	source.h = 14;
	source.w = 40;
	source.x = 242;
	source.y = 213;

	target.x = 104;
	target.y = 257;
	target.h = source.h * 2;
	target.w = source.w * 2;
}