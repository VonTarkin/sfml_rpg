#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Button.h"



//FIRST: ENTITY (Player/Enemy)
//SECOND: Display fight screen test


int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 500), "RPG");
	Button* gamestate_btn = new Button(0, 0, "skill");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		auto MousePos = sf::Mouse::getPosition(window);

		gamestate_btn->Update({ static_cast<float>(MousePos.x), static_cast<float>(MousePos.y) });
		gamestate_btn->Render(&window);

		window.display();

	}

	return 0;
}
