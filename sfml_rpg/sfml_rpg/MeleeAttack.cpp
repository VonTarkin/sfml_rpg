#include "MeleeAttack.h"

/*!
* \file
* \brief Plik definicyjny klasy MeleeAttack
*
* Plik Definicyjny klasy MeleeAttack.
*/
MeleeAttack::MeleeAttack()
{
	this->cooldown = 0;
	this->name = "SkillMeleeAttack";
	if (!this->soundBuffer.loadFromFile("./assets/" + name + ".wav"))
	{
		std::cout << "MELEE SOUND ATTACK LOAD ERROR" << std::endl;
	}
}

MeleeAttack::~MeleeAttack()
{

}

void MeleeAttack::Function(Entity* target, Entity* attacker, Random* random)
{
	int dmg = random->RandomInt(attacker->stats.minDMG, attacker->stats.maxDMG);

	int effectiveAcc = attacker->stats.accuracy - target->stats.dodge;

	if (random->IfHitLanded(effectiveAcc))
	{
		target->stats.health -= dmg;
		std::cout << "DMG " << dmg << std::endl;
	}
	else
		std::cout << "MISS" << std::endl;


}
