#pragma once
#include <SFML\Graphics.hpp>

class Point
{
	sf::Texture t1, t2, t3;
	sf::Sprite stateSprite;
	int state, stateLength, blok;
public:
	Point();
	~Point(){}
	void ChangeState(int newState);
	int retur(int what);
	void StateUp();
	void blokChange(int newBlok);

};