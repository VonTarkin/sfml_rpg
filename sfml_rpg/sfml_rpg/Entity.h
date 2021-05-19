#pragma once
#include <algorithm>
#include "Stats.h"
#include "UnitFrame.h"
#include <fstream>
#include "Button.h"
#include "UnitFrame.h";
#include "HealthBar.h"
#include "Status.h"
#include <vector>
/*!
* \file
* \brief Plik naglowkowy klasy Entity.
*
* Plik naglowkowy klasy Entity.
*/





class Entity
{
public:
	 Entity(float x, float y, std::string name);
	 Entity();
	 ~Entity();
	 std::unique_ptr<UnitFrame> unitFrame;
	 std::unique_ptr<HealthBar> healthBar;
	 Stats stats;
	 std::vector <Status> statuses;
	 void Render(sf::RenderTarget* renderTarget);
	 void Update(const sf::Vector2f mousePos);
	 void ProcessStatuses();
	 void AddStatus(int dmg, int duration, std::string type);
	 sf::Text statsText;
protected:
	int textOffsetY, textOffsetX;
	sf::Font font;

	std::fstream file;
};

