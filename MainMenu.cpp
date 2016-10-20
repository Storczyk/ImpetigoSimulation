#include "MainMenu.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::ShowMainMenu()
{
	sf::RenderWindow MainMenu(sf::VideoMode(1280, 1024), "Symulacja Liszaja");
	while (MainMenu.isOpen())
	{
		sf::Text text;
		sf::Font font;
		font.loadFromFile("font/font.ttf");
		text.setFont(font);
		text.setString("string");
		sf::Event event;
		while (MainMenu.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				MainMenu.close();

		} 
		MainMenu.clear();
		MainMenu.draw(text);
		MainMenu.display();
	}
}