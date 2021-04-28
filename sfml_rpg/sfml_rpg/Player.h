#pragma once
#include "Entity.h"
#include <array>

#include "MeleeAttack.h"
#include "VampireAttack.h"
#include "BleedAttack.h"
class Player : public Entity
{
public:
	Player(float x, float y, std::string name);
	~Player();
	void Render(sf::RenderTarget* renderTarget);
	void Update(const sf::Vector2f mousePos);
	void UpdateButtons();
	int activeButtonIndex;
	void initializeSkills();
	int CheckCooldown(int index);
	void DecrementCooldowns();
	void SetCooldown(int index, int cooldown);
	//Skill** skills;
	std::vector<std::unique_ptr<Skill>> skills;
	//std::unique_ptr<Skill[]> skills;
	//int* cooldowns
	std::vector<int> cooldowns;
private:

	int buttonsAmount = 0;
	int selected = NULL;
	int buttonOffset = 38;
	std::vector<std::unique_ptr<Button>> buttons;
	std::vector<bool> prevPressed;
	std::vector<bool> nowPressed;
	//bool* prevPressed;
	//bool* nowPressed;
};


