#include "LevelMotor.h"
#include <pigpio.h>
#include <stdint.h>
#include "AdditionalFunctions.h"

LevelMotor::LevelMotor()
{
}

LevelMotor::LevelMotor(uint8_t pin_left, uint8_t pin_right)
{
	m_driver_right = pin_right;
	m_driver_left = pin_left;
}
void LevelMotor::init()
{
	gpioSetMode(m_driver_left, PI_OUTPUT);
	gpioSetMode(m_driver_right, PI_OUTPUT);
}
void LevelMotor::set_power(int8_t power)
{
	m_power = constrain(power, -100, 100);
	m_power = m_is_inverse ? m_power * -1 : m_power;
	if (m_power == 0)
	{
		gpioWrite(m_driver_left, PI_LOW);
		gpioWrite(m_driver_right, PI_LOW);
	}
	else if (m_power > 0)
	{
		gpioWrite(m_driver_left, PI_HIGH);
		gpioWrite(m_driver_right, PI_LOW);
	}
	else
	{
		gpioWrite(m_driver_left, PI_LOW);
		gpioWrite(m_driver_right, PI_HIGH);
	}
}