#pragma once
#include <random>

/*!
* \file
* \brief Plik naglowkowy klasy Random
*
* Plik naglowkowy klasy Random.
*/


class Random
{
public:
	Random();
	int RandomInt(int min, int ma);
	bool IfHitLanded(int effectiveAcc);
private:
	std::random_device rand;
};

