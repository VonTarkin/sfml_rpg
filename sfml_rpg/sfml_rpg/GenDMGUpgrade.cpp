#include "GenDMGUpgrade.h"

GenDMGUpgrade::GenDMGUpgrade()
{

	if(!font.loadFromFile("./assets/arcade.ttf"))
	{
		std::cout << "FONT LOAD ERROR" << std::endl;
	}
	this->text.setFillColor(sf::Color::Black);
	this->text.setString("The Sword Sharpens...");
	this->text.setFont(font);
	this->text.setCharacterSize(40);
	this->text.setPosition(1, 1);
	this->bFirst = new Button(20, 140, "function");
}

GenDMGUpgrade::~GenDMGUpgrade()
{
	delete this->bFirst;
}

void GenDMGUpgrade::Update(const sf::Vector2f mousePos)
{
	this->bFirst->Update(mousePos);
}

void GenDMGUpgrade::Render(sf::RenderTarget* target)
{
	this->bFirst->Render(target);
	
}

void GenDMGUpgrade::Option1(Player* player)
{
	player->stats.minDMG++;
}

