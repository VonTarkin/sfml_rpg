#pragma once
#include "enums.h"
#include "Clickable.h"

class UnitFrame : public Clickable
{
public:
	void Render(sf::RenderTarget* target);
	UnitFrame(float x, float y, std::string charSpritePath);
	UnitFrame();
	~UnitFrame();

private:

	sf::Sprite characterSprite;
	sf::Texture characterTexture;
};

