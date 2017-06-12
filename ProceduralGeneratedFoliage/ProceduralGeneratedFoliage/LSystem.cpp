#include "LSystem.h"

void LSystem::InitalizeLSystem(string axiom_i, int height_i){
	axiom = axiom_i;
	height = height_i;
}

void LSystem::InitalizeRules(Direction dir_i) {
	Rules['F'] = GenerateRule(dir_i);
}

string LSystem::Generate() {
	string currSentense = axiom;
	string nextSentense = "";
	for (int j = 0; j < height; ++j) {
		nextSentense = "";

		for (int i = 0; i < currSentense.size(); ++i) {
			char currChar = currSentense.at(i);

			//check if Rules contains rule of currChar
			if (Rules.find(currChar) != Rules.end()) {
				nextSentense.append(Rules[currChar]);
			}
			else {
				nextSentense.append(string(1, currChar));
			}
		}

		currSentense = nextSentense;
	}
	

	return nextSentense;
}

string LSystem::GenerateRule(Direction dir_i) {
	//srand(time(NULL));
	
	string newRule = "";

	switch (dir_i) {
	case LEFT:
		newRule = GenerateLeftDirRule();
		break;
	case MIDDLE:
		newRule = GenerateMiddleDirRule();
		break;
	case RIGHT:
		newRule = GenerateRightDirRule();
		break;
	}
	cout << newRule << endl;
	return newRule;
}

string LSystem::GenerateMiddleDirRule() {
	string newRule;

	newRule.append("FF-[-" + GetFOrFF() + "+" + GetFOrFF() + "+" + GetFOrFF() + "]+[+" + GetFOrFF() + "-" + GetFOrFF() + "-" + GetFOrFF() + "]");
	return newRule;
}
string LSystem::GenerateLeftDirRule() {
	string newRule;

	newRule.append("FF-[-" + GetFOrFF() + "+" + GetFOrFF() + "]+[+" + GetFOrFF() + "-" + GetFOrFF() + "]");
	return newRule;
}
string LSystem::GenerateRightDirRule() {
	string newRule;

	newRule.append("FF+[+" + GetFOrFF() + "-" + GetFOrFF() + "]-[-" + GetFOrFF() + "+" + GetFOrFF() + "]");
	return newRule;
}

string LSystem::GetFOrFF() {
	string outStr = "";
	int randNum =  rand() % 2 + 1;
	cout << "randNum: " << randNum << endl;
	for (int i = 0; i < randNum; ++i) {
		outStr.append("F");
	}

	return outStr;
}