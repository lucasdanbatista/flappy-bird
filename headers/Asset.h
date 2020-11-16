#pragma once

#include "Component.h";

struct CollisionBox {
	double height, width;
};

class Asset : public Component {
public:
	string type = "asset";
	CollisionBox collisionBox{};

	Asset(SDL_Renderer* renderer, SDL_Texture* texture);

	virtual bool hasCollidedWith(Asset asset);
};