#pragma once
#include "enums.h"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include <iostream>
class UnitFrame
{
public:
	void Render(sf::RenderTarget* target);
	void Update(const sf::Vector2f mousePos);
	const bool isPressed();

	UnitFrame(float x, float y);
	~UnitFrame();

private:
	short unsigned buttonState;
	sf::Sprite unitFrameSprite;
	sf::Sprite characterSprite;
	sf::Texture normalTexture;
	sf::Texture triggeredTexture;
};

