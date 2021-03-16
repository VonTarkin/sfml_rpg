#include "Entity.h"

Entity::Entity(float x, float y, std::string name)
{
	file.open(path + name + textSuffix);

	if (file.good())
	{
		file >> this->stats.Name;
		file >> this->stats.maxHealth;
		this->stats.health = this->stats.maxHealth;
		file >> this->stats.minDMG;
		file >> this->stats.maxDMG;
		file >> this->stats.accuracy;
		file >> this->stats.dodge;
	}
	else
		std::cout << name << textSuffix <<" not opened properly!" << std::endl;
	this->unitFrame = new UnitFrame(x, y, path + name + spriteSuffix);
	this->healthBar = new HealthBar(x, y - 50);
}

void Entity::Render(sf::RenderTarget* renderTarget)
{
	this->healthBar->Render(renderTarget);
	this->unitFrame->Render(renderTarget);
}

void Entity::Update(const sf::Vector2f mousePos)
{
	this->healthBar->Update(float(stats.health / stats.maxHealth));
	this->unitFrame->Update(mousePos);
}