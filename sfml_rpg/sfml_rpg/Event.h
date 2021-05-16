#pragma once
#include "Button.h"
#include "Event.h"
#include "Player.h"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

/*!
* \file
* \brief Plik naglowkowy klasy Event.
*
* Plik naglowkowy klasy Event.
*/

class Event
{
public: 
	Event();
	virtual void Option1(Player* player);
	virtual void Update(const sf::Vector2f mousePos);
	virtual void Render(sf::RenderTarget* target);
	sf::Text text;
	std::unique_ptr<Button> bFirst;
protected:
	sf::Font font;
};

