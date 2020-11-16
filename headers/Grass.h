#pragma once

#include "Asset.h"

class Grass : public Asset {
public:
	Grass(SDL_Renderer* renderer, SDL_Texture* texture);
};

