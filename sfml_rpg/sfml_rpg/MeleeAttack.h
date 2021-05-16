#pragma once
#include "Skill.h"
/*!
* \file
* \brief Plik naglowkowy klasy MeleeAttack
*
* Plik naglowkowy klasy MeleeAttack.
*/


class MeleeAttack : public virtual Skill
{
public:
	MeleeAttack();
	~MeleeAttack();
	virtual void Function(Entity* target, Entity* attacker, Random* random) override;
};
