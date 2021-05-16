#include "HealthBar.h"

/*!
* \file
* \brief Plik definicyjny klasy Healthbar
*
* Plik definicyjny klasy Healthbar.
*/


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
	if (percentage >= 0)
		barSprite.setScale({ percentage, 1.0f });
	else
		barSprite.setScale({ 0.0f, 1.0f });
}