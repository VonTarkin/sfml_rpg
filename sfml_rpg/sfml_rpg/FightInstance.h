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
	//std::unique_ptr<Enemy> enemy;
	int enemyAmount;
	sf::Sound sound;
	sf::RenderWindow& window;
	Player* player;
	Random* random;
	sf::Clock clock;
	sf::Time attackCooldown;
	int turn;
	std::unique_ptr<Button> attackButton;
	//Button* attackButton;
	int activeTargetIndex;
	int enemiesAmount;
	//std::vector<std::unique_ptr<Entity>> entities;
	Entity** entities;
	std::vector<bool> prevPressed;
	std::vector<bool> nowPressed;
	//bool* prevPressed;
	//bool* nowPressed;
	bool changed;
	sf::Font font;
	sf::Text text1;
	sf::Text text2;
	sf::Text text3;
	std::vector<sf::Text> texts;
};

