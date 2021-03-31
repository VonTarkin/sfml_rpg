#pragma once
#include "Event.h"
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

