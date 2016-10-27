#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
class Point : public sf::Drawable
{
	sf::Texture t1, t2, t3;
	sf::Sprite stateSprite;
	int state, stateLength, blok;
public:
	Point();
	~Point(){}
	void ChangeState(int newState);
	void setPosition(float x, float y) {
		stateSprite.setPosition(x, y);
	}
	int retur(int what);
	void StateUp();
	void blokChange(int newBlok);
	void sf::Drawable::draw(sf::RenderTarget & window, sf::RenderStates states) const {
		window.draw(stateSprite);
	}
};