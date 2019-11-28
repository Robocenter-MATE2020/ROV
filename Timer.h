#pragma once
#include <chrono>

class Timer
{
public:
	Timer();
	void start();
	int elapsed();
	bool is_started();
	void stop();
private:
	bool m_is_started = false;
	int m_starting_time = 0;
};