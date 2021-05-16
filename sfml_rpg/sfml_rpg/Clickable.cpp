#include "Clickable.h"


/*!
* \file
* \brief Plik definicyjny klasy Clickable
*
* Plik definicyjny klasy Clickable.
*/

Clickable::Clickable(float x, float y)
{
	this->buttonState = BTN_IDLE;

		this->sprite.setPosition(sf::Vector2f(x, y));
}

Clickable::~Clickable()
{

}

void Clickable::Render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

void Clickable::Update(const sf::Vector2f mousePos)
{
	if (this->buttonState != BTN_ACTIVE)
		this->buttonState = BTN_IDLE;
	if (this->sprite.getGlobalBounds().contains(mousePos) && this->buttonState != BTN_ACTIVE)
	{
		this->buttonState = BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_ACTIVE;
		}
	}

	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->sprite.setTexture(normalTexture);
		break;
	case BTN_HOVER:
		this->sprite.setTexture(triggeredTexture);
		break;
	case BTN_ACTIVE:
		this->sprite.setTexture(triggeredTexture);
		break;
	default:
		std::cout << "Clickable default case error!" << std::endl;
	}
}

const bool Clickable::isPressed()
{
	if (this->buttonState == BTN_ACTIVE)
		return true;

	return false;
}

void Clickable::SetButtonState(bool state)
{
	if (state)
		this->buttonState = BTN_ACTIVE;
	else if (!state)
		this->buttonState = BTN_IDLE;
}