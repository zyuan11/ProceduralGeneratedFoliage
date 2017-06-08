#pragma once
#include "config.h"

class UserInterface {
public:
	std::vector<sf::RectangleShape> Drawable;

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

	void AddToDrawable();
};
