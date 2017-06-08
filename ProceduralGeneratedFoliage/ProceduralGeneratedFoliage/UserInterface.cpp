#include "UserInterface.h"

UserInterface::UserInterface() {
	backgroundSetup();
	InfoSetup();
	BarSetup();
	SelectSetup();
	AddToDrawable();
}

void UserInterface::backgroundSetup() {
	background.setPosition(sf::Vector2f(0, 0));
	background.setSize(sf::Vector2f(USERINTERFACE_WIDTH, WINDOW_HEIGHT));
	background.setFillColor(sf::Color(140, 140, 140));
}

void UserInterface::InfoSetup() {
	DensityInfo.setSize(INFO_SIZE);
	DensityInfo.setPosition(DENSITY_INFO_POS);
	
	DirectionInfo.setSize(INFO_SIZE);
	DirectionInfo.setPosition(DIRECTION_INFO_POS);

	ColorInfo.setSize(INFO_SIZE);
	ColorInfo.setPosition(COLOR_INFO_POS);
}

void UserInterface::BarSetup() {
	DensityBar.setSize(BAR_SIZE);
	DensityBar.setPosition(DENSITY_BAR_POS);
	DensityBar.setFillColor(BAR_COLOR);

	DirectionBar.setSize(BAR_SIZE);
	DirectionBar.setPosition(DIRECTION_BAR_POS);
	DirectionBar.setFillColor(BAR_COLOR);

	ColorBar.setSize(BAR_SIZE);
	ColorBar.setPosition(COLOR_BAR_POS);
	ColorBar.setFillColor(BAR_COLOR);
}

void UserInterface::SelectSetup() {
	DensitySelect.setSize(SELECT_SIZE);
	DensitySelect.setOutlineThickness(SELECT_OUTLINE_THINKNESS);
	DensitySelect.setPosition(DENSITY_SELECT_POS);
	DensitySelect.setFillColor(SELECT_COLOR);
	DensitySelect.setOutlineColor(SELECT_OUTLINE_COLOR);
	
	DirectionSelect.setSize(SELECT_SIZE);
	DirectionSelect.setOutlineThickness(SELECT_OUTLINE_THINKNESS);
	DirectionSelect.setPosition(DIRECTION_SELECT_POS);
	DirectionSelect.setFillColor(SELECT_COLOR);
	DirectionSelect.setOutlineColor(SELECT_OUTLINE_COLOR);

	ColorSelect.setSize(SELECT_SIZE);
	ColorSelect.setOutlineThickness(SELECT_OUTLINE_THINKNESS);
	ColorSelect.setPosition(COLOR_SELECT_POS);
	ColorSelect.setFillColor(SELECT_COLOR);
	ColorSelect.setOutlineColor(SELECT_OUTLINE_COLOR);
}

void UserInterface::AddToDrawable() {
	Drawable.push_back(background);
	Drawable.push_back(DensityBar);
	Drawable.push_back(DirectionBar);
	Drawable.push_back(ColorBar);
	Drawable.push_back(DensitySelect);
	Drawable.push_back(DirectionSelect);
	Drawable.push_back(ColorSelect);
}

