#pragma once
#include "Button.h"
#include "Event.h"
#include "Player.h"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
class Event
{
public: 
	Event();
	virtual void Option1(Player* player);
	virtual void Update(const sf::Vector2f mousePos);
	virtual void Render(sf::RenderTarget* target);
	sf::Text text;
	Button* bFirst = nullptr;
protected:
	sf::Font font;
};

