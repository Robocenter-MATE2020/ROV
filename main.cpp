#include <pigpio.h>
#include "Rov.h"
#include "IMU.h"
#include "AdditionalFunctions.h"
#include <iostream>
#include "UDPConnection.h"
#include "BrushlessMotor.h"
#include "ms5837.hpp"
#include "ThrustersSubSystem.h"

ThrustersSubSystem motors;
UDPConnection udp;
IMU imu;
RovData data;

//BrushlessMotor motor(17);
//UDPConnection udp;
//Rov rov;

int main(void)
{
	gpioInitialise();
	//udp.init();
	imu.init();
	//motors.init();
	//gpioDelay(10000000);
	//motor.write(100);
	//gpioDelay(5000000);
	
	std::cout << "start" << std::endl;
	//gpioDelay(5000000);

	while (true)
	{
		imu.read(data);
		//udp.write(data);
		//udp.read(data);
		//motors.write(data);
	}
	gpioTerminate();
	return 0;
}