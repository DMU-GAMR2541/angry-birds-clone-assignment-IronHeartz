#pragma once
#include "DynamicObject.h"
#include <iostream>
#include <list>

class Pig : public DynamicObject {
public:
	Pig() = default;

	//Pig(std::string PigSpriteLocation) : DynamicObject(PigSpriteLocation) {}; //pass the variable into dynamic object so we can use the objects elsewhere, and if extra stuff needed
	Pig(std::string PigSpriteLocation, b2Vec2 PigPosition, b2World& World) : DynamicObject(PigSpriteLocation, PigPosition, World) 
	{
		DynamicObject::getBody()->GetUserData().pointer = 3; //Set the pigs data to 3 for the contact listener
	};

private:
	int PigHealth = 100;
	bool PigCollision = false;
	
};

std::list < std::unique_ptr<Pig>> ls_pigs; //Make list unique pointers