#ifndef BRUSHLESS_MOTOR_H
#define BRUSHLESS_MOTOR_H

#include <stdint.h>
#include "Motor.h"

class BrushlessMotor : public Motor
{
public:
	BrushlessMotor();
	BrushlessMotor(uint8_t pin);
	void init();
	void write(int8_t speed);
private:
	unsigned m_driver;
};

#endif