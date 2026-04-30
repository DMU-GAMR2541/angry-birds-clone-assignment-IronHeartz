#pragma once
#include "DynamicObject.h"

class Bird : public DynamicObject {
public:
	Bird() = default;

	Bird(std::string PigSpriteLocation, b2World World) : DynamicObject(PigSpriteLocation, World) {};
};
