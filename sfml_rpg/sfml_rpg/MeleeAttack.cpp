#include "MeleeAttack.h"

MeleeAttack::MeleeAttack()
{
}

void MeleeAttack::function(Entity* target, int dmg)
{
	 target->stats.health-=dmg;
}
