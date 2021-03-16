#include "gameFunctions.h"

void initializeGame()
{

}

void UpdateClickables(int size, bool* prevPressed, bool* nowPressed, Clickable** clickables)
{
	bool changed = false;
	for (int i = 0; i < size; i++)
	{
		if (nowPressed[i] != prevPressed[i])
		{
			changed = true;
			break;
		}
	}

	if (changed)
	{
		for (int i = 0; i < size; i++)
		{
			if (nowPressed[i] == prevPressed[i])
			{
				nowPressed[i] = false;
				clickables[i]->SetButtonState(nowPressed[i]);
			}
			prevPressed[i] = nowPressed[i];
		}
	}
}