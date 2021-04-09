#include "FightInstance.h"

FightInstance::FightInstance(sf::RenderWindow& _window, Player* player, Random* random) : window(_window)
{
	this->random = random;
	this->player = player;;
	attackCooldown = sf::seconds(1);
	turn = 1;
	attackButton = new Button(191, 200, "function");
	activeTargetIndex = -1;
	enemyAmount = 1;
	entities = new Entity * [enemyAmount + 1];
	prevPressed = new bool[enemyAmount + 1];
	nowPressed = new bool[enemyAmount + 1];
	changed = false;

	entities[0] = player;

	for (int i = 0; i < enemyAmount; i++)
	{
		nowPressed[i] = false;
		prevPressed[i] = false;
	}
	this->GenerateEnemy();
}

FightInstance::~FightInstance()
{
	delete attackButton;
	delete enemy;
	delete[] entities;
	delete prevPressed;
	delete nowPressed;

}

void FightInstance::GenerateEnemy()
{
	int choice = this->random->RandomInt(1, 1);
	
	if (choice == 1)
	{
		enemy = new Enemy(400, 80, "Xotrios");
	}
	entities[1] = enemy;
}

void FightInstance::Update()
{
	auto MousePos = sf::Mouse::getPosition(window);
	player->Update({ static_cast<float>(MousePos.x), static_cast<float>(MousePos.y) });


		enemy->Update({ static_cast<float>(MousePos.x), static_cast<float>(MousePos.y) });
	attackButton->Update({ static_cast<float>(MousePos.x), static_cast<float>(MousePos.y) });
}

void FightInstance::Render()
{
	player->Render(&window);

		enemy->Render(&window);

	attackButton->Render(&window);
	window.draw(player->statsText);
	window.draw(enemy->statsText);
	window.display();
}

void FightInstance::UpdateEntities()
{
	changed = false;

	for (int i = 0; i < 2; i++)
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
		for (int i = 0; i < enemyAmount + 1; i++)
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

			enemy->ProcessStatuses();
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
		std::cout << "ENEMYSTART" << std::endl;
		enemy->skill->Function(player, enemy, random);
		std::cout << "ENEMYEND" << std::endl;

}

bool FightInstance::CheckIfFinished()
{
	if (this->player->stats.health <= 0 || this->enemy->stats.health <= 0)
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
