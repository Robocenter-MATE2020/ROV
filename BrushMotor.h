#pragma once

#include "Motor.h"
#include <pigpio.h>
#include "AdditionalFunctions.h"

class BrushMotor : public Motor
{
public:
	BrushMotor(uint8_t pin_left, uint8_t pin_right);
	void init();
	void write(int8_t speed);
private:
	unsigned m_pin_left;
	unsigned m_pin_right;
};