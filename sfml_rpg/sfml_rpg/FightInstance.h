#pragma once

#include "Enemy.h"
#include "Player.h"
#include "Random.h"
/*void Fight(sf::RenderWindow& window, Player* player, Enemy* enemies, Random* random);
void UpdateUnitFrames(int amount);*/

class FightInstance
{
public:

	 FightInstance(sf::RenderWindow& window, Player* player, Random* random);
	 ~FightInstance();
	 void Update();
	 void Render();
	 void Fight();
	 void UpdateEntities();
	 void OnPressedAttackButton();
	 void CounterAttack();
	 bool CheckIfFinished();
	 void GenerateEnemy();
	 void InitializeText();
private:
	Enemy* enemy;
	int enemyAmount;
	sf::Sound sound;
	sf::RenderWindow& window;
	Player* player;
	Enemy* enemies;
	Random* random;
	sf::Clock clock;
	sf::Time attackCooldown;
	int turn;
	Button* attackButton;
	int activeTargetIndex;
	int enemiesAmount;
	Entity** entities;
	bool* prevPressed;
	bool* nowPressed;
	bool changed;
	sf::Font font;
	sf::Text text1;
	sf::Text text2;
	sf::Text text3;
	std::vector<sf::Text> texts;
};

