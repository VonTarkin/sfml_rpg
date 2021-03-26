#pragma once
#include "Skill.h"
class MeleeBleedAtttack : public Skill
{
	virtual void Function(Entity* target, Entity* attacker, Random* random) override;
};

