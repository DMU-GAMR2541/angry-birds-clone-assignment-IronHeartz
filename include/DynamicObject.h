#pragma once
#include "GameObject.h"

class DynamicObject : public GameObject {
public:
	DynamicObject() = default; //A destructor
	DynamicObject(std::string ObjConstructor, b2Vec2 SprPosition, b2World& World); //this is how we override the dynamic object. A constructor
	void update() override {};
	void render(sf::RenderWindow& GO_window) override;
	void UpdateSprite();
	void Impluse(b2Vec2 ImpluseForce, bool Awake) 
	{
		b2_Body->ApplyLinearImpulseToCenter(ImpluseForce, Awake);
	}
	void setPosition(b2Vec2 ResetPos, float Angle) { b2_Body->SetTransform(ResetPos, Angle); }; //Set positiopn back to start or anywhere for any dynamic object
	void setVelocity(b2Vec2 ResetVel) { b2_Body->SetLinearVelocity(ResetVel); };                //Setting velocity

	void setLocation(b2Vec2 b2_loc)
	{
		b2_Body->SetTransform(b2_loc, 0);
		ObjSprite.setPosition(sf::Vector2f(b2_loc.x * SCALE, b2_loc.y * SCALE));
	}

private:
	sf::Sprite ObjSprite; //The sprite
	sf::Texture ObjTexture; //The texture/image
	std::string TextureLocation; //File location
	//sf::RenderWindow ObjWindow;
	b2Vec2 b2_Pos; //Position of pig
	b2BodyDef b2_BodyDef; //Body definition for the object in box2d physics engine
	b2FixtureDef b2_FixtureDef; //fixture definition for the object in box2d physics engine
	//b2Body* b2_Body; //The body for the object
	b2CircleShape b2_dynamicCircle; //The shape of the object, defined as a circle

protected:
	b2Body* b2_Body;
};

//sprite, texture, string (location), get sprite, render