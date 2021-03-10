#pragma once
#include "Clickable.h"




class Button : public Clickable
{
public:

	//void Render(sf::RenderTarget* target);
	//const bool isPressed();

	Button(float x, float y, std::string type);
	~Button();

protected:

	std::string type;


};

