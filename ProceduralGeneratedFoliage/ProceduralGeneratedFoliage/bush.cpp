#include "bush.h"

bush::bush() {}

void bush::GrowBush(sf::Vector2f startingPos_i, Density density_i, Color color_i) {
	startingPos = startingPos_i;
	DensityOfBush = density_i;
	ColorOfBush = color_i;

	FoliageSetup();
}

void bush::FoliageSetup() {
	srand(time(NULL));
	NumOfFoliages = rand() % 4 + 2;
	
	cout << "NumOfFoliages: " << NumOfFoliages << endl;

	for (int i = 0; i < NumOfFoliages; ++i) {
		sf::Vector2f newPos = GenerateStartingPos();
		
		cout << "this foliage growing from x: " << newPos.x << " y: " << newPos.y << endl;
		
		int height = GenerateRandomHeight();
		float updatedAngle = GenerateRandomAngle();
		sf::Color color = GetColor();

		foliage newFoliage(height, "F", sf::Vector2f(10, 1), newPos, -90.0f, updatedAngle, color);
		newFoliage.GrowFoliage();
		myBush.push_back(newFoliage);
	}
}

sf::Vector2f bush::GenerateStartingPos() {
	float width = startingPos.x + (rand() % 200 - 100);
	float height = startingPos.y + (rand() % 90 - 45);

	return sf::Vector2f(width, height);
}

float bush::GenerateRandomAngle() {
	float angle = 25;

	switch (DensityOfBush) {
	case LOW:
		angle = rand() % 5 + 25;
		break;
	case MEDIAM:
		angle = rand() % 5 + 20;
		break;
	case HIGH:
		angle = rand() % 5 + 15;
		break;
	}

	return angle;
}
int bush::GenerateRandomHeight() {
	return (rand() % 3 + 2);
}

sf::Color bush::GetColor() {
	switch (ColorOfBush) {
	case RED:
		return GenerateRandomRedBasedColor();
	case GREEN:
		return GenerateRandomGreenBasedColor();
	case BLUE:
		return GenerateRandomBlueBasedColor();
	}
}
sf::Color bush::GenerateRandomRedBasedColor() {
	sf::Color newColor;
	
	int r = rand() % 4 + 1;
	r = 155 + r * 20;
	int g = rand() % 100;
	int b = rand() % 100;
	
	newColor = sf::Color(sf::Uint8(r), sf::Uint8(g), sf::Uint8(b));
	return newColor;
}
sf::Color bush::GenerateRandomGreenBasedColor() {
	sf::Color newColor;

	int g = rand() % 4 + 1;
	g = 155 + g * 20;
	int r = rand() % 150;
	int b = rand() % 150;

	newColor = sf::Color(sf::Uint8(r), sf::Uint8(g), sf::Uint8(b));
	return newColor;
}
sf::Color bush::GenerateRandomBlueBasedColor() {
	sf::Color newColor;

	int b = rand() % 4 + 1;
	b = 155 + b * 20;
	int g = rand() % 150;
	int r = rand() % 150;

	newColor = sf::Color(sf::Uint8(r), sf::Uint8(g), sf::Uint8(b));
	return newColor;
}

void bush::clear() {
	sf::Vector2f startingPos = sf::Vector2f(0, 0);
	NumOfFoliages = 0;
	myBush.clear();
}
