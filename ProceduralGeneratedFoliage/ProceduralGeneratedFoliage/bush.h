#pragma once
#include "foliage.h"
#include "config.h"
class bush {
	sf::Vector2f startingPos;
	int NumOfFoliages;
	std::vector<sf::Vector2f> OriginPosOfFoliages;
public:
	std::vector<foliage> myBush;

	bush();
	void GrowBush(sf::Vector2f startingPos_i);
	void FoliageSetup();

	sf::Vector2f GenerateStartingPos();
};