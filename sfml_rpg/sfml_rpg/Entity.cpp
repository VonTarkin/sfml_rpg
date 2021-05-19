#include "Entity.h"

/*!
* \file
* \brief Plik definicyjny klasy Entity.
*
* Plik definicyjny klasy Entity.
*/

Entity::Entity(float x, float y, std::string name)
{
	file.open(l_folderPath + name + l_statsSuffix);

	if (file.good())
	{
		file >> this->stats.Name;
		file >> this->stats.maxHealth;
		this->stats.health = this->stats.maxHealth;
		file >> this->stats.minDMG;
		file >> this->stats.maxDMG;
		file >> this->stats.accuracy;
		file >> this->stats.dodge;
	}
	else
		std::cout << name << l_statsSuffix << " not opened properly!" << std::endl;

	if (!font.loadFromFile(l_font))
	{
		std::cout << "FONT LOAD ERROR" << std::endl;
	}

	this->unitFrame = std::unique_ptr<UnitFrame>(new UnitFrame(x, y, l_folderPath + name + l_spriteSuffix));
	this->healthBar = std::unique_ptr<HealthBar>(new HealthBar(x, y - 50));

	this->textOffsetX = 171;
	this->textOffsetY = 171;

	this->statsText.setFillColor(sf::Color::Black);
	this->statsText.setString("DMG: " + std::to_string(this->stats.minDMG) +  "-" + std::to_string(this->stats.maxDMG) + "\n" + "DODGE: " + std::to_string(this->stats.dodge) + "\n" + "ACC: " + std::to_string(this->stats.accuracy));
	this->statsText.setFont(font);
	this->statsText.setCharacterSize(40);
	this->statsText.setPosition(x + textOffsetX, y + textOffsetY);
}

Entity::Entity()
{
	this->stats.maxHealth = 1;
	this->stats.health = 1;
}

Entity::~Entity()
{

}

void Entity::Render(sf::RenderTarget* renderTarget)
{
	this->healthBar->Render(renderTarget);
	this->unitFrame->Render(renderTarget);
}

void Entity::Update(const sf::Vector2f mousePos)
{
	float h = this->stats.health;

	this->healthBar->Update(float(h / stats.maxHealth));
	this->unitFrame->Update(mousePos);
}

void Entity::ProcessStatuses()
{
	int blightDMGSum = 0;
	int bleedDMGSum = 0;
	for (int i = 0; i < statuses.size(); i++)
	{
		if (statuses[i].duration < 0)
			statuses.erase(statuses.begin() + i);

		this->stats.health -= statuses[i].dmg;
		
		if (statuses[i].type == "Blight")
			blightDMGSum += statuses[i].dmg;
		else if (statuses[i].type == "Bleed")
			bleedDMGSum += statuses[i].dmg;
	}
	
	if (bleedDMGSum > 0)
	{
		std::cout << bleedDMGSum << " DMG TO BLEED" << std::endl;
	}
	if (blightDMGSum > 0)
	{
		std::cout << blightDMGSum << " DMG TO BLIGHT" << std::endl;
	}
}

void Entity::AddStatus(int dmg, int duration, std::string type)
{
	Status status;
	status.dmg = dmg;
	status.duration = duration;
	status.type = type;
	this->statuses.push_back(status);
}