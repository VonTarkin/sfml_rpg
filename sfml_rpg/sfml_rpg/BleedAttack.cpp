#include "BleedAttack.h"

/*!
* \file
* \brief Plik definicyjny klasy BleedAttack
*
* Plik Definicyjny klasy BleedAttack.
*/


BleedAttack::BleedAttack()
{
	this->name = "SkillBleedAttack";
	this->cooldown = 2;
	this->dmgDec = 4;
	this->bleedDMG = 3;
	this->bleedDur = 3;

	if (!this->soundBuffer.loadFromFile(l_folderPath + name + l_wavFormat))
	{
		std::cout << "BLEED SOUND ATTACK LOAD ERROR" << std::endl;
	}
}

void BleedAttack::Function(Entity* target, Entity* attacker, Random* random)
{
	int dmg = random->RandomInt(attacker->stats.minDMG - dmgDec, attacker->stats.maxDMG - dmgDec);

	int effectiveAcc = attacker->stats.accuracy - target->stats.dodge;

	if (random->IfHitLanded(effectiveAcc))
	{
		target->stats.health -= dmg;
		std::cout << "DMG FOR : " << dmg << std::endl;
		
		target->AddStatus(bleedDMG, bleedDur, "Bleed");
	}
	else
		std::cout << "MISS" << std::endl;


}