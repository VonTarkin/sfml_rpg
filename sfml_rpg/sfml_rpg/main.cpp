#include <SFML/Graphics.hpp>
#include "gameFunctions.h"
#include "FightInstance.h"
#include "EventInstance.h"
#include "Timer.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <conio.h>


//FIRST: ENTITY (Player/Enemy)
//SECOND: Display fight screen test
/**/
namespace ch = std::chrono;
namespace tt = std::this_thread;

std::atomic<bool> mainThreadRunning;
int secondsPassed;

void timeCounter()
{
	while (mainThreadRunning)
	{
		tt::sleep_for(ch::seconds{ 1 });
		secondsPassed++;
	}
}


int main()
{
	mainThreadRunning = true;
	std::thread countTime(timeCounter);

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
			//return 0;
			break;
		delete eventInstance;
		FightInstance* fightInstance = new FightInstance(window, testP, random);
		fightInstance->Fight();
		delete fightInstance;
		if (testP->stats.health <= 0)
		{
			//return 0;
			break;
		}

		if (!window.isOpen())
			//return 0;
			break;


	}
	tt::sleep_for(ch::seconds{ 1 });
	delete random;
	delete testP;
	mainThreadRunning = false;

	countTime.join();
	std::cout << "Game ended in " << secondsPassed << " seconds!";
	char a = _getch();


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
