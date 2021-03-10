#pragma once
#include "enums.h"
#include <string>
#include <iostream>
#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include "SFML/Audio.hpp"



class Button
{
public:

	void Render(sf::RenderTarget* target);
	void Update(const sf::Vector2f mousePos);
	const bool isPressed();

	Button(float x, float y, std::string type);
	~Button();

private:
	short unsigned buttonState;

	sf::Sprite sprite;
	std::string type;
	sf::Texture normalTexture;
	sf::Texture triggeredTexture;

};

