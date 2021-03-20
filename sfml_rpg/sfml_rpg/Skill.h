#pragma once
#include "Entity.h"
class Skill
{
public:  
	Skill();
	virtual void function(Entity* target, int dmg);
protected:
	std::string name;

};

