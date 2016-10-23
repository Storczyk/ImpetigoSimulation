#include "SimulationSettings.h"
#include "SFML\Graphics.hpp"
SimulationSettings::SimulationSettings(sf::Font font)
{
	this->font = font;
	LoadMedia();
}

int SimulationSettings::GetSetting(int nr)
{
	switch (nr)
	{
	case 1: return this->ArraySize;
	case 2: return this->ImmuneChance;
	case 3: return this->HealChance;
	case 4: return this->InfectionChance;
	case 5: return this->ImmuneTime;
	case 6: return this->ResistanceTime;
	case 7: return this->CycleTime;
	}
}

void SimulationSettings::SimulationSettingsMenu()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(1024, 768), "Ustawienia Symulacji", sf::Style::Titlebar);
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
		}
		window.clear();
		for (int i = 0; i < 8; i++)
		{
			window.draw(buttonText[i]);
		}

		window.display();
	}

}

void SimulationSettings::LoadMedia()
{
	buttonText[0].setString(L"Rozmiar tablicy:");
	buttonText[1].setString(L"Szansa na uodpornienie komorki:");
	buttonText[2].setString(L"Szansa na uzdrowienie komorki:");
	buttonText[3].setString(L"Szansa na zainfekowanie komorki:");
	buttonText[4].setString(L"Dlugosc stanu zarazenia:");
	buttonText[5].setString(L"Dlugosc stanu odpornosci:");
	buttonText[6].setString(L"Dlugosc trwania jednego cyklu");
	buttonText[7].setString(L"Powrot");
	float y = 50.f;
	for (int i = 0; i < 8; i++)
	{
		float y = 50.f;
		buttonText[i].setFont(font);
		buttonText[i].setCharacterSize(30);
		buttonText[i].setPosition(250.f, y);
		y += 100.f;
	}
}

