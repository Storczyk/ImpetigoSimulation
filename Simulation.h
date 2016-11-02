#pragma once
#include "SimulationSettings.h"
#include "Point.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>
#include "Button.h"
class Simulation
{
	int cycle;
	int arraySize;
	int dlugoscCyklu;
	int SzUodpornienie;
	int SzUzdrowienie;
	int SzZainfekowanie;
	int czasUodpornienia;
	int czasOdpornosci;

	Point **TabArray;
	SimulationSettings *settings;
	sf::RenderWindow window;
	sf::RectangleShape recShape;
	sf::Texture bgTexture;
	sf::Sprite background;
	sf::Font font;
	Button button[6];
	sf::Text cycleText;
	std::string st;
	void drawing();
	void updateState();
	void MakeArray();
	void CleanUp();
	void StateFirst();
	int randomNumber();
	void Reset();
	bool InfectWhenClicked(sf::Vector2i);
	void LoadMedia();
	void updateSettings();
	void isMusicPlaying(sf::Music & music, bool first = false);
public:
	Simulation();
	~Simulation(){}
	void SimulationMain(SimulationSettings & settings, sf::Music & music);

};