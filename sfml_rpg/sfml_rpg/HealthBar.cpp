#include "HealthBar.h"

HealthBar::HealthBar(float x, float y)
{
	barTexture.loadFromFile(path + healthBar);
	backgroundTexture.loadFromFile(path + healthBackground);

	this->barSprite.setTexture(barTexture);
	this->backgroundSprite.setTexture(backgroundTexture);

	this->backgroundSprite.setPosition(x, y);
	this->barSprite.setPosition(x + offset, y + offset);
}

void HealthBar::Render(sf::RenderTarget* target)
{
	target->draw(this->backgroundSprite);
	target->draw(this->barSprite);
}

void HealthBar::Update(float percentage)
{
	barSprite.setScale({percentage, 1.0f});
}