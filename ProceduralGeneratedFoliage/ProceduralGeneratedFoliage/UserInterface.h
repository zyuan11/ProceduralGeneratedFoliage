#pragma once
#include "config.h"

class UserInterface {
	Density currDensity;
	Direction currDirection;

	Arrow isUpdatingDensity(sf::Vector2f cursorPos);
	void UpdateDensityUI();

public:
	sf::RectangleShape background;
	
	sf::RectangleShape DensityInfo;
	sf::RectangleShape DirectionInfo;
	sf::RectangleShape ColorInfo;

	sf::RectangleShape DensityBar;
	sf::RectangleShape DirectionBar;
	sf::RectangleShape ColorBar;

	sf::RectangleShape DensitySelect;
	sf::RectangleShape DirectionSelect;
	sf::RectangleShape ColorSelect;

	UserInterface();
	void backgroundSetup();
	void InfoSetup();
	void BarSetup();
	void SelectSetup();

	void UpdateDensity(sf::Vector2f cursorPos);
	
	Density GetCurrDensity();
	Direction GetCurrDirect();


};
