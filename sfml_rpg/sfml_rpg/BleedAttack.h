#pragma once
#include "Skill.h"
class BleedAttack : public Skill
{
public:
	BleedAttack();
	virtual void Function(Entity* target, Entity* attacker, Random* random) override;
private:
	int dmgDec;
	int bleedDMG;
	int bleedDur;
};

