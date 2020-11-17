#include "../headers/Bird.h"

Bird::Bird(State state) : Asset(state) {
	source.h = 12;
	source.w = 17;
	source.x = 392;
	target.h = 12 * 2;
	target.w = 17 * 2;
	target.x = 100;
	target.y = 256;

	collisionBox.width = target.w;
	collisionBox.height = target.h;
}

void Bird::fly() {
	target.y -= 40;
}

void Bird::fall() {
	target.y += 15;
}

bool Bird::hasCollidedWith(Asset* asset) {
	if (asset->type == "grass") {
		return target.y >= 376;
	}
	else if (asset->type == "bottomPipe") {
		return true;
	}
	return false;
}