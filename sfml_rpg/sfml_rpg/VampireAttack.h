#pragma once
#include "Skill.h"
class VampireAttack : public Skill
{
public:
	VampireAttack();
	virtual void Function(Entity* target, Entity* attacker, Random* random) override;
private:
	int dmgDec;
};

