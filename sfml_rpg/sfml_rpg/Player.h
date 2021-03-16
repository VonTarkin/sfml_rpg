#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(float x, float y, std::string name);
	~Player();
	void Render(sf::RenderTarget* renderTarget);
	void Update(const sf::Vector2f mousePos);

private:
	int buttonsAmount = 0;
	int selected = NULL;
	int buttonOffset = 38;
	Button*  buttons[4];
	bool* prevPressed;
	bool* nowPressed;
};


