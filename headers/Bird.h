#pragma once

#include "Asset.h"

class Bird : public Asset
{

public:
	Bird(SDL_Renderer* renderer, SDL_Texture* texture);

	virtual void fly();

	virtual void fall();

	virtual bool hasCollidedWith(Asset asset) override;
};

