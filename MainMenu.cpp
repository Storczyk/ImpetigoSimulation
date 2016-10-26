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
	bgTexture.loadFromFile("imgs/mainmenu_bg.png");
	background.setTexture(bgTexture);
	
	sf::String str[5] = { L"Start symulacji",L"Ustawienia Symulacji", L"Ustawienia graficzne", L"Muzyka ON", L"Wyjscie" };
	float y = 50.f;
	for (int i = 0; i < 5; i++)
	{	
		button[i].LoadButtonNormal();
		button[i].setPosition(250.f, y);
		button[i].LoadMenu(str[i]);
		y += 150.f;
	}
}

void MainMenu::ShowMainMenu()
{
	while (window.isOpen())
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		
		for (int i = 0; i < 5; i++)
		{
			button[i].MouseHover(mousePos, button[i].getGlobalBounds());
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
			
			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (button[0].contains(mousePos))
					{

					}
					else if (button[1].contains(mousePos))
					{
						window.setVisible(false);
						this->simulationSettings.SimulationSettingsMenu();
						window.setVisible(true);
					}
					else if (button[4].contains(mousePos)) window.close();
				}
				
			}
		}
		window.clear();
		window.draw(background);
		for (int i = 0; i < 5; i++)
		{
			window.draw(button[i]);

			//window.draw(buttonText[i]);
		}

		window.display();
	}
}