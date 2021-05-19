#include "Button.h"

/*!
* \file
* \brief Plik definicyjny klasy Button
*
* Plik definicyjny klasy Button.
*/

Button::Button(float x, float y, std::string type) : Clickable(x, y)
{
	additionalTextureSet = false;
	offset = 0;
	if (type == "skill")
	{
		if (!normalTexture.loadFromFile(l_skillSquare))
			std::cout << "SkillSquare texture load error!" << std::endl;
		if (!triggeredTexture.loadFromFile(l_skillSquareTriggered))
			std::cout << "SkillSquare texture load error!" << std::endl;
		this->offset = 6;
	}
	else if (type == "function")
	{
		if (!normalTexture.loadFromFile(l_functionButton))
			std::cout << "SkillSquare texture load error!" << std::endl;
		if (!triggeredTexture.loadFromFile(l_functionButtonTriggered))
			std::cout << "SkillSquare texture load error!" << std::endl;
		this->offset = 0;
	}

	this->sprite.setTexture(normalTexture);
}

Button::~Button()
{

}

void Button::Render(sf::RenderTarget* target)
{
	Clickable::Render(target);
	if(additionalTextureSet)
	target->draw(this->additionalSprite);
}


void Button::SetAdditionalTexture(std::string name)
{
	sf::Vector2f pos = this->sprite.getPosition();
	if (!additionalTexture.loadFromFile(l_folderPath + name + l_pngSuffix))
	{
		std::cout << name << " additionalTexture load error!" << std::endl;
	}
	this->additionalSprite.setTexture(additionalTexture);
	this->additionalSprite.setPosition(sf::Vector2f(pos.x + offset, pos.y + offset));
	
	additionalTextureSet = true;
}