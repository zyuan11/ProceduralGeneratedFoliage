#include "bush.h"

bush::bush() {}

void bush::GrowBush(sf::Vector2f startingPos_i, Density density_i) {
	startingPos = startingPos_i;
	DensityOfBush = density_i;

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
		
		foliage newFoliage(height, "F", sf::Vector2f(10, 1), newPos, -90.0f, updatedAngle);
		newFoliage.GrowFoliage();
		myBush.push_back(newFoliage);
	}
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
	return (rand() % 4 + 2);
}

sf::Vector2f bush::GenerateStartingPos() {
	float width = startingPos.x + (rand() % 200 - 100);
	float height = startingPos.y + (rand() % 90 - 45);
	
	return sf::Vector2f(width, height);
}

void bush::clear() {
	sf::Vector2f startingPos = sf::Vector2f(0, 0);
	NumOfFoliages = 0;
	myBush.clear();
}