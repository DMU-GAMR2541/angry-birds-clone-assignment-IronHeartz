#pragma once
#include "GameObject.h"

class DynamicObject : public GameObject {
public:
	DynamicObject() = default; //A destructor
	DynamicObject(std::string ObjConstructor); //this is how we override the dynamic object. A constructor

	void update() override {};
	void render(sf::RenderWindow& GO_window) override;
	void UpdateSprite(sf::Vector2f SpriteUpd);

private:
	sf::Sprite ObjSprite; //The sprite
	sf::Texture ObjTexture; //The texture/image
	std::string TextureLocation; //File location
	sf::RenderWindow ObjWindow;
};

//sprite, texture, string (location), get sprite, render