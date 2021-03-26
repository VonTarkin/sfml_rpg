#include "MeleeBleedAtttack.h"

void MeleeBleedAttack::Function(Entity* target, Entity* attacker, Random* random)
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