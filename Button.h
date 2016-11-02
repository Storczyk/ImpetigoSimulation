#pragma once
#include <SFML\Graphics.hpp>
class Button : public sf::Drawable
{
	sf::Texture ButtonTextureNormal;
	sf::Texture ButtonTextureHover;
	sf::Texture ButtonTextureClicked;
	sf::Text buttonText;
	sf::Sprite button;
	sf::Font font;
	bool isHover;
public:
	Button();
	~Button(){}
	void setPosition(float x, float y) {
		button.setPosition(x, y);
	}
	sf::FloatRect getGlobalBounds() { return button.getGlobalBounds(); }
	void LoadButtonSettings();
	void LoadMenu(sf::String buttonText, sf::Color color = sf::Color::White, float swap = 0.f);
	void MouseHover(sf::Vector2i mousePos, sf::FloatRect rect);
	void LoadButtonNormal();
	void clicked(bool st=false);
	bool contains(sf::Vector2i rect);
	void sf::Drawable::draw(sf::RenderTarget & window, sf::RenderStates states) const { window.draw(button);
	window.draw(buttonText);
	}
};