#include <SFML/Graphics.hpp>
#include "gameFunctions.h"
#include "FightInstance.h"



//FIRST: ENTITY (Player/Enemy)
//SECOND: Display fight screen test


int main()
{
	Random* random = new Random();
	sf::RenderWindow window(sf::VideoMode(900, 500), "RPG");
	window.setFramerateLimit(60);

	Player* testP = new Player(20, 80, "Thorne");
	Enemy* testE = new Enemy(400, 80, "Xotrios");
	FightInstance* fightInstance = new FightInstance(window, testP, testE, random);
	fightInstance->Fight();
	/*while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();-
		}

		window.clear(sf::Color::White);
		auto MousePos = sf::Mouse::getPosition(window);

		testP->Update({static_cast<float>(MousePos.x), static_cast<float>(MousePos.y)});
		testP->Render(&window);
		testE->Update({ static_cast<float>(MousePos.x), static_cast<float>(MousePos.y) });
		testE->Render(&window);

		window.display();

	} */

	return 0;
}
