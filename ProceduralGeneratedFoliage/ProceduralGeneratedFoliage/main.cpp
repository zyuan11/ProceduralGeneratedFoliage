#include "config.h"
#include "foliage.h"
#include "UserInterface.h"

int main()
{
	//bush init
	std::vector<foliage> Bush;
	string axiom = "F";	
	int height = 4;
	float branchLength = 7;
	float branchWidth = 0.6;
	sf::Vector2f currBranchSize = sf::Vector2f(branchLength, branchWidth);
	sf::Vector2f currLoc = sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT);
	float currRot = -90;
	float updatedRot = 15;
	
	//user interface init
	UserInterface UI = UserInterface();

	sf::Texture DensityInfoTexture = sf::Texture();
	DensityInfoTexture.loadFromFile("DensityText.png");
	UI.DensityInfo.setTexture(&DensityInfoTexture);

	sf::Texture DirectionInfoTexture = sf::Texture();
	DirectionInfoTexture.loadFromFile("DirectionText.png");
	UI.DirectionInfo.setTexture(&DirectionInfoTexture);

	sf::Texture ColorInfoTexture = sf::Texture();
	ColorInfoTexture.loadFromFile("ColorText.png");
	UI.ColorInfo.setTexture(&ColorInfoTexture);
	
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

		//draw UI
		for (auto r : UI.Drawable) {
			window.draw(r);
		}

		window.draw(UI.DensityInfo);
		window.draw(UI.DirectionInfo);
		window.draw(UI.ColorInfo);
		

		//draw bush
		for (foliage f : Bush) {
			for (branch b : f.myFoliage) {
				window.draw(b.Line);
			}
		}
		
		window.display();
	}

	return 0;
}
