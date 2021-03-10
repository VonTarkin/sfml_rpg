#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Button.h"
#include "UnitFrame.h"



//FIRST: ENTITY (Player/Enemy)
//SECOND: Display fight screen test


int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 500), "RPG");
	Button* gamestate_btn = new Button(0, 0, "skill");
	UnitFrame* unitFrame_test = new UnitFrame(38, 38);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		auto MousePos = sf::Mouse::getPosition(window);

		gamestate_btn->Update({ static_cast<float>(MousePos.x), static_cast<float>(MousePos.y) });
		gamestate_btn->Render(&window);
		unitFrame_test->Update({ static_cast<float>(MousePos.x), static_cast<float>(MousePos.y) });
		unitFrame_test->Render(&window);

		window.display();

	}

	return 0;
}
