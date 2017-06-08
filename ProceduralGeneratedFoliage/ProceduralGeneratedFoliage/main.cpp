#include "config.h"
#include "foliage.h"


int main()
{
	std::vector<foliage> Bush;

	string axiom = "F";	
	int height = 5;
	float branchLength = 15;
	float branchWidth = 1;
	sf::Vector2f currBranchSize = sf::Vector2f(branchLength, branchWidth);
	sf::Vector2f currLoc = sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT);
	float currRot = -90;
	float updatedRot = 25;
	
	//sfml drawing
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");

	foliage foliage1(height, axiom, currBranchSize, currLoc, currRot, updatedRot);
	foliage1.GrowFoliage();
	Bush.push_back(foliage1);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();


		for (foliage f : Bush) {
			for (branch b : f.myFoliage) {
				window.draw(b.Line);
			}
		}
		
		window.display();
	}

	return 0;
}
