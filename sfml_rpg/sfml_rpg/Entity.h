#pragma once
#include "Stats.h"
#include "UnitFrame.h"
#include <fstream>
#include "Button.h"
#include "UnitFrame.h";
#include "HealthBar.h"
#include "Status.h"
#include <vector>
//skills





class Entity
{
public:
	 Entity(float x, float y, std::string name);
	 Entity();
	 ~Entity();
	 UnitFrame* unitFrame;
	 HealthBar* healthBar;
	 Stats stats;
	 std::vector <Status> statuses;


	 void Render(sf::RenderTarget* renderTarget);
	 void Update(const sf::Vector2f mousePos);
	 void ProcessStatuses();
	 void AddStatus(int dmg, int duration, std::string type);
protected:
	
	std::string path = "./assets/";
	std::string textSuffix = "Stats.txt";
	std::fstream file;
	std::string spriteSuffix = "Trans.png";
};

