#pragma once
#include "Entity.h"
class Enemy : public Entity
{
public:
	Enemy(float x, float y, std::string name);
	~Enemy();
	void Render(sf::RenderTarget* renderTarget);
	void Update(const sf::Vector2f mousePos);
};

