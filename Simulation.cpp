#include "Simulation.h"
Simulation::Simulation()
{
	TabArray = NULL;
	settings = NULL;
	arraySize = 0;
	cycle = 1;

}

void Simulation::SimulationMain(SimulationSettings & settings, sf::Music & music)
{

	window.create(sf::VideoMode(1280, 850), "Symulacja Liszaja", sf::Style::Titlebar);
	window.setFramerateLimit(30);

	LoadMedia();
	isMusicPlaying(music, true);

	this->settings = &settings;
	this->arraySize = this->settings->GetSetting(1);

	char SimulationState = 'P';

	MakeArray();
	StateFirst();
	sf::Clock zegar;
	zegar.restart();
	updateSettings();

	while (window.isOpen())
	{

		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::Event event;
		for (int i = 0; i < 6; i++)
			button[i].MouseHover(mousePos, button[i].getGlobalBounds());

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				CleanUp();
				window.close();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				CleanUp();
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (InfectWhenClicked(mousePos)) {}
					else if (button[0].contains(mousePos))
					{
						SimulationState = 'S';
						button[0].clicked();
					}
					else if (button[1].contains(mousePos))
					{
						SimulationState = 'P';
						button[1].clicked();
					}
					else if (button[2].contains(mousePos))
						Reset();
					else if (button[3].contains(mousePos))
					{
						window.setVisible(false);
						SimulationState = 'P';
						settings.SimulationSettingsMenu();
						window.setVisible(true);
						updateSettings();
					}
					else if (button[4].contains(mousePos))
						isMusicPlaying(music);
					else if (button[5].contains(mousePos))
					{
						CleanUp();
						window.close();
					}
				}
			}
		}
		if (!window.isOpen())
			break;
		if (SimulationState == 'S')
		{
			button[0].clicked(true);
			button[1].clicked(false);
			if (dlugoscCyklu >= 100 && dlugoscCyklu <= 2000)
			{
				sf::Time t = (zegar.getElapsedTime());

				if (t.asMilliseconds() >= (float)dlugoscCyklu)
				{
					zegar.restart();
					cycle += 1;
					updateState();
				}
			}
		}
		else
		{
			button[0].clicked(false);
			button[1].clicked(true);
		}
		window.clear();
		window.draw(background);
		st = "Cykl " + std::to_string(this->cycle);
		cycleText.setString(st);

		window.draw(background);
		window.draw(cycleText);
		for (int i = 0; i < 6; i++)
			window.draw(button[i]);
		drawing();
		window.display();
	}

}
void Simulation::StateFirst()
{
	TabArray[(int)(this->arraySize / 2) - 1][(int)(this->arraySize / 2) - 1].ChangeState(2);
}

void Simulation::updateSettings()
{
	this->SzUodpornienie = this->settings->GetSetting(2);
	this->SzUzdrowienie = this->settings->GetSetting(3);
	this->SzZainfekowanie = this->settings->GetSetting(4);
	this->czasUodpornienia = this->settings->GetSetting(5);
	this->czasOdpornosci = this->settings->GetSetting(6);
	this->dlugoscCyklu = this->settings->GetSetting(7);
}

int Simulation::randomNumber()
{
	return (rand() % (100) + 1);
}

void Simulation::Reset()
{
	for (int i = 0; i < arraySize; i++)
		for (int j = 0; j < arraySize; j++)
			TabArray[i][j].ChangeState(1);
	StateFirst();
	cycle = 1;

}

bool Simulation::InfectWhenClicked(sf::Vector2i mPos)
{
	sf::FloatRect rect;
	rect.top = rect.left = 10;
	rect.width = rect.height = arraySize * 10;
	rect.height = rect.height - 10;
	if (rect.contains((float)mPos.x, (float)mPos.y))
	{
		TabArray[(int)(mPos.y / 10)][(int)(mPos.x / 10)].ChangeState(2);
		return true;
	}
	return false;
}

void Simulation::LoadMedia()
{
	font.loadFromFile("font/Sansita-Italic.ttf");
	sf::String str[6] = { L"Start", L"Pause",L"Restart", L"Ustawienia", L"Muzyka", L"Powrot" };
	cycleText.setFont(font);
	cycleText.setFillColor(sf::Color::White);
	cycleText.setPosition(900.f, 50.f);
	cycleText.setCharacterSize(60);
	float y = 150.f;
	for (int i = 0; i < 6; i++)
	{
		button[i].LoadButtonNormal();
		button[i].setPosition(900.f, y);
		button[i].LoadMenu(str[i]);
		y += 100.f;
	}
	bgTexture.loadFromFile("imgs/simulation_bg.png");
	background.setTexture(bgTexture);
}

