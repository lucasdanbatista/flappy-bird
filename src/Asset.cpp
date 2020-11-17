#include "../headers/Asset.h"

bool Asset::hasCollidedWith(Asset* asset) {
	return false;
}

Asset::Asset(State* state) : Component(state) {
	Component::Component(state);
}

void Asset::setTargetInitialPosition() {}