#pragma once
#include "config.h"
#include "branch.h"
#include "LSystem.h"

class foliage {
	int height;
	string mySentence;
	LSystem myLSystem;

	sf::Color myColor;
	sf::Vector2f currBranchSize;
	sf::Vector2f currLoc;
	float currRot;
	float updatedRot;

	std::stack<sf::Vector2f> LocStack;
public:
	std::vector<branch> myFoliage;

	foliage(int height_i, string inputSentence_i, sf::Vector2f currBranchSize_i, sf::Vector2f initLoc, float initRot, float updatedRot_i, sf::Color color_i);
	void BuildMyLSystem(string inputSentence_i, int height_i);
	sf::Vector2f CalculateNextLoc(sf::Vector2f currLoc, float currRot, float branchLength);
	void GrowFoliage();
};