#include "Player.h"

/*!
* \file
* \brief Plik definicyjny klasy Player.
*
* Plik definicyjny klasy Player.
*/

Player::Player(float x, float y, std::string name) : Entity(x, y, name)
{
	buttonsAmount = 3;

	for (int i = 0; i < buttonsAmount; i++)
	{
		std::unique_ptr<Button> button(new Button(this->unitFrame->width + x + buttonOffset * i, y, "skill"));
		buttons.push_back(std::move(button));
		prevPressed.push_back(false);
		nowPressed.push_back(false);
		cooldowns.push_back(0);
	}
	this->initializeSkills();


}

Player::~Player()
{
}

void Player::initializeSkills()
{
	std::unique_ptr<Skill> skill1(new MeleeAttack);
	std::unique_ptr<Skill> skill2(new VampireAttack);
	std::unique_ptr<Skill> skill3(new BleedAttack);
	skills.push_back(std::move(skill1));
	this->buttons[0]->SetAdditionalTexture(this->skills[0]->name);
	skills.push_back(std::move(skill2));
	this->buttons[1]->SetAdditionalTexture(this->skills[1]->name);
	skills.push_back(std::move(skill3));
	this->buttons[2]->SetAdditionalTexture(this->skills[2]->name);
}

void Player::Render(sf::RenderTarget* renderTarget)
{
	Entity::Render(renderTarget);

	for (std::vector<std::unique_ptr<Button>>::iterator it = buttons.begin(); it != buttons.end(); ++it)
	{
		(*it)->Render(renderTarget);
	}
}

void Player::Update(const sf::Vector2f mousePos)
{
	Entity::Update(mousePos);

	for (std::vector<std::unique_ptr<Button>>::iterator it = buttons.begin(); it != buttons.end(); ++it)
	{
		(*it)->Update(mousePos);
	}
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