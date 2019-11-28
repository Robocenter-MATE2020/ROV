#include "Motor.h"
#include <pigpio.h>
#include <stdint.h>
#include "AdditionalFunctions.h"

class LevelMotor : public Motor {
public:
	LevelMotor();
	LevelMotor(uint8_t pin_left, uint8_t pin_right);
	void init();
	void set_power(int8_t power);
private:
	uint8_t m_driver_left;
	uint8_t m_driver_right;
};