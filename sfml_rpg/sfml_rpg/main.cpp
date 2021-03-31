#include <SFML/Graphics.hpp>
#include "gameFunctions.h"
#include "FightInstance.h"
#include "EventInstance.h"


//FIRST: ENTITY (Player/Enemy)
//SECOND: Display fight screen test


int main()
{
	sf::Music music;
	if (!music.openFromFile("./assets/heaven.wav"))
	{
		std::cout << "MUSIC LOAD ERROR" << std::endl;
	}
	music.play();

	Random* random = new Random();
	sf::RenderWindow window(sf::VideoMode(900, 500), "RPG");
	window.setFramerateLimit(60);

	Player* testP = new Player(20, 80, "Thorne");
	while (true)
	{
		EventInstance* eventInstance = new EventInstance(window, testP, random);
		eventInstance->ProcessEvent();
		if (!window.isOpen())
			return 0;
		delete eventInstance;
		FightInstance* fightInstance = new FightInstance(window, testP, random);
		fightInstance->Fight();
		if (!window.isOpen())
			return 0;
		delete fightInstance;
	}



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
