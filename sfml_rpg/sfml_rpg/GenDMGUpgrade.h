#pragma once
#include "Event.h"

/*!
* \file
* \brief Plik naglowkowy klasy GenDMGUpgrade.
*
* Plik naglowkowy klasy genDMGUpgrade.
*/

class GenDMGUpgrade : public Event
{
public:
	GenDMGUpgrade();
	~GenDMGUpgrade();
	virtual void Render(sf::RenderTarget* target) override;
	virtual void Update(const sf::Vector2f mousePos) override;
	virtual void Option1(Player* player) override;
private:

};

