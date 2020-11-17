#pragma once

#include "../headers/Scenario.h"

#include <iostream>

using namespace std;

Scenario::Scenario(State* state) : Asset(state) {
	source.h = 256;
	source.w = 144;
	source.x = 0;
	source.y = 0;
	target.w = 144 * 2;
	target.h = 256 * 2;
	target.x = 0;
	target.y = 0;
}