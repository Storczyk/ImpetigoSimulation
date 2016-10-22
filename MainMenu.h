#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
class MainMenu
{
	sf::RenderWindow window;
	sf::Font font;
	sf::Texture background;
	Button button[5];
	sf::Text buttonText[5];
public: MainMenu();
		~MainMenu() {};
		void ShowMainMenu();
		void LoadMedia();

};