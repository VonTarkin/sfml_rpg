#pragma once
#include <string>

/*!
* \file
* \brief Struktura opisujaca statystyki.
*
* Struktura opisujaca statystyki.
*/

typedef struct Stats
{
	std::string Name;
	int health;
	int maxHealth;
	int minDMG;
	int maxDMG;
	int dodge;
	int accuracy;
};