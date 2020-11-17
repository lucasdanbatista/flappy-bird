#pragma once

#include "Asset.h"

class Bird : public Asset
{

public:
	Bird(State* state);

	virtual void fly();

	virtual void fall();

	virtual bool hasCollidedWith(Asset* asset) override;
};

