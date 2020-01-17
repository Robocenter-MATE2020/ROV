#ifndef TIMER_H
#define TIMER_H

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

#endif