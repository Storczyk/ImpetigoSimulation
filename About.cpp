#include "About.h"


About::About()
{
	bgTexture.loadFromFile("imgs/about_bg.png");
	background.setTexture(bgTexture);
	sf::RenderWindow window;
	window.create(sf::VideoMode(500, 500), "O programie", sf::Style::Titlebar);
	window.setFramerateLimit(30);
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
			window.clear();
			window.draw(background);
			window.display();
		}
	}
}

