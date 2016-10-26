#include "SimulationSettings.h"

SimulationSettings::SimulationSettings()
{
	LoadMedia();
	ArraySize = 100;
	ImmuneChance = 50;
	HealChance = 100;
	InfectionChance = 50;
	InfectedToImmuneTime = 6;
	ImmuneToInfectedTime = 4;
	CycleTime = 500;
}

int SimulationSettings::GetSetting(int nr)
{
	switch (nr)
	{
	case 1: return this->ArraySize;
	case 2: return this->ImmuneChance;
	case 3: return this->HealChance;
	case 4: return this->InfectionChance;
	case 5: return this->InfectedToImmuneTime;
	case 6: return this->ImmuneToInfectedTime;
	case 7: return this->CycleTime;
	}
}

void SimulationSettings::SimulationSettingsMenu()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(1024, 768), "Ustawienia Symulacji", sf::Style::Titlebar);
	window.setFramerateLimit(10);
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
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left) //zwiêkszanie
				{
					if (button[7].contains(mousePos))
						window.close();
					for (int i = 0; i < 7; i++)
					{
						sf::FloatRect bValPos = buttonValue[i].getGlobalBounds();
						if (this->contains(mousePos, bValPos))
						{
							switch (i)
							{
							case 0:
								if (this->ArraySize <= 1900) //rozmiar tablicy
									this->ArraySize += 100;
								break;
							case 1:
								if (this->ImmuneChance <= 95) //szansa na uodpornienie
									this->ImmuneChance += 5;
								break;
							case 2:
								if (this->HealChance <= 95) //szansa na uzdrowienie
									this->HealChance += 5;
								break;
							case 3:
								if (this->InfectionChance <= 95) //szansa na zainfekowania 
									this->InfectionChance += 5;
								break;
							case 4:
								if (this->InfectedToImmuneTime < 100) //czas uodprnienia - czas potrzebny na przejscie z zainfekowanej na odporna
									this->InfectedToImmuneTime += 1;
								break;
							case 5:
								if (this->ImmuneToInfectedTime < 100) //czas odpornosci - czas potrzebny na przejscie z odpornej na zdrowa
									this->ImmuneToInfectedTime += 1;
								break;
							case 6:
								if (this->CycleTime < 2000)
									this->CycleTime += 100;
								break;
							}
						}
					}
				}
				if (event.mouseButton.button == sf::Mouse::Button::Right) //zmniejszanie
				{
					for (int i = 0; i < 7; i++)
					{
						sf::FloatRect bValPos = buttonValue[i].getGlobalBounds();
						if (this->contains(mousePos, bValPos))
						{
							switch (i)
							{
							case 0:
								if (this->ArraySize > 200) //rozmiar tablicy
									this->ArraySize -= 100;
								break;
							case 1:
								if (this->ImmuneChance >= 5) //szansa na uodpornienie
									this->ImmuneChance -= 5;
								break;
							case 2:
								if (this->HealChance >= 5) //szansa na uzdrowienie
									this->HealChance -= 5;
								break;
							case 3:
								if (this->InfectionChance >= 5) //szansa na zainfekowania 
									this->InfectionChance -= 5;
								break;
							case 4:
								if (this->InfectedToImmuneTime > 1) //czas uodprnienia - czas potrzebny na przejscie z zainfekowanej na odporna
									this->InfectedToImmuneTime -= 1;
								break;
							case 5:
								if (this->ImmuneToInfectedTime > 1) //czas odpornosci - czas potrzebny na przejscie z odpornej na zdrowa
									this->ImmuneToInfectedTime -= 1;
								break;
							case 6:
								if (this->CycleTime > 100 )
									this->CycleTime -= 100;
								break;
							}
						}
					}
				}
			}
		}
		window.clear();
		for (int i = 0; i < 8; i++)
		{
			window.draw(button[i]);
			window.draw(buttonText[i]);
			if (i < 7)
			{
				buttonValue[i].setString(std::to_string(this->GetSetting(i + 1)));
				window.draw(buttonValue[i]);
			}
		}
		window.display();
	}

}

void SimulationSettings::LoadMedia()
{
	font.loadFromFile("font/Sansita-Italic.ttf");
	buttonText[0].setString(L"Rozmiar tablicy:");
	buttonText[1].setString(L"Szansa na uodpornienie komorki [%]:");
	buttonText[2].setString(L"Szansa na uzdrowienie komorki [%]:");
	buttonText[3].setString(L"Szansa na zainfekowanie komorki [%]:");
	buttonText[4].setString(L"Dlugosc stanu zarazenia [s]:");
	buttonText[5].setString(L"Dlugosc stanu odpornosci [s]:");
	buttonText[6].setString(L"Dlugosc trwania jednego cyklu [ms]:");
	buttonText[7].setString(L"Powrot");
	float y = 50.f;
	for (int i = 0; i < 8; i++)
	{
		buttonText[i].setFont(font);
		buttonText[i].setCharacterSize(30);
		button[i].setPosition(150.f, y);
		sf::FloatRect textRect, buttonRect;
		textRect = buttonText[i].getGlobalBounds();
		buttonRect = button[i].getGlobalBounds();
		buttonText[i].setPosition(buttonRect.left + (buttonRect.width / 2.f) - (textRect.width / 2.f),
			buttonRect.top + buttonRect.height / 2.f - textRect.height / 1.5f);
		if (i < 7)
		{
			buttonValue[i].setFont(font);
			buttonValue[i].setFillColor(sf::Color::Blue);
			buttonValue[i].setCharacterSize(30);
			buttonValue[i].setPosition(buttonRect.left + 550,
				buttonRect.top + buttonRect.height / 2.f - textRect.height / 1.5f);
		}
		y += 90.f;
	}
}

bool SimulationSettings::contains(sf::Vector2i mousePos, sf::FloatRect textPos)
{
	if (textPos.contains((float)mousePos.x, (float)mousePos.y))
		return true;
	else
		return false;
}
