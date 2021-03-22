#include "MeleeAttack.h"

MeleeAttack::MeleeAttack()
{
}

void MeleeAttack::function(Entity* target, Entity* attacker, Random* random)
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
