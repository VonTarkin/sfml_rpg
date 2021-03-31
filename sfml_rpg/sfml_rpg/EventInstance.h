#pragma once
#include "GenDMGUpgrade.h"
#include "Player.h"
#include "Random.h"
class EventInstance
{
public:
	EventInstance(sf::RenderWindow& window, Player* player, Random* random);
	~EventInstance();
	void GenerateNewEvent();
	void Render();
	void Update();
	void ProcessEvent();
private:
	Event* event;
	sf::Sound sound;
	sf::RenderWindow& window;
	Player* player;
	Random* random;

};

