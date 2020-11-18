#include "./include/Asset.h"

Asset::Asset(State* state) : Component(state) {
	Component::Component(state);
}

void Asset::setTargetInitialPosition() {}

void Asset::updatePosition() {}

void Asset::animate(State* state) {}