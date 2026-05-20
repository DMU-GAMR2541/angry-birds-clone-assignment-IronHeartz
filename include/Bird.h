#pragma once
#include "DynamicObject.h"

class Bird : public DynamicObject {
public:
	Bird() = default;

	Bird(std::string BirdSpriteLocation, b2Vec2 BirdPosition, b2World& World) : DynamicObject(BirdSpriteLocation, BirdPosition, World) {};
};

