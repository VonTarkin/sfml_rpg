#pragma once
#include "enums.h"
#include "LoadPaths.h"
#include <iostream>
#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

/*!
* \file
* \brief Plik naglowkowy klasy Clickable
*
* Plik naglowkowy klasy Clickable.
*/

class Clickable
{

	public:

	void Render(sf::RenderTarget* target);
	void Update(const sf::Vector2f mousePos);
	const bool isPressed();
	void SetButtonState(bool state);
	Clickable() = delete;
	Clickable(float x, float y);
	~Clickable();



	short unsigned buttonState;
	sf::Sprite sprite;	
	sf::Texture normalTexture;
	sf::Texture triggeredTexture;


};

