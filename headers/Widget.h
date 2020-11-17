#pragma once

#include "Component.h"

class Widget : public Component {
public:
	Widget(State state);

	virtual void show();

	virtual void hide();
};
