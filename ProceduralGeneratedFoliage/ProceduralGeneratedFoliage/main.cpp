#include "config.h"
#include "branch.h"

std::map <char, string> InitalizeRules() {
	std::map <char, string> Rules;
	Rules['F'] = "FF+[+F-F-F]-[-F+F+F]";
	return Rules;
}


string Generate(string axiom, std::map <char, string> Rules) {
	string nextSentense = "";
	for (int i = 0; i < axiom.size(); ++i) {
		char currChar = axiom.at(i);

		//check if Rules contains rule of currChar
		if (Rules.find(currChar) != Rules.end()) {
			nextSentense.append(Rules[currChar]);
		}
		else {
			nextSentense.append(string(1, currChar));
		}
	}

	return nextSentense;
}

sf::Vector2f CalculateNextLoc(sf::Vector2f currLoc, float currRot, float branchLength) {
	float nextX, nextY;

	nextX = currLoc.x + branchLength * cos(currRot * PI / 180);
	nextY = currLoc.y + branchLength * sin(currRot * PI / 180);
	return sf::Vector2f(nextX, nextY);
}

int main()
{
	string axiom = "F";
	std::map <char, string> Rules = InitalizeRules();

	int depth = 5;
	
	string currSentense = axiom;
	
	std::vector<branch> Foliage;
	float branchLength = 15;
	float branchWidth = 1;
	sf::Vector2f currBranchSize = sf::Vector2f(branchLength, branchWidth);
	sf::Vector2f currLoc = sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT);
	float currRot = -90;
	float updatedRot = 25;
	std::stack<sf::Vector2f> LocStack;

	//sfml drawing
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");

	bool isGrowing = true;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		
		//turtle drawing
		if (isGrowing) {
			for (int i = 0; i < depth; ++i) {
				for (int j = 0; j < currSentense.size(); ++j) {
					char currChar = currSentense.at(j);
					if (currChar == 'F') {
						branch newBranch(currBranchSize, currLoc, currRot);
						Foliage.push_back(newBranch);
						//update currLoc
						currLoc = CalculateNextLoc(currLoc, currRot, branchLength);
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

				string nextSentence = Generate(currSentense, Rules);
				cout << nextSentence << endl;
				currSentense = nextSentence;
			}
			isGrowing = false;
		}

		for (branch b : Foliage) {
			window.draw(b.Line);
		}
		

		window.display();
	}


	//system("pause");

	return 0;
}
