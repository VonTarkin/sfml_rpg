#include "Button.h"


Button::Button(float x, float y, std::string type) : Clickable(x, y)
{

	if (type == "skill")
	{
		if (!normalTexture.loadFromFile("./assets/SkillSquare.png"))
			std::cout << "SkillSquare texture load error!" << std::endl;
		if (!triggeredTexture.loadFromFile("./assets/SkillSquareTriggered.png"))
			std::cout << "SkillSquare texture load error!" << std::endl;
		

		this->sprite.setTexture(normalTexture);
	}
}