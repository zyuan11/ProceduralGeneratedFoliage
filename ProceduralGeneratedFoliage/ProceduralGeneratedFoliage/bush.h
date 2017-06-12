#pragma once
#include "foliage.h"
#include "config.h"
class bush {
	sf::Vector2f startingPos;
	Density DensityOfBush;
	Color ColorOfBush;
	Direction DirOfBush;

	int NumOfFoliages;

	sf::Color GenerateRandomRedBasedColor();
	sf::Color GenerateRandomGreenBasedColor();
	sf::Color GenerateRandomBlueBasedColor();
public:
	std::vector<foliage> myBush;

	bush();
	void GrowBush(sf::Vector2f startingPos_i, Density density_i, Color color_i, Direction dir_i);
	void FoliageSetup();

	int GenerateNumOfBush();
	int GenerateHeight();

	sf::Color GetColor();
	int GenerateRandomHeight();
	sf::Vector2f GenerateStartingPos();

	void clear();

	
};