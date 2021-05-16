#include "Random.h"

/*!
* \file
* \brief Plik definicyjny klasy Random
*
* Plik definicyjny klasy Random.
*/


Random::Random()
{
	std::mt19937 gen(rand());
}

int Random::RandomInt(int min, int max)
{
	std::uniform_int_distribution<> dist(min, max);
	return dist(rand);
}

bool Random::IfHitLanded(int effectiveAcc)
{

	int accRes = this->RandomInt(0, 100);
	if (effectiveAcc > accRes)
	{
		return true;
	}
	else
		return false;
}