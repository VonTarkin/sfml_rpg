#include "Button.h"


Button::Button(float x, float y, std::string type) : Clickable(x, y)
{
	additionalTextureSet = false;
	if (type == "skill")
	{
		if (!normalTexture.loadFromFile("./assets/SkillSquare.png"))
			std::cout << "SkillSquare texture load error!" << std::endl;
		if (!triggeredTexture.loadFromFile("./assets/SkillSquareTriggered.png"))
			std::cout << "SkillSquare texture load error!" << std::endl;
		this->offset = 6;
	}
	else if (type == "function")
	{
		if (!normalTexture.loadFromFile("./assets/FunctionButton.png"))
			std::cout << "SkillSquare texture load error!" << std::endl;
		if (!triggeredTexture.loadFromFile("./assets/FunctionButtonTriggered.png"))
			std::cout << "SkillSquare texture load error!" << std::endl;
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
	if (!additionalTexture.loadFromFile("./assets/" + name + pngSuffix))
	{
		std::cout << name << " additionalTexture load error!" << std::endl;
	}
	this->additionalSprite.setTexture(additionalTexture);
	this->additionalSprite.setPosition(sf::Vector2f(pos.x + offset, pos.y + offset));
	
	additionalTextureSet = true;
}