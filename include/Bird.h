#pragma once
#include "DynamicObject.h"
#include <iostream>
#include <list>

using namespace std;

class Bird : public DynamicObject {
public:
	Bird() = default;

	Bird(std::string BirdSpriteLocation, b2Vec2 BirdPosition, b2World& World) : DynamicObject(BirdSpriteLocation, BirdPosition, World) 
	{
		DynamicObject::getBody()->GetUserData().pointer = 100;
	};

protected:
	bool BirdCollision = false;
};

std::list < std::unique_ptr<Bird>> ls_birds;

