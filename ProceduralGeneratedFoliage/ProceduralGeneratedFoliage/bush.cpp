#include "bush.h"

bush::bush() {}

void bush::GrowBush(sf::Vector2f startingPos_i) {
	startingPos = startingPos_i;
	FoliageSetup();
}

void bush::FoliageSetup() {
	srand(time(NULL));
	NumOfFoliages = rand() % 4 + 2;
	
	cout << "NumOfFoliages: " << NumOfFoliages << endl;

	for (int i = 0; i < NumOfFoliages; ++i) {
		sf::Vector2f newPos = GenerateStartingPos();
		
		cout << "this foliage growing from x: " << newPos.x << " y: " << newPos.y << endl;
		OriginPosOfFoliages.push_back(newPos);
		foliage newFoliage(3, "F", sf::Vector2f(10, 1), newPos, -90.0f, 25.0f);
		newFoliage.GrowFoliage();
		myBush.push_back(newFoliage);
	}
}

sf::Vector2f bush::GenerateStartingPos() {
	float width = startingPos.x + (rand() % 300 - 150);
	float height = startingPos.y + (rand() % 50 - 25);
	
	return sf::Vector2f(width, height);
}