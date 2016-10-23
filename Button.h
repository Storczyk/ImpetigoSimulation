#pragma once
#include <SFML\Graphics.hpp>
class Button : public sf::Drawable
{
	sf::Texture ButtonTexture;
	sf::Sprite button;
public:
	Button();
	~Button(){}
	void LoadButton();
	void setPosition(float x, float y) {
		button.setPosition(x, y);
	}
	sf::FloatRect getGlobalBounds() { return button.getGlobalBounds(); }
	bool contains(sf::Vector2i rect);
	void sf::Drawable::draw(sf::RenderTarget & window, sf::RenderStates states) const { window.draw(button); }
};