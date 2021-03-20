#include "UnitFrame.h"

UnitFrame::UnitFrame(float x, float y, std::string charSpritePath) : Clickable(x , y)
{
	normalTexture.loadFromFile("./assets/UnitFrame.png");
	triggeredTexture.loadFromFile("./assets/UnitFrameTriggered.png");

	characterTexture.loadFromFile(charSpritePath);


	this->characterSprite.setPosition(x, y);
	this->characterSprite.setTexture(characterTexture);
}

UnitFrame::~UnitFrame()
{

}

void UnitFrame::Render(sf::RenderTarget* target)
{
	Clickable::Render(target);
	target->draw(this->characterSprite);
}
