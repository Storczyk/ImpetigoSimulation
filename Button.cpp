#include "Button.h"

Button::Button() 
{
	isHover = false;
	font.loadFromFile("font/Sansita-Italic.ttf");
}

void Button::LoadButtonNormal()
{
	ButtonTextureNormal.loadFromFile("imgs/normal_button.png");
	ButtonTextureHover.loadFromFile("imgs/hover_button.png");
	ButtonTextureClicked.loadFromFile("imgs/clicked_button.png");
	button.setTexture(ButtonTextureNormal);
}

void Button::clicked(bool st)
{
	if (st == true)
	{
		button.setTexture(ButtonTextureClicked);
		return;
	}
	else
	{
		button.setTexture(ButtonTextureNormal);
		return;
	}
		
}

void Button::LoadButtonSettings()
{
	ButtonTextureNormal.loadFromFile("imgs/settings_button.png");
	button.setTexture(ButtonTextureNormal);
}

void Button::LoadMenu(sf::String buttonTexts, sf::Color color, float swap )
{
	sf::FloatRect textRect, buttonRect;
	buttonText.setCharacterSize(30);
	buttonText.setFont(font);
	buttonText.setString(buttonTexts);
	buttonText.setFillColor(color);
	textRect = buttonText.getGlobalBounds();
	buttonRect = button.getGlobalBounds();
	buttonText.setPosition(buttonRect.left + (buttonRect.width / 2.f) - (textRect.width / 2.f) + swap,
		buttonRect.top + buttonRect.height / 2.f - textRect.height / 1.5f);
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
