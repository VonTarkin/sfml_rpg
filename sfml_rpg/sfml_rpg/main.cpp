#include <SFML/Graphics.hpp>
#include "FightInstance.h"
#include "EventInstance.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <conio.h>


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
			break;
		delete eventInstance;
		FightInstance* fightInstance = new FightInstance(window, testP, random);
		fightInstance->Fight();
		delete fightInstance;
		if (testP->stats.health <= 0)
		{
			break;
		}

		if (!window.isOpen())
			break;


	}
	tt::sleep_for(ch::seconds{ 1 });
	delete random;
	delete testP;
	mainThreadRunning = false;

	window.close();
	countTime.join();

	std::cout << "Game ended in " << secondsPassed << " seconds!";
	char a = _getch();

	return 0;
}
