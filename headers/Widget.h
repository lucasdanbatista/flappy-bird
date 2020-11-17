#pragma once

#include "Component.h"

class Widget : public Component {
public:
	Widget(SDL_Renderer* renderer, SDL_Texture* texture);

	virtual void show();

	virtual void hide();
};
