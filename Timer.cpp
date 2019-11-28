#ifndef TIMER_H
#define TIMER_H

#include "Timer.h"

Timer::Timer()
{

}

void Timer::start()
{
	m_is_started = true;
	m_starting_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

int Timer::elapsed()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - m_starting_time;
}

bool Timer::is_started()
{
	return m_is_started;
}

void Timer::stop()
{
	m_is_started = false;
}

#endif