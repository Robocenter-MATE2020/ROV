#ifndef LEVELMOTOR_H
#define LEVELMOTOR_H

#include "Motor.h"

class LevelMotor : public Motor 
{
public:
	LevelMotor();
	LevelMotor(uint8_t pin_left, uint8_t pin_right);
	void init();
	void set_power(int8_t power);
private:
	uint8_t m_driver_left;
	uint8_t m_driver_right;
};
#endif