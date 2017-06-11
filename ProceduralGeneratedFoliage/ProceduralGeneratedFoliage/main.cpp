#include "config.h"
#include "bush.h"
#include "UserInterface.h"

int main()
{
	//bush init
	bush b = bush();
		
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
				b.GrowBush(sf::Vector2f(sf::Mouse::getPosition(window)));
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
		for (foliage f : b.myBush) {
			for (branch b : f.myFoliage) {
				window.draw(b.Line);
			}
		}
		
		window.display();
	}

	return 0;
}
