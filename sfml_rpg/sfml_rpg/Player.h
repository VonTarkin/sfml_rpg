#pragma once
#include "Entity.h"

class Player : public Entity
{
	Player(int _maxHealth, int minAttack, int maxAttack, int dodge, int accuracy);
	void Attack(Entity target);
};

