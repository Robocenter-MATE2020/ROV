#include "BrushlessMotor.h"
#include <pigpio.h>
#include "AdditionalFunctions.h"

BrushlessMotor::BrushlessMotor()
{

}

BrushlessMotor::BrushlessMotor(uint8_t pin) 
{
	m_driver = pin;
}

void BrushlessMotor::init()
{
	gpioSetMode(m_driver, PI_OUTPUT);
	gpioServo(m_driver, 1500);
}

void BrushlessMotor::write(int8_t speed)
{
	m_power = constrain(speed, -100, 100);
	m_power = m_is_inverse ? m_power * -1 : m_power;
	gpioServo(m_driver, map(speed, -100, 100, 1000, 2000));
}
