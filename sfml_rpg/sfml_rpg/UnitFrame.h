#pragma once
#include "enums.h"
#include "Clickable.h"


/*!
* \file
* \brief Plik naglowkowy klasy Unitframe.
*
* Plik naglowkowy klasy UnitFrame.
*/

class UnitFrame : public Clickable
{
public:
	void Render(sf::RenderTarget* target);
	UnitFrame(float x, float y, std::string charSpritePath);
	UnitFrame();
	~UnitFrame();
	int width = 171;
	int height = 384;
protected:

	sf::Sprite characterSprite;
	sf::Texture characterTexture;
};

