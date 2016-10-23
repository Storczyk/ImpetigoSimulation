#include "MainMenu.h"
#include "SFML\Window.hpp"
MainMenu::MainMenu()
{
	window.create(sf::VideoMode(768, 768), "Symulacja Liszaja", sf::Style::Titlebar);
	window.setFramerateLimit(60);
	LoadMedia();
	ShowMainMenu();
}

void MainMenu::LoadMedia()
{
	font.loadFromFile("font/font.ttf");
	buttonText[0].setString(L"Start symulacji");
	buttonText[1].setString(L"Ustawienia Symulacji");
	buttonText[2].setString(L"Ustawienia Graficzne");
	buttonText[3].setString(L"Muzyka ON");
	buttonText[4].setString(L"Wyjscie");
	float y = 50.f;
	for (int i = 0; i < 5; i++)
	{
		buttonText[i].setFont(font);
		buttonText[i].setCharacterSize(30);
		button[i].setPosition(250.f, y);

		sf::FloatRect textRect, buttonRect;
		textRect = buttonText[i].getGlobalBounds();
		buttonRect = button[i].getGlobalBounds();
		
		buttonText[i].setPosition(buttonRect.left + (buttonRect.width / 2.f) - (textRect.width / 2.f),
			buttonRect.top + buttonRect.height / 2.f - textRect.height / 1.5f);
		y += 150.f;
	}
}

void MainMenu::ShowMainMenu()
{
	while (window.isOpen())
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
			if (event.type == sf::Event::MouseButtonReleased && event.MouseLeft)
			{
				for (int i = 0; i < 5; i++)
				{
					if(button[i].contains)
				}
			}
		} 
		window.clear();
		for (int i = 0; i < 5; i++)
		{
			window.draw(button[i]);
			window.draw(buttonText[i]);
		}

		window.display();
	}
}