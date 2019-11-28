#ifndef BRUSHLESS_MOTOR_H
#define BRUSHLESS_MOTOR_H

#include "BrushlessMotor.h"

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
	gpioServo(m_driver, map(speed, -100, 100, 1000, 2000));
}

#endif