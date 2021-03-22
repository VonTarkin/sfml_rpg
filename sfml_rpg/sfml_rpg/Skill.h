#pragma once
#include "Entity.h"
#include <cstdlib>
#include <ctime>
#include "Random.h"
class Skill
{
public:  
	Skill();
	virtual void Function(Entity* target, int dmg);
	virtual void Function(Entity* target, Entity* attacker, Random* random);
	int cooldown;
	std::string name;
protected:


};

