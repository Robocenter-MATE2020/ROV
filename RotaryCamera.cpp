#include "RotaryCamera.h"
#include <pigpio.h>
#include "AdditionalFunctions.h"
#include "Timer.h"

#define DEF_ANGLE 0

RotaryCamera::RotaryCamera(uint8_t pin)
{
	m_timer = new Timer;
	m_driver = pin;
}

void RotaryCamera::init()
{
	gpioSetMode(m_driver, PI_OUTPUT);
	gpioServo(m_driver, map(DEF_ANGLE, 0, 180, 1000, 2000));
	m_timer->start();
	m_rotation_time = 30;
}

void RotaryCamera::setRotationTime(uint8_t time)
{
	m_rotation_time = time;
}

void RotaryCamera::write(int8_t angle)
{
	m_lastangle = angle != m_lastangle ? angle : m_lastangle;
	if (m_timer->elapsed() > m_rotation_time)//30
	{
		m_angle += m_lastangle;
		m_timer->start();
		m_angle = constrain(m_angle, 3, 179);
		gpioServo(m_driver, map(constrain(m_angle, 0, 180), 0, 180, 1000, 2000));
	}	
}