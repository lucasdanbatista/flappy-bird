#include "../headers/Bird.h"

Bird::Bird(State* state) : Asset(state) {
	source.h = 12;
	source.w = 17;
	source.x = 392;

	target.h = 12 * 2;
	target.w = 17 * 2;

	setTargetInitialPosition();

	collisionBox.width = target.w;
	collisionBox.height = target.h;
}

void Bird::setTargetInitialPosition() {
	target.x = 100;
	target.y = 256;
}

void Bird::fly() {
	target.y -= 8;
}

void Bird::fall() {
	target.y += 4;
	updatePosition();
}

void Bird::updatePosition() {
	position.x = target.x;
	position.y = target.y;
}

bool Bird::hasCollidedWith(Asset* asset) {
	if (asset->type == "grass") {
		return target.y >= 376;
	}
	else if (asset->type == "bottomPipe") {
		return (asset->target.x <= 132 && asset->target.x >= 120) && target.y >= 311 ||
			(asset->target.x <= 112 && asset->target.x >= 48) && target.y >= 270;
	}
	return false;
}

void Bird::animate(State* state) {
	source.y = (state->currentFrame % 3) * 16;
}