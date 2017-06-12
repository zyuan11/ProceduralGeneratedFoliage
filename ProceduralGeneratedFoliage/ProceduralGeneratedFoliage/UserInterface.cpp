#include "UserInterface.h"

UserInterface::UserInterface() {
	backgroundSetup();
	InfoSetup();
	BarSetup();
	SelectSetup();
	
	currDensity = MEDIAM;
	currDirection = MIDDLE;
	currColor = GREEN;
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
	DensitySelect.setPosition(DENSITY_SELECT_MEDIAM_POS);
	DensitySelect.setFillColor(SELECT_COLOR);
	DensitySelect.setOutlineColor(SELECT_OUTLINE_COLOR);
	
	DirectionSelect.setSize(SELECT_SIZE);
	DirectionSelect.setOutlineThickness(SELECT_OUTLINE_THINKNESS);
	DirectionSelect.setPosition(DIRECTION_SELECT_MIDDLE_POS);
	DirectionSelect.setFillColor(SELECT_COLOR);
	DirectionSelect.setOutlineColor(SELECT_OUTLINE_COLOR);

	ColorSelect.setSize(SELECT_SIZE);
	ColorSelect.setOutlineThickness(SELECT_OUTLINE_THINKNESS);
	ColorSelect.setPosition(COLOR_SELECT_GREEN_POS);
	ColorSelect.setFillColor(SELECT_COLOR);
	ColorSelect.setOutlineColor(SELECT_OUTLINE_COLOR);
}

Arrow UserInterface::isUpdatingDensity(sf::Vector2f cursorPos) {
	if ((cursorPos.y <= DENSTIY_SELECT_HEIGHT + 20) && (cursorPos.y >= DENSTIY_SELECT_HEIGHT - 20)) {
		if (cursorPos.x > DensitySelect.getPosition().x)
			return GoRight;
		else
			return GoLeft;
	}
	else
		return Stay;
}
void UserInterface::UpdateDensity(sf::Vector2f cursorPos) {
	Arrow dir_i = isUpdatingDensity(cursorPos);

	switch (dir_i) {
	case Stay:
		break;
	case GoRight:
		switch (currDensity) {
		case LOW:
			currDensity = MEDIAM;
			break;
		case MEDIAM:
			currDensity = HIGH;
			break;
		case HIGH:
			break;
		}
		UpdateDensityUI();
		break;
	case GoLeft:
		switch (currDensity) {
		case LOW:
			break;
		case MEDIAM:
			currDensity = LOW;
			break;
		case HIGH:
			currDensity = MEDIAM;
			break;
		}
		UpdateDensityUI();
	}
}
void UserInterface::UpdateDensityUI() {
	switch (currDensity) {
	case LOW:
		DensitySelect.setPosition(DENSITY_SELECT_LOW_POS);
		break;
	case MEDIAM:
		DensitySelect.setPosition(DENSITY_SELECT_MEDIAM_POS);
		break;
	case HIGH:
		DensitySelect.setPosition(DENSITY_SELECT_HIGH_POS);
		break;
	}
}
Density UserInterface::GetCurrDensity() {
	return currDensity;
}

Arrow UserInterface::isUpdatingDirection(sf::Vector2f cursorPos) {
	if ((cursorPos.y <= DIRECTION_SELECT_HEIGHT + 20) && (cursorPos.y >= DIRECTION_SELECT_HEIGHT - 20)) {
		if (cursorPos.x > DirectionSelect.getPosition().x)
			return GoRight;
		else
			return GoLeft;
	}
	else
		return Stay;
}
void UserInterface::UpdateDirection(sf::Vector2f cursorPos) {
	Arrow dir_i = isUpdatingDirection(cursorPos);

	switch (dir_i) {
	case Stay:
		break;
	case GoRight:
		switch (currDirection) {
		case LEFT:
			currDirection = MIDDLE;
			break;
		case MIDDLE:
			currDirection = RIGHT;
			break;
		case RIGHT:
			break;
		}
		UpdateDirectionUI();
		break;
	case GoLeft:
		switch (currDirection) {
		case LEFT:
			break;
		case MIDDLE:
			currDirection = LEFT;
			break;
		case RIGHT:
			currDirection = MIDDLE;
			break;
		}
		UpdateDirectionUI();
	}
}
void UserInterface::UpdateDirectionUI() {
	switch (currDirection) {
	case LEFT:
		DirectionSelect.setPosition(DIRECTION_SELECT_LEFT_POS);
		break;
	case MIDDLE:
		DirectionSelect.setPosition(DIRECTION_SELECT_MIDDLE_POS);
		break;
	case RIGHT:
		DirectionSelect.setPosition(DIRECTION_SELECT_RIGHT_POS);
		break;
	}
}
Direction UserInterface::GetCurrDirection() {
	return currDirection;
}

Arrow UserInterface::isUpdatingColor(sf::Vector2f cursorPos) {
	if ((cursorPos.y <= COLOR_SELECT_HEIGHT + 20) && (cursorPos.y >= COLOR_SELECT_HEIGHT - 20)) {
		if (cursorPos.x > ColorSelect.getPosition().x)
			return GoRight;
		else
			return GoLeft;
	}
	else
		return Stay;
}
void UserInterface::UpdateColor(sf::Vector2f cursorPos) {
	Arrow dir_i = isUpdatingColor(cursorPos);

	switch (dir_i) {
	case Stay:
		break;
	case GoRight:
		switch (currColor) {
		case RED:
			currColor = GREEN;
			break;
		case GREEN:
			currColor = BLUE;
			break;
		case BLUE:
			break;
		}
		UpdateColorUI();
		break;
	case GoLeft:
		switch (currColor) {
		case RED:
			break;
		case GREEN:
			currColor = RED;
			break;
		case BLUE:
			currColor = GREEN;
			break;
		}
		UpdateColorUI();
	}
}
void UserInterface::UpdateColorUI() {
	switch (currColor) {
	case RED:
		ColorSelect.setPosition(COLOR_SELECT_RED_POS);
		break;
	case GREEN:
		ColorSelect.setPosition(COLOR_SELECT_GREEN_POS);
		break;
	case BLUE:
		ColorSelect.setPosition(COLOR_SELECT_BLUE_POS);
		break;
	}
}
Color UserInterface::GetCurrColor() {
	return currColor;
}

