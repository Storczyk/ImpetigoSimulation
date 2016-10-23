#include "Button.h"

Button::Button() 
{
	LoadButton();
}

void Button::LoadButton()
{
	ButtonTexture.loadFromFile("imgs/normal_button.png");
	button.setTexture(ButtonTexture);
}

bool Button::contains(sf::Vector2i mousePosition)
{
	sf::FloatRect pos = this->getGlobalBounds();
	if (pos.contains((float)mousePosition.x, (float)mousePosition.y))
		return true;
	else
		return false;
}
