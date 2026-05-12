#include "DynamicObject.h"

DynamicObject::DynamicObject(std::string ObjConstructor, sf::IntRect SprSize, b2World& World)
{
	//Don't forget to name the variables in the brackets so it nows what we're doing
	TextureLocation = ObjConstructor;
	
	if (!ObjTexture.loadFromFile(TextureLocation, SprSize)) { //if the sprite isn't loaded
		std::cout << "Not loaded" << std::endl;
	}

	ObjSprite.setTexture(ObjTexture);
	ObjSprite.setPosition(sf::Vector2f(200.0f, 200.0));
    ObjSprite.setOrigin(ObjSprite.getLocalBounds().getSize().x / 2, ObjSprite.getLocalBounds().getSize().y /2); //Setting the collider to be the centre of the sprite

    //produce an object in Box2D
    b2_BodyDef.type = b2_dynamicBody;
    b2_BodyDef.position.Set(ObjSprite.getPosition().x / SCALE, ObjSprite.getPosition().y / SCALE); //orignally in pixels, divide to scale

    //Create the body in the world
    b2_Body = World.CreateBody(&b2_BodyDef);
    b2_dynamicCircle.m_radius = ObjSprite.getLocalBounds().getSize().x / 2 / SCALE; //15 pixels wide, ObjectLocalBounds to get the relative size of sprite

    //Set up fixtures
    b2_FixtureDef.shape = &b2_dynamicCircle;
    b2_FixtureDef.density = 1.0f;
    b2_FixtureDef.friction = 0.3f;
    b2_FixtureDef.restitution = 0.5f;

    //Attach to body
    b2_Body->CreateFixture(&b2_FixtureDef);
}

void DynamicObject::render(sf::RenderWindow& GameWindow)
{
	GameWindow.draw(ObjSprite);
}

void DynamicObject::UpdateSprite()
{
    ObjSprite.setPosition(sf::Vector2f(b2_Body->GetPosition().x * SCALE, b2_Body->GetPosition().y * SCALE)); //The position of the sprite is equal to this
	//ObjSprite.setPosition(SpriteUpd);                                                                      //Update from the body as it moves
}
