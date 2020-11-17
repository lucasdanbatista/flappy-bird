#pragma once

#include "Component.h"
#include "CollisionBox.h"

class Asset : public Component {
public:
	string type = "asset";
	CollisionBox collisionBox{};

	Asset(State* state);

	virtual bool hasCollidedWith(Asset* asset);

	virtual void setTargetInitialPosition();
};