#include "gameFunctions.h"


void Fight(sf::RenderWindow& window, Player* player, Enemy* enemies, Random* random)
{
	sf::Clock clock;
	sf::Time attackCooldown = sf::seconds(2);
	int turn = 1;
	Button* attackButton = new Button(191, 200, "function");
	int activeTargetIndex = -1;
	int enemiesAmount = sizeof(*enemies) / sizeof(enemies[0]);
	Entity** entities = new Entity * [enemiesAmount + 1];
	bool* prevPressed = new bool[enemiesAmount + 1];
	bool* nowPressed = new bool[enemiesAmount + 1];
	bool changed = false;

	entities[0] = player;
	for (int i = 1; i < enemiesAmount + 1; i++)
		entities[i] = &enemies[i - 1]; 
	for (int i = 0; i < enemiesAmount; i++) 
	{
	nowPressed[i] = false;
	prevPressed[i] = false;
	}

;		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear(sf::Color::White);
			auto MousePos = sf::Mouse::getPosition(window);

			player->Update({ static_cast<float>(MousePos.x), static_cast<float>(MousePos.y) });
			player->Render(&window);
			for (int i = 0; i < enemiesAmount; i++)
			{
				enemies[i].Update({ static_cast<float>(MousePos.x), static_cast<float>(MousePos.y) });
				enemies[i].Render(&window);
			}

			attackButton->Update({ static_cast<float>(MousePos.x), static_cast<float>(MousePos.y) });
			attackButton->Render(&window);
			window.display();
			

			//Updating entities
			changed = false;
			for (int i = 0; i < enemiesAmount + 1; i++)
			{
				nowPressed[i] = entities[i]->unitFrame->isPressed();
				if (prevPressed[i] != nowPressed[i])
				{
					changed = true;
					break;
				}
			}
			if (changed)
			{
				for (int i = 0; i < enemiesAmount + 1; i++)
				{
					if (nowPressed[i] == prevPressed[i])
					{
						nowPressed[i] = false;
						entities[i]->unitFrame->SetButtonState(nowPressed[i]);
					}
					if (nowPressed[i])
						activeTargetIndex = i;

					prevPressed[i] = nowPressed[i];
				}
			}

			if (attackButton->isPressed())
			{
				if (clock.getElapsedTime() > attackCooldown)
				{
					if (player->CheckCooldown(player->activeButtonIndex) == 0)
					{
						player->skills[player->activeButtonIndex]->Function(entities[activeTargetIndex], player, random);
						player->SetCooldown(player->activeButtonIndex, player->skills[player->activeButtonIndex]->cooldown);

						clock.restart();
						std::cout << "ATT " << activeTargetIndex << std::endl;
						player->DecrementCooldowns();
						
						for (int i = 0; i < enemiesAmount; i++)
							enemies[i].ProcessStatuses();
						player->ProcessStatuses();

					}
					else
					{
						std::cout << "Skill Cooldown" << std::endl;
					}
				}
				else
				{
				//	std::cout << "Delay" << std::endl;
				}
				attackButton->SetButtonState(false);
			}
			

		}
		delete[] entities;
		delete[] prevPressed;
		delete[] nowPressed;
}
