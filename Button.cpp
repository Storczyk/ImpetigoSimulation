#include "Button.h"

Button::Button() 
{
	isHover = false;
}

void Button::LoadButtonNormal()
{
	ButtonTextureNormal.loadFromFile("imgs/normal_button.png");
	ButtonTextureHover.loadFromFile("imgs/hover_button.png");
	button.setTexture(ButtonTextureNormal);
}

void Button::LoadButtonSettings()
{
	ButtonTextureNormal.loadFromFile("imgs/settings_button.png");
	button.setTexture(ButtonTextureNormal);
}

void Button::LoadMenu(sf::Text* texts)
{

}

void Button::MouseHover(sf::Vector2i mousePos, sf::FloatRect rect)
{
	if (!rect.contains((float)mousePos.x, (float)mousePos.y) && isHover)
	{
		isHover = false;
		button.setTexture(ButtonTextureNormal);		
	}
	if (rect.contains((float)mousePos.x, (float)mousePos.y) && !isHover)
	{
		isHover = true;
		button.setTexture(ButtonTextureHover);
	}
}

bool Button::contains(sf::Vector2i mousePosition)
{
	sf::FloatRect pos = this->getGlobalBounds();
	if (pos.contains((float)mousePosition.x, (float)mousePosition.y))
		return true;
	else
		return false;
}
