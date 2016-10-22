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