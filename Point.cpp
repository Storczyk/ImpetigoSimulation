#include "point.h"

Point::Point()
{
	t1.loadFromFile("imgs/p_healthy.png");
	t2.loadFromFile("imgs/p_infected.png");
	t3.loadFromFile("imgs/p_immune.png");
	state = 1;
	stateSprite.setTexture(t1);
	//1-zdrowa
	//2-zarazona
	//3-odporna
	blok = 0;
	stateLength = 1;
}

void Point::ChangeState(int newState)
{
	this->state = newState;
	if (newState == 1)
	{
		stateLength = 1;
		stateSprite.setTexture(t1);
	}
	if (newState == 2)
	{
		stateLength = 1;
		stateSprite.setTexture(t2);
	}
	if (newState == 3)
	{
		stateLength = 1;
		stateSprite.setTexture(t3);
	}
}

int Point::retur(int what)
{
	switch (what)
	{
	case 1: return this->state;
	case 2: return this->stateLength;
	case 3: return this->blok;
	}
}

void Point::StateUp()
{
	this->stateLength = this->stateLength + 1;
}

void Point::blokChange(int to)
{
	this->blok = to;
}
