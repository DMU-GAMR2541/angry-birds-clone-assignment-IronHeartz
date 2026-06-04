#pragma once
#include <iostream>
#include "GameObject.h"

class StaticObject : public virtual GameObject {
public:
	StaticObject() = default;
	~StaticObject() = default;

	StaticObject(sf::Vector2f position, std::string text, std::string fontLocation);

	void update() override; //pure virtual function. Needs to be overriden when inherited
	void render(sf::RenderWindow& GO_window) override;

	sf::Text GetText()
	{
		return text;
	}

private:
	sf::Font font; //font of the text
	sf::Text text; //The text

};