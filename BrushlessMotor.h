#include <pigpio.h>
#include "AdditionalFunctions.h"

class BrushlessMotor
{
public:
	BrushlessMotor(uint8_t pin);
	void init();
	void write(int8_t speed);
private:
	unsigned m_driver;
};
