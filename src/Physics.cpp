#include "../headers/Physics.h"

void Physics::applyGravity(SDL_Rect* target) {
	target->y += 15;
}