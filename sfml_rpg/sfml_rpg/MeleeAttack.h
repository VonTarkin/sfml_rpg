#pragma once
#include "Skill.h"

class MeleeAttack : public virtual Skill
{
public:
	MeleeAttack();
	virtual void function(Entity* target, Entity* attacker, Random* random) override;
};

