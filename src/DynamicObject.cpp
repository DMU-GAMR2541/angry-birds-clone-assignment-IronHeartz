#include "DynamicObject.h"

DynamicObject::DynamicObject(std::string ObjConstructor)
{
	//Don't forget to name the variables in the brackets so it nows what we're doing
	TextureLocation = ObjConstructor;
	
	if (!ObjTexture.loadFromFile(TextureLocation, sf::IntRect(0, 0, 60, 52))) { //if the sprite isn't loaded
		std::cout << "Not loaded" << std::endl;
	}

	ObjSprite.setTexture(ObjTexture);
	ObjSprite.setPosition(sf::Vector2f(200.0, 200.0));

}

void DynamicObject::render(sf::RenderWindow& GameWindow)
{
	GameWindow.draw(ObjSprite);
}