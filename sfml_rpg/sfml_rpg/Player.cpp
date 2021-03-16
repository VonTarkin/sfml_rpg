#include "Player.h"

Player::Player(float x, float y, std::string name) : Entity(x, y, name)
{
	buttonsAmount = sizeof(this->buttons) / sizeof(this->buttons[0]);
	prevPressed = new bool[buttonsAmount];
	nowPressed = new bool[buttonsAmount];
	for (int i = 0; i < buttonsAmount; i++)
	{
		this->buttons[i] = new Button(this->unitFrame->width + x + buttonOffset * i, y, "skill");
		prevPressed[i] = false;
		nowPressed[i] = false;
	}

}

void Player::Render(sf::RenderTarget* renderTarget)
{
	Entity::Render(renderTarget);
	for (int i = 0; i < buttonsAmount; i++)
		buttons[i]->Render(renderTarget);
}

void Player::Update(const sf::Vector2f mousePos)
{
	Entity::Update(mousePos);
	for (int i = 0; i < buttonsAmount; i++)
		buttons[i]->Update(mousePos);
	for (int i = 0; i < buttonsAmount; i++)
		nowPressed[i] = buttons[i]->isPressed();
	
	this->UpdateButtons();
}

void Player::UpdateButtons()
{
	bool changed = false;
	for (int i = 0; i < buttonsAmount; i++)
	{
		if (nowPressed[i] != prevPressed[i])
		{
			changed = true;
			break;
		}
	}
	if (changed)
	{
		for (int i = 0; i < buttonsAmount; i++)
		{
			if (nowPressed[i] == prevPressed[i])
			{
				nowPressed[i] = false;
				buttons[i]->SetButtonState(nowPressed[i]);
			}
			if (nowPressed[i])
				activeButtonIndex = i;
			prevPressed[i] = nowPressed[i];
			
		}
	}
}
