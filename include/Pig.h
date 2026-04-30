#pragma once
#include "DynamicObject.h"

class Pig : public DynamicObject {
public:
	Pig() = default;

	//Pig(std::string PigSpriteLocation) : DynamicObject(PigSpriteLocation) {}; //pass the variable into dynamic object so we can use the objects elsewhere, and if extra stuff needed
	Pig(std::string PigSpriteLocation, b2World& World) : DynamicObject(PigSpriteLocation, World) {};
};
