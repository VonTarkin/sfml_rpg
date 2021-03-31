#pragma once
#include "Skill.h"

class MeleeAttack : public virtual Skill
{
public:
	MeleeAttack();
	~MeleeAttack();
	virtual void Function(Entity* target, Entity* attacker, Random* random) override;
};
