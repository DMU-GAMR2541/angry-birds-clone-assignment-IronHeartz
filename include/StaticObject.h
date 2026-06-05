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

//class StaticImage : public virtual GameObject{
//public:
//	StaticImage() = default;
//	~StaticImage() = default;
//
//	StaticImage(const std::string ImageTxt, const std::string GameWindow);
//
//private:
//	sf::Texture ImageTexture;
//	sf::Sprite ImageSprite;
//	sf::String GameWindow;
//};