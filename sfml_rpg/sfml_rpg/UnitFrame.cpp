#include "UnitFrame.h"

UnitFrame::UnitFrame(float x, float y)
{
	this->buttonState = BTN_IDLE;

	normalTexture.loadFromFile("./assets/UnitFrame.png");
	triggeredTexture.loadFromFile("./assets/UnitFrameTriggered.png");
	//characterSprite.loadFromFile("assets")

	this->unitFrameSprite.setPosition(x, y);
	this->unitFrameSprite.setTexture(normalTexture);
}

void UnitFrame::Render(sf::RenderTarget* target)
{
	target->draw(this->unitFrameSprite);
}


void UnitFrame::Update(const sf::Vector2f mousePos)
{
	if (this->buttonState != BTN_ACTIVE)
		this->buttonState = BTN_IDLE;
	if (this->unitFrameSprite.getGlobalBounds().contains(mousePos) && this->buttonState != BTN_ACTIVE)
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
		this->unitFrameSprite.setTexture(normalTexture);
		break;
	case BTN_HOVER:
		this->unitFrameSprite.setTexture(triggeredTexture);
		break;
	case BTN_ACTIVE:
		this->unitFrameSprite.setTexture(triggeredTexture);
		break;
	default:
		std::cout << "SkillSquare default casec error!" << std::endl;
	}
}


const bool UnitFrame::isPressed()
{
	if (this->buttonState == BTN_ACTIVE)
		return true;

	return false;
}