#pragma once
#include <string>
#include <iostream>
#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button
{
public:
	Button(float x, float y, std::string type);
	~Button();
	void Render(sf::RenderTarget* target);
	void Update(const sf::Vector2f mousePos);

	const bool isPressed();

private:
	short unsigned buttonState;
	float xSize, ySize;
	sf::RectangleShape shape;
	sf::Sprite sprite;
	std::string type;
	sf::Texture normalTexture;
	sf::Texture triggeredTexture;

};

