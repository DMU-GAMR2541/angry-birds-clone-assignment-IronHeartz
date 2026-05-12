#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "box2d/box2d.h"
#include <iostream>

class GameObject {
public:
	GameObject() = default;
	virtual void update() = 0; //pure virtual function. Needs to be overriden when inherited
	virtual void render(sf::RenderWindow& GO_window) = 0;

	//~GameObject() = default;

protected:
	const float SCALE = 30.0f; //Anything that inherits can access

};

