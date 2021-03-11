#pragma once
#include "Stats.h"
#include "UnitFrame.h"
#include <fstream>
#include <string>

#include "UnitFrame.h";
class Entity
{
public:
	 Entity(float x, float y, std::string name);
	 Entity();
	 UnitFrame* unitFrame;
	 Stats stats;

	 void Render(sf::RenderTarget* renderTarget);
	 void Update(const sf::Vector2f mousePos);

protected:
	std::string path = "./assets/";
	std::string textSuffix = "Stats.txt";
	std::fstream file;
	std::string spriteSuffix = "Trans.png";

};

