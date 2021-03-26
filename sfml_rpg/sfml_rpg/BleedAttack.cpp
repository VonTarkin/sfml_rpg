#include "BleedAttack.h"

BleedAttack::BleedAttack()
{
	this->name = "SkillBleedAttack";
	this->cooldown = 2;
	this->dmgDec = 4;
	this->bleedDMG = 3;
	this->bleedDur = 3;
}

void BleedAttack::Function(Entity* target, Entity* attacker, Random* random)
{
	int dmg = random->RandomInt(attacker->stats.minDMG - dmgDec, attacker->stats.maxDMG - dmgDec);

	int effectiveAcc = attacker->stats.accuracy - target->stats.dodge;

	if (random->IfHitLanded(effectiveAcc))
	{
		target->stats.health -= dmg;
		std::cout << "DMG FOR : " << dmg << std::endl;
		attacker->stats.health += dmg;
		
		target->AddStatus(bleedDMG, bleedDur, "Bleed");
	}
	else
		std::cout << "MISS" << std::endl;


}