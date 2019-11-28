#ifndef BRUSHMOTOR_H
#define BRUSHMOTOR_H

#include "BrushMotor.h"

BrushMotor::BrushMotor(uint8_t pin_left, uint8_t pin_right)
{
	m_pin_left = pin_left;
	m_pin_right = pin_right;
}

void BrushMotor::init()
{
	gpioSetMode(m_pin_left, PI_OUTPUT);
	gpioSetMode(m_pin_right, PI_OUTPUT);
}

void BrushMotor::write(int8_t speed)
{
	if (speed > 0)
	{
		gpioWrite(m_pin_left, PI_LOW);
		gpioPWM(m_pin_right, map(speed, -100, 100, 0, 255));
	}
	if (speed <= 0)
	{
		gpioPWM(m_pin_left, map(speed, -100, 100, 0, 255));
		gpioWrite(m_pin_right, PI_LOW);
	}
}

#endif