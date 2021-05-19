#pragma once
#include "Entity.h"
#include "MeleeAttack.h"
#include "VampireAttack.h"
#include "BleedAttack.h"

/*!
* \file
* \brief Plik naglowkowy klasy Enemy
*
* Plik naglowkowy klasy Enemy.
*/

class Enemy : public Entity
{
public:
	Enemy(float x, float y, std::string name);
	~Enemy();
	void Render(sf::RenderTarget* renderTarget);
	void Update(const sf::Vector2f mousePos);
	void InitializeSkill();
	std::unique_ptr<Skill> skill;
private:

};

