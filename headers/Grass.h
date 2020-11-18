#pragma once

#include "Asset.h"

class Grass : public Asset {
public:
	Grass(State* state);

	virtual void updatePosition() override;

	virtual void animate(State* state) override;
};

