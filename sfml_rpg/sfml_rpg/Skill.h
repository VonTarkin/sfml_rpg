#pragma once
#include "Entity.h"
#include <cstdlib>
#include <ctime>
#include "Random.h"
class Skill
{
public:  
	Skill();
	virtual void function(Entity* target, int dmg);
	virtual void function(Entity* target, Entity* attacker, Random* random);
protected:
	std::string name;

};

