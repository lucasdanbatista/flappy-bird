#pragma once

#include "Asset.h"

class Bird : public Asset
{

public:
	Bird(State* state);

	void fly();

	void fall();

	bool hasCollidedWith(Asset* asset);

	virtual void setTargetInitialPosition() override;

	virtual void updatePosition() override;
};

