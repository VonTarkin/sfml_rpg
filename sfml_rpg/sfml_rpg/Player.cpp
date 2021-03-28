#include "Player.h"

Player::Player(float x, float y, std::string name) : Entity(x, y, name)
{
	buttonsAmount = sizeof(this->buttons) / sizeof(this->buttons[0]);
	prevPressed = new bool[buttonsAmount];
	nowPressed = new bool[buttonsAmount];
	cooldowns = new int[buttonsAmount];
	for (int i = 0; i < buttonsAmount; i++)
	{
		this->buttons[i] = new Button(this->unitFrame->width + x + buttonOffset * i, y, "skill");
		prevPressed[i] = false;
		nowPressed[i] = false;
		cooldowns[i] = 0;
	}
	this->initializeSkills();


}

Player::~Player()
{
	delete[] prevPressed;
	delete[] nowPressed;
	for (int i = 0; i < this->buttonsAmount; i++)
	{
		delete this->buttons[i];
		delete this->skills[i];
	}
	delete[] buttons;
	delete[] skills;
	delete skills;
}

void Player::initializeSkills()
{
	this->skills = new Skill*[buttonsAmount];
	this->skills[0] = new MeleeAttack();
	this->buttons[0]->SetAdditionalTexture(this->skills[0]->name);
	this->skills[1] = new VampireAttack();
	this->buttons[1]->SetAdditionalTexture(this->skills[1]->name);
	this->skills[2] = new BleedAttack();
	this->buttons[2]->SetAdditionalTexture(this->skills[2]->name);
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

int Player::CheckCooldown(int index)
{
	return cooldowns[index];
}

void Player::DecrementCooldowns()
{
	for (int i = 0; i < buttonsAmount; i++)
	{
		if (cooldowns[i] > 0)
			cooldowns[i]--;
	}
}

void Player::SetCooldown(int index, int cooldown)
{
	cooldowns[index] = cooldown;
}