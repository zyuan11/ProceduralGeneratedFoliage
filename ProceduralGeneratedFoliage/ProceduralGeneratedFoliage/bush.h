#pragma once
#include "foliage.h"
#include "config.h"
class bush {
	sf::Vector2f startingPos;
	Density DensityOfBush;

	int NumOfFoliages;
	std::vector<sf::Vector2f> OriginPosOfFoliages;
public:
	std::vector<foliage> myBush;

	bush();
	void GrowBush(sf::Vector2f startingPos_i, Density density_i);
	void FoliageSetup();

	float GenerateRandomAngle();
	int GenerateRandomHeight();
	sf::Vector2f GenerateStartingPos();
};