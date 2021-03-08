#include "Player.h"

Player::Player(int maxHealth, int minDMG, int maxDMG, int dodge, int accuracy)
{
	stats.maxHealth = maxHealth;
	stats.minDMG = minDMG;
	stats.maxDMG = maxDMG;
	stats.dodge = dodge;
	stats.accuracy = accuracy;
}

void Player::Attack(Entity target)
{

}