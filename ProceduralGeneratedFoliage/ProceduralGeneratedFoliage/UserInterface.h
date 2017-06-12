#pragma once
#include "config.h"

class UserInterface {
	Density currDensity;
	Direction currDirection;
	Color currColor;

	Arrow isUpdatingDensity(sf::Vector2f cursorPos);
	void UpdateDensityUI();

	Arrow isUpdatingDirection(sf::Vector2f cursorPos);
	void UpdateDirectionUI();

	Arrow isUpdatingColor(sf::Vector2f cursorPos);
	void UpdateColorUI();

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

	sf::RectangleShape ClickToEdit;

	UserInterface();
	void backgroundSetup();
	void InfoSetup();
	void BarSetup();
	void SelectSetup();

	void UpdateDensity(sf::Vector2f cursorPos);
	void UpdateDirection(sf::Vector2f cursorPos);
	void UpdateColor(sf::Vector2f cursorPos);

	Density GetCurrDensity();
	Direction GetCurrDirection();
	Color GetCurrColor();


};
