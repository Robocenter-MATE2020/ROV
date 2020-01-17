#ifndef BRUSHMOTOR_H
#define BRUSHMOTOR_H

#include "Motor.h"

class BrushMotor : public Motor
{
public:
	BrushMotor(uint8_t pin_left, uint8_t pin_right);
	void init();
	void write(int8_t speed);
private:
	bool m_is_inverse = false;
	unsigned m_pin_left;
	unsigned m_pin_right;
};

#endif