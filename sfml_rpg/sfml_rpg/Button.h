#pragma once
#include "Clickable.h"




class Button : public Clickable
{
public:

	//void Render(sf::RenderTarget* target);
	//const bool isPressed();
	Button();
	Button(float x, float y, std::string type);
	void SetAdditionalTexture(std::string name);
	void Render(sf::RenderTarget* target);
	~Button();

protected:
	bool additionalTextureSet;
	int offset;
	std::string type;
	sf::Sprite additionalSprite;
	sf::Texture additionalTexture;


};

