#include "Enemy.h"

/*!
* \file
* \brief Plik definicyjny klasy Enemy.
*
* Plik definicyjny klasy Enemy.
*/

Enemy::Enemy(float x, float y, std::string name) : Entity(x, y, name)
{
	this->InitializeSkill();
}

Enemy::~Enemy()
{

}

void Enemy::InitializeSkill()
{
	if (stats.Name == "Xotrios")
		skill = std::unique_ptr<Skill>(new MeleeAttack);
	if (stats.Name == "Nazg")
		skill = std::unique_ptr<Skill>(new MeleeAttack);
}

void Enemy::Render(sf::RenderTarget* renderTarget)
{
	Entity::Render(renderTarget);
}

void Enemy::Update(const sf::Vector2f mousePos)
{
	Entity::Update(mousePos);
}