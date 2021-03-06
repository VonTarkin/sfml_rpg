#include "UnitFrame.h"

/*!
* \file
* \brief Plik definicyjny klasy UnitFrame
*
* Plik definicyjny klasy UnitFrame.
*/

UnitFrame::UnitFrame(float x, float y, std::string charSpritePath) : Clickable(x , y)
{
	normalTexture.loadFromFile(l_unitFrame);
	triggeredTexture.loadFromFile(l_unitFrameTriggered);

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
