#pragma once
#include "DynamicObject.h"

class Bird : public DynamicObject {
public:
	Bird() = default;

	Bird(std::string BirdSpriteLocation, sf::IntRect SprSize, b2World& World) : DynamicObject(BirdSpriteLocation, SprSize, World) {};
};
