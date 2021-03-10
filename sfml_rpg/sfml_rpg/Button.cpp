#include "Button.h"


Button::Button(float x, float y, std::string type)
{
	this->buttonState = BTN_IDLE;

	if (type == "skill")
	{
		if (!normalTexture.loadFromFile("./assets/SkillSquare.png"))
			std::cout << "SkillSquare texture load error!" << std::endl;
		if (!triggeredTexture.loadFromFile("./assets/SkillSquareTriggered.png"))
			std::cout << "SkillSquare texture load error!" << std::endl;
		


		this->sprite.setPosition(sf::Vector2f(x, y));
		this->sprite.setTexture(normalTexture);
	}
}

void Button::Render(sf::RenderTarget* target)
{

	target->draw(this->sprite);
}

void Button::Update(const sf::Vector2f mousePos)
{
	if(this->buttonState != BTN_ACTIVE)
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
		std::cout << "SkillSquare default casec error!" << std::endl;
	}
}


const bool Button::isPressed()
{
	if (this->buttonState == BTN_ACTIVE)
		return true;

	return false;
}