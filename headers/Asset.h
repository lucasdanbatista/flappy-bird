#pragma once

#include "Component.h"
#include "CollisionBox.h"
#include "Position.h"

class Asset : public Component {
public:
	string type = "asset";
	CollisionBox collisionBox{};
	Position position{};

	Asset(State* state);

	virtual bool hasCollidedWith(Asset* asset);

	virtual void setTargetInitialPosition();

	virtual void updatePosition();
};