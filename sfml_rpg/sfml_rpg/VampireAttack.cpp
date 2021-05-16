#include "VampireAttack.h"

/*!
* \file
* \brief Plik definicyjny klasy VampireAttack
*
* Plik Definicyjny klasy VampireAttack.
*/

VampireAttack::VampireAttack()
{
	this->name = "SkillVampireAttack";
	this->cooldown = 2;
	this->dmgDec = 2;

	if (!this->soundBuffer.loadFromFile("./assets/" + name + ".wav"))
	{
		std::cout << "VAMPIRE SOUND ATTACK LOAD ERROR" << std::endl;
	}
}

void VampireAttack::Function(Entity* target, Entity* attacker, Random* random)
{
	int dmg = random->RandomInt(attacker->stats.minDMG - dmgDec, attacker->stats.maxDMG - dmgDec);

	int effectiveAcc = attacker->stats.accuracy - target->stats.dodge;

	if (random->IfHitLanded(effectiveAcc))
	{
		target->stats.health -= dmg;
		std::cout << "DMG AND HEALED FOR : " << dmg << std::endl;
		attacker->stats.health += dmg;
		if (attacker->stats.health > attacker->stats.maxHealth)
		{
			attacker->stats.health = attacker->stats.maxHealth;
		}
	}
	else
		std::cout << "MISS" << std::endl;


}
