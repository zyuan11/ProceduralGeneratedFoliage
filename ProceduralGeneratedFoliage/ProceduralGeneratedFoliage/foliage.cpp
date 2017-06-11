#include "foliage.h"

foliage::foliage(int height_i, string inputSentence_i, sf::Vector2f currBranchSize_i, sf::Vector2f initLoc, float initRot, float updatedRot_i) {
	BuildMyLSystem(inputSentence_i, height_i);
	currBranchSize = currBranchSize_i;
	currLoc = initLoc;
	currRot = initRot;
	updatedRot = updatedRot_i;
}


void foliage::BuildMyLSystem(string inputSentence_i, int height_i) {
	myLSystem.InitalizeLSystem(inputSentence_i, height_i);
	myLSystem.InitalizeRules();
	mySentence = myLSystem.Generate();
}

sf::Vector2f foliage::CalculateNextLoc(sf::Vector2f currLoc, float currRot, float branchLength) {
	float nextX, nextY;

	nextX = currLoc.x + branchLength * cos(currRot * PI / 180);
	nextY = currLoc.y + branchLength * sin(currRot * PI / 180);
	return sf::Vector2f(nextX, nextY);
}

void foliage::GrowFoliage() {
	//turtle drawing
	for (int j = 0; j < mySentence.size(); ++j) {
		char currChar = mySentence.at(j);
		if (currChar == 'F') {
			branch newBranch(currBranchSize, currLoc, currRot, myColor);
			myFoliage.push_back(newBranch);
			
			//update currLoc
			currLoc = CalculateNextLoc(currLoc, currRot, currBranchSize.x);
		}
		else if (currChar == '+') {
			currRot += updatedRot;
		}
		else if (currChar == '-') {
			currRot -= updatedRot;
		}
		else if (currChar == '[') {
			LocStack.push(currLoc);
		}
		else if (currChar == ']') {
			currLoc = LocStack.top();
			LocStack.pop();
		}
	}
}