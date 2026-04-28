#pragma once
#include "DynamicObject.h"

class Bird : public DynamicObject {
public:
	Bird() = default;

	Bird(std::string PigSpriteLocation) : DynamicObject(PigSpriteLocation) {};
};
