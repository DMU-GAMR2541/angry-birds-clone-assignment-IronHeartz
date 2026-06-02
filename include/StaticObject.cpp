#include "StaticObject.h"

StaticObject::StaticObject(sf::Vector2f position, std::string UIText, std::string fontLocation)
{
	if (!font.loadFromFile(fontLocation))
	{
		std::cout << "Error loading text/font" << std::endl;
	}
	else 
	{
		text.setFont(font);
		text.setString(UIText);
		text.setPosition(position);
	}
}

void StaticObject::update()
{
}

void StaticObject::render(sf::RenderWindow& GO_window)
{
	GO_window.draw(text);
}
