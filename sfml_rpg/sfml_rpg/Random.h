#pragma once
#include <random>
class Random
{
public:
	Random();
	int RandomInt(int min, int ma);
	bool IfHitLanded(int effectiveAcc);
private:
	std::random_device rand;
};

