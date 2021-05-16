#pragma once
#include "Skill.h"

/*!
* \file
* \brief Plik naglowkowy klasy VampireAttack
*
* Plik naglowkowy klasy VampireAttack.
*/


class VampireAttack : public Skill
{
public:
	VampireAttack();
	virtual void Function(Entity* target, Entity* attacker, Random* random) override;
private:
	int dmgDec;
};

