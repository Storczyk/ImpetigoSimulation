#pragma once
#include "SimulationSettings.h"
#include "Point.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Button.h"
class Simulation
{
	int cycle;
	int arraySize;
	Point **TabArray;
	SimulationSettings *settings;
	sf::RenderWindow window;
	sf::Texture bgTexture;
	sf::Sprite background;
	sf::Font font;
	Button button[4];
	sf::Text cycleText;
	std::string st;
	void drawing();
	void updateState();
	void MakeArray();
	void CleanUp();
	void StateFirst();
	int randomNumber();
	void Reset();
	void DynamicModification(int before, int after);
	bool InfectWhenClicked(sf::Vector2i);
	void LoadMedia();
public:
	Simulation();
	~Simulation(){}
	void SimulationMain(SimulationSettings & settings);

};