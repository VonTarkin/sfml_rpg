#include "FightInstance.h"

FightInstance::FightInstance(sf::RenderWindow& _window, Player* player, Enemy* enemies, Random* random) : window(_window)
{
	this->random = random;
	this->player = player;
	this->enemies = enemies;
	attackCooldown = sf::seconds(1);
	turn = 1;
	attackButton = new Button(191, 200, "function");
	activeTargetIndex = -1;
	enemiesAmount = sizeof(*enemies) / sizeof(enemies[0]);
	entities = new Entity * [enemiesAmount + 1];
	prevPressed = new bool[enemiesAmount + 1];
	nowPressed = new bool[enemiesAmount + 1];
	changed = false;

	entities[0] = player;
	for (int i = 1; i < enemiesAmount + 1; i++)
		entities[i] = &enemies[i - 1];
	for (int i = 0; i < enemiesAmount; i++)
	{
		nowPressed[i] = false;
		prevPressed[i] = false;
	}

}

FightInstance::~FightInstance()
{
	delete attackButton;
	delete entities;
	delete prevPressed;
	delete nowPressed;
}

void FightInstance::Update()
{
	auto MousePos = sf::Mouse::getPosition(window);
	player->Update({ static_cast<float>(MousePos.x), static_cast<float>(MousePos.y) });

	for (int i = 0; i < enemiesAmount; i++)
	{
		enemies[i].Update({ static_cast<float>(MousePos.x), static_cast<float>(MousePos.y) });
	}
	attackButton->Update({ static_cast<float>(MousePos.x), static_cast<float>(MousePos.y) });
}

void FightInstance::Render()
{
	player->Render(&window);
	for (int i = 0; i < enemiesAmount; i++)
	{
		enemies[i].Render(&window);
	}
	attackButton->Render(&window);
	window.display();
}

void FightInstance::UpdateEntities()
{
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
}

void FightInstance::OnPressedAttackButton()
{
	if (clock.getElapsedTime() > attackCooldown)
	{
		if (player->CheckCooldown(player->activeButtonIndex) == 0)
		{
			player->skills[player->activeButtonIndex]->Function(entities[activeTargetIndex], player, random);
			player->SetCooldown(player->activeButtonIndex, player->skills[player->activeButtonIndex]->cooldown);

			clock.restart();
			std::cout << "ATT " << activeTargetIndex << std::endl;

			//Comment out for Sounds
			this->sound.setBuffer(player->skills[player->activeButtonIndex]->soundBuffer);
			this->sound.play();
			this->CounterAttack();

			player->DecrementCooldowns();
			for (int i = 0; i < enemiesAmount; i++)
				enemies[i].ProcessStatuses();
			player->ProcessStatuses();

			turn++;
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

void FightInstance::CounterAttack()
{
	for (int i = 0; i < enemiesAmount; i++)
	{
		std::cout << "ENEMYSTART" << std::endl;
		enemies[i].skill->Function(player, &enemies[i], random);
		std::cout << "ENEMYEND" << std::endl;

	}
}

bool FightInstance::CheckIfFinished()
{
	if (this->player->stats.health <= 0 || this->enemies[0].stats.health <= 0)
	{
		return true;
	}
	return false;
}
void FightInstance::Fight()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return;
			}

			window.clear(sf::Color::White);
			this->Update();
			this->Render();
			this->UpdateEntities();

			if(attackButton->isPressed())
				this->OnPressedAttackButton();
			if (this->CheckIfFinished())
			{
				return;
			}
		}
	}
}
