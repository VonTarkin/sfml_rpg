#pragma once
#include <chrono>
class Timer
{
public:
	std::chrono::time_point<std::chrono::high_resolution_clock> lastTime;
	Timer();
	double Elapsed();

};

