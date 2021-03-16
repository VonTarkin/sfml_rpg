#include <SFML/Graphics.hpp>

#include "Player.h"



//FIRST: ENTITY (Player/Enemy)
//SECOND: Display fight screen test


int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 500), "RPG");


	Player* testP = new Player(20, 80, "Thorne");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		auto MousePos = sf::Mouse::getPosition(window);

		testP->Update({static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)});
		testP->Render(&window);

		window.display();

	}

	return 0;
}
