#include "Timer.h"

Timer::Timer()  :lastTime(std::chrono::high_resolution_clock::now())
{

}

double Timer::Elapsed()
{
	std::chrono::time_point<std::chrono::high_resolution_clock> thisTime = std::chrono::high_resolution_clock::now();
	double deltaTime = std::chrono::duration<double>(thisTime - lastTime).count();
	lastTime = thisTime;
	return deltaTime;

}