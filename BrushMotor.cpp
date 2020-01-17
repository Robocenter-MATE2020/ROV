#include "BrushMotor.h"
#include <pigpio.h>
#include "AdditionalFunctions.h"

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
	m_power = constrain(speed, -100, 100);
	m_power = m_is_inverse ? m_power * -1 : m_power;
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

