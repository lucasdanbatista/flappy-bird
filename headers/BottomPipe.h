#pragma once

#include "Asset.h"

class BottomPipe : public Asset {
public:
	BottomPipe(State* state);

	virtual void setTargetInitialPosition() override;

	virtual void updatePosition() override;
};

