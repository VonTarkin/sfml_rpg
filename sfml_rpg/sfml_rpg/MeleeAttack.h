#pragma once
#include "Skill.h"

class MeleeAttack : public virtual Skill
{
public:
	MeleeAttack();
	//virtual void function(Entity* target) override;
	virtual void function(Entity* target, int dmg) override;
};

