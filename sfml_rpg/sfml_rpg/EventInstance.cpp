#include "EventInstance.h"

EventInstance::EventInstance(sf::RenderWindow& _window, Player* player, Random* random) : window(_window)
{
	this->player = player;
	this->random = random;
	this->GenerateNewEvent();
}

EventInstance::~EventInstance()
{
	delete event;
}

void EventInstance::GenerateNewEvent()
{
	this->event = new GenDMGUpgrade();
}

void EventInstance::ProcessEvent()
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
		}
		if (this->event->bFirst->isPressed())
		{
			std::cout << player->stats.minDMG << std::endl;
			this->event->Option1(player);
			std::cout << player->stats.minDMG << std::endl;
			return;
		}
	}
}


void EventInstance::Update()
{
	auto MousePos = sf::Mouse::getPosition(window);
	this->event->Update({ static_cast<float>(MousePos.x), static_cast<float>(MousePos.y) });
}

void EventInstance::Render()
{

	this->event->Render(&window);
	window.draw(event->text);
	window.display();

}