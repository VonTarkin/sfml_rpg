#include "UnitFrame.h"

UnitFrame::UnitFrame(float x, float y) : Clickable(x , y)
{
	normalTexture.loadFromFile("./assets/UnitFrame.png");
	triggeredTexture.loadFromFile("./assets/UnitFrameTriggered.png");
	characterTexture.loadFromFile("./assets/ThorneTRans.png");

	this->characterSprite.setPosition(x, y);
	this->characterSprite.setTexture(characterTexture);
}

void UnitFrame::Render(sf::RenderTarget* target)
{
	Clickable::Render(target);
	target->draw(this->characterSprite);
}
