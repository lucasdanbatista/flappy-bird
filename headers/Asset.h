#pragma once

#include <SDL.h>
#include <iostream>

using namespace std;

struct CollisionBox {
	double height, width;
};

class Asset {
	SDL_Renderer* renderer;
	SDL_Texture* texture;

public:
	string type = "asset";
	SDL_Rect source{}, target{};
	CollisionBox collisionBox{};

	Asset(SDL_Renderer* renderer, SDL_Texture* texture);

	virtual void copyToRenderer();

	virtual bool hasCollidedWith(Asset asset);
};