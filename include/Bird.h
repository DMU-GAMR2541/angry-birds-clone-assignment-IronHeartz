#pragma once
#include "DynamicObject.h"

class Bird : public DynamicObject {
public:
	Bird() = default;

	Bird(std::string BirdSpriteLocation, sf::IntRect SprSize, sf::Vector2f SprPosition, b2World& World) : DynamicObject(BirdSpriteLocation, SprSize, SprPosition, World) {};
};
