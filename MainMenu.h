#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Simulation.h"
#include "SimulationSettings.h"
#include "GraphicSettings.h"
class MainMenu
{
	sf::RenderWindow window;
	sf::Font font;
	sf::Texture background;
	Button button[5];
	sf::Text buttonText[5];

	Simulation simulation;
	SimulationSettings simulationSettings;
	GraphicSettings graphicSettings;


public: 
	MainMenu();
	~MainMenu() {};
	void ShowMainMenu();
	void LoadMedia();

};