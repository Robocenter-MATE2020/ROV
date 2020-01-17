#ifndef ROTARY_CAMERA_H
#define ROTARY_CAMERA_H

#include <stdint.h>

class Timer;

class RotaryCamera
{
public:
	RotaryCamera(uint8_t pin);
	void init();
	void write(int8_t angle);
	void setRotationTime(uint8_t);
private:
	unsigned m_driver;
	uint8_t m_angle = 0;
	Timer* m_timer;
	int8_t m_lastangle = 0;
	uint8_t m_rotation_time;

};

#endif