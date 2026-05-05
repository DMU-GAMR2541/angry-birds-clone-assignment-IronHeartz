#pragma once
#include "GameObject.h"

class DynamicObject : public GameObject {
public:
	DynamicObject() = default; //A destructor
	DynamicObject(std::string ObjConstructor, sf::IntRect SprSize, sf::Vector2f SprPosition, b2World& World); //this is how we override the dynamic object. A constructor

	void update() override {};
	void render(sf::RenderWindow& GO_window) override;
	void UpdateSprite();

private:
	sf::Sprite ObjSprite; //The sprite
	sf::Texture ObjTexture; //The texture/image
	std::string TextureLocation; //File location
	sf::RenderWindow ObjWindow;
	b2Vec2 b2_Pos; //Position of pig
	b2BodyDef b2_BodyDef; //Body definition for the object in box2d physics engine
	b2FixtureDef b2_FixtureDef; //fixture definition for the object in box2d physics engine
	b2Body* b2_Body; //The body for the object
	b2CircleShape b2_dynamicCircle; //The shape of the object, defined as a circle
};

//sprite, texture, string (location), get sprite, render