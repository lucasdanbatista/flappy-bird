#pragma once

#include "Asset.h"

class Bird : public Asset
{

public:
	bool isFlypping = false;
	Bird(SDL_Renderer* renderer, SDL_Texture* texture);

	virtual void fly();
};

