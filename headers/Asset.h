#pragma once

#include "Component.h"

struct CollisionBox {
	int height, width;
};

class Asset : public Component {
public:
	string type = "asset";
	CollisionBox collisionBox{};

	Asset(State state);

	virtual bool hasCollidedWith(Asset* asset);
};