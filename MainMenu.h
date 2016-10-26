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
	Button button[5];
	sf::Text buttonText[5];
	sf::Texture bgTexture;
	sf::Sprite background;


	Simulation simulation;
	SimulationSettings simulationSettings;
	GraphicSettings graphicSettings;


public: 
	MainMenu();
	~MainMenu() {};
	void ShowMainMenu();
	void LoadMedia();

};