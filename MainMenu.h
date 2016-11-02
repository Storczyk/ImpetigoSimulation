#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Simulation.h"
#include "SimulationSettings.h"
#include "About.h"
#include <SFML\Audio.hpp>
class MainMenu
{
	sf::RenderWindow window;
	sf::Font font;
	Button button[5];
	sf::Text buttonText[5];
	sf::Texture bgTexture;
	sf::Sprite background;
	sf::Music music;

	bool isMusicOn;
	Simulation simulation;
	SimulationSettings simulationSettings;
public: 
	MainMenu();
	~MainMenu() {};
	void ShowMainMenu();
	void LoadMedia();
	void musicStart();
};