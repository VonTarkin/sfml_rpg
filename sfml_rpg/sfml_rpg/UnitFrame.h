#pragma once
#include "enums.h"
#include "Clickable.h"

class UnitFrame : public Clickable
{
public:
	void Render(sf::RenderTarget* target);
	//sf::Vector2f offset;
	UnitFrame(float x, float y);
	~UnitFrame();

private:

	sf::Sprite characterSprite;
	sf::Texture characterTexture;
};

