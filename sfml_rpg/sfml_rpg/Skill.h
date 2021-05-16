#pragma once
#include "Entity.h"
#include <cstdlib>
#include <ctime>
#include "Random.h"

/*!
* \file
* \brief Plik naglowkowy klasy Skill
*
* Plik naglowkowy klasy Skill.
*/
 
class Skill
{
public:  
	Skill();
	virtual ~Skill();
	virtual void Function(Entity* target, Entity* attacker, Random* random);
	int cooldown;
	std::string name;
	sf::SoundBuffer soundBuffer;
protected:


};

