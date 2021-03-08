#pragma once
class GameInstance
{
public:
	int turns;
	bool isInBattle;

	GameInstance();

	void newFight();
	void newEvent();
};

