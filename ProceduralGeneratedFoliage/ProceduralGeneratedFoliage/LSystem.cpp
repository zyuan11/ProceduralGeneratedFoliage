#include "LSystem.h"

void LSystem::InitalizeLSystem(string axiom_i, int height_i){
	axiom = axiom_i;
	height = height_i;
}

void LSystem::InitalizeRules() {
	Rules['F'] = "FF+[+F-F-F]-[-F+F+F]";
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
		//cout << currSentense << endl;
	}
	

	return nextSentense;
}