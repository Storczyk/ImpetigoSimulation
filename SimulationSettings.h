#pragma once
#include "Button.h"
class SimulationSettings
{
	int CycleTime;		 //dlugosc cyklu
	int InfectionChance; //szansa na zainfekowanie
	int ImmuneChance;	 //szansa na uodpornienie
	int HealChance;		 //szansa na uzdrowienie
	int InfectedToImmuneTime;		 //czas uodpornienia - czas potrzebny na przejscie z zainfekowanej na odporna
	int ImmuneToInfectedTime;  //czas odpornosci - czas potrzebny na przejscie z odpornej na zdrowa
	int ArraySize;

	Button button[8];
	sf::Text buttonText[8];
	sf::Text buttonValue[7];
	sf::Font font;
	
public:
	SimulationSettings();
	~SimulationSettings(){}
	int GetSetting(int nr);
	void SimulationSettingsMenu();
	void LoadMedia();
	bool contains(sf::Vector2i mousePos, sf::FloatRect textPos);
};