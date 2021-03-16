#include "Enemy.h"

Enemy::Enemy(float x, float y, std::string name) : Entity(x, y, name)
{

}

void Enemy::Render(sf::RenderTarget* renderTarget)
{
	Entity::Render(renderTarget);
}

void Enemy::Update(const sf::Vector2f mousePos)
{
	Entity::Update(mousePos);
}