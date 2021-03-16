#pragma once
#include "Stats.h"
#include "UnitFrame.h"
#include "Button.h"
#include "UnitFrame.h";

class HealthBar
{
public:
	HealthBar();
	HealthBar(float x, float y);
	void Render(sf::RenderTarget* target);
	void Update(float percentage);
private:

	sf::Sprite barSprite;
	sf::Texture barTexture;
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
	float offset = 10;

	std::string path = "./assets/";
	std::string healthBar = "HealthBar.png";
	std::string healthBackground = "HealthBarBackground.png";
};