#pragma once
#include "SimulationSettings.h"
#include "Point.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
class Simulation
{
	int cycle;
	int arraySize;
	Point **TabArray;
	SimulationSettings *settings;
public:
	Simulation();
	~Simulation(){}
	void SimulationMain(SimulationSettings & settings)

};