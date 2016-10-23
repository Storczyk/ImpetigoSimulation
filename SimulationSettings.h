#pragma once
#include "Button.h"
class SimulationSettings
{
	int CycleTime;		 //dlugosc cyklu
	int InfectionChance; //szansa na zainfekowanie
	int ImmuneChance;	 //szansa na uodpornienie
	int HealChance;		 //szansa na uzdrowienie
	int ImmuneTime;		 //czas uodpornienia - czas potrzebny na przejscie z zainfekowanej na odporna
	int ResistanceTime;  //czas odpornosci - czas potrzebny na przejscie z odpornej na zdrowa
	int ArraySize;
	sf::Text buttonText[8];
	sf::Font font;
	
public:
	SimulationSettings() {};
	SimulationSettings(sf::Font);
	~SimulationSettings(){}
	int GetSetting(int nr);
	void SimulationSettingsMenu();
	void LoadMedia();
};