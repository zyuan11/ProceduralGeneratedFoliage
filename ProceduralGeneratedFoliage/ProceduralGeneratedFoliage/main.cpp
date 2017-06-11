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
				sf::Vector2f clickPos = sf::Vector2f(sf::Mouse::getPosition(window));
				
				//click to give user input
				if (clickPos.x <= USERINTERFACE_WIDTH) {
					UI.UpdateDensity(clickPos);
					UI.UpdateDirection(clickPos);
				}
				else {
					Density density_i = UI.GetCurrDensity();
					b.GrowBush(sf::Vector2f(sf::Mouse::getPosition(window)), density_i);
				}
			}

		}

		window.clear();


		//draw UI
		window.draw(UI.background);
		window.draw(UI.DensityInfo);
		window.draw(UI.DirectionInfo);
		window.draw(UI.ColorInfo);
		window.draw(UI.DensityBar);
		window.draw(UI.DirectionBar);
		window.draw(UI.ColorBar);
		window.draw(UI.DensitySelect);
		window.draw(UI.DirectionSelect);
		window.draw(UI.ColorSelect);

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