void Simulation::isMusicPlaying(sf::Music &music, bool first)
{
	if (first == true)
	{
		if (sf::Music::Status::Playing == music.getStatus())
			button[4].LoadMenu(L"Music ON");
		else button[4].LoadMenu(L"Music OFF");
		return;
	}
	if (sf::Music::Status::Playing == music.getStatus())
	{
		button[4].LoadMenu(L"Music OFF");
		music.stop();
	}
	else
	{
		button[4].LoadMenu(L"Music ON");
		music.openFromFile("sounds/bg1.ogg");
		music.play();
	}
}

void Simulation::drawing()
{
	if (TabArray == NULL)
		return;
	int n = this->arraySize;
	int dlugoscStanuZarazenia = settings->GetSetting(5);
	int dlugoscStanuOdpornosci = settings->GetSetting(6);
	int stan, dlStanu;
	float x = 0.f, y = 10.f;
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			stan = TabArray[i][j].retur(1);
			x += 10.f;
			TabArray[i][j].setPosition(x, y);
			if (stan == 1)
			{
				window.draw(TabArray[i][j]);
			}
			if (stan == 2)
			{
				window.draw(TabArray[i][j]);
			}
			if (stan == 3)
			{
				window.draw(TabArray[i][j]);
			}
		}
		y += 10.f;
		x = 0.f;
	}
}

void Simulation::updateState()
{
	srand(time(NULL));
	int n = this->settings->GetSetting(1);

	updateSettings();
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			switch (TabArray[i][j].retur(1))
			{
			case 1:
				break;
			case 2://czy komorka nie zostala zmieniona juz w danym cyklu
				if (TabArray[i][j].retur(3) == 0)
				{
					if (TabArray[i][j].retur(2) >= czasUodpornienia && randomNumber() <= SzUodpornienie)
					{
						TabArray[i][j].ChangeState(3);
					}
					else
					{
						TabArray[i][j].StateUp();
						//zarazenie komorek innych
						//gorna
						if (TabArray[i - 1][j].retur(1) == 1 && randomNumber() <= SzZainfekowanie)
						{
							TabArray[i - 1][j].blokChange(1);
							TabArray[i - 1][j].ChangeState(2);
						}
						//prawa
						if (TabArray[i][j + 1].retur(1) == 1 && randomNumber() <= SzZainfekowanie)
						{
							TabArray[i][j + 1].blokChange(1);
							TabArray[i][j + 1].ChangeState(2);
						}
						//dolna
						if (TabArray[i + 1][j].retur(1) == 1 && randomNumber() <= SzZainfekowanie)
						{
							TabArray[i + 1][j].blokChange(1);
							TabArray[i + 1][j].ChangeState(2);
						}
						//lewa
						if (TabArray[i][j - 1].retur(1) == 1 && randomNumber() <= SzZainfekowanie)
						{
							TabArray[i][j - 1].blokChange(1);
							TabArray[i][j - 1].ChangeState(2);
						}
						//lewa gorna
						if (TabArray[i - 1][j - 1].retur(1) == 1 && randomNumber() <= SzZainfekowanie)
						{
							TabArray[i - 1][j - 1].blokChange(1);
							TabArray[i - 1][j - 1].ChangeState(2);
						}
						//prawa gorna
						if (TabArray[i - 1][j + 1].retur(1) == 1 && randomNumber() <= SzZainfekowanie)
						{
							TabArray[i - 1][j + 1].blokChange(1);
							TabArray[i - 1][j + 1].ChangeState(2);
						}
						//lewa dolna
						if (TabArray[i + 1][j - 1].retur(1) == 1 && randomNumber() <= SzZainfekowanie)
						{
							TabArray[i + 1][j - 1].blokChange(1);
							TabArray[i + 1][j - 1].ChangeState(2);
						}
						//prawa dolna
						if (TabArray[i + 1][j + 1].retur(1) == 1 && randomNumber() <= SzZainfekowanie)
						{
							TabArray[i + 1][j + 1].blokChange(1);
							TabArray[i + 1][j + 1].ChangeState(2);
						}
					}
				}

				break;
			case 3:
				if (TabArray[i][j].retur(2) >= czasOdpornosci && randomNumber() <= SzUzdrowienie)
				{
					TabArray[i][j].ChangeState(1);
				}
				else
				{
					TabArray[i][j].StateUp();
				}
				break;
			}
		}
	}
	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j < n - 1; j++)
			TabArray[i][j].blokChange(0);
}

void Simulation::MakeArray()
{

	int n = this->arraySize;
	this->TabArray = new Point*[n];
	for (int i = 0; i < n; i++)
		TabArray[i] = new Point[n];
}

void Simulation::CleanUp()
{
	if (TabArray)
	{
		int n = this->arraySize;
		for (int i = 0; i < n; i++)
			delete[] TabArray[i];
		delete[] TabArray;
	}
}
