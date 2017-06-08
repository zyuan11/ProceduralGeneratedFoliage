#include "config.h"
#include "foliage.h"


int main()
{
	std::vector<foliage> Bush;

	string axiom = "F";	
	int height = 4;
	float branchLength = 7;
	float branchWidth = 0.5;
	sf::Vector2f currBranchSize = sf::Vector2f(branchLength, branchWidth);
	sf::Vector2f currLoc = sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT);
	float currRot = -90;
	float updatedRot = 25;
	
	//sfml drawing
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonReleased) {
				foliage newFoliage(height, axiom, currBranchSize, sf::Vector2f(sf::Mouse::getPosition(window)), currRot, updatedRot);
				newFoliage.GrowFoliage();
				Bush.push_back(newFoliage);
			}
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
