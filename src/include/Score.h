#pragma once

#include "Component.h"

class Score : public Component {
	unsigned currentValue = 0;

	virtual void createTextureFromText(const char* text);
public:
	SDL_Color textColor = { 255, 255, 255, 0 };
	Score(State* state);

	virtual void increment();

	virtual void copyToRenderer() override;
};