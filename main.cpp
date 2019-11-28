//#include <wiringPi.h>
#include <pigpio.h>
#include <iostream>
#include "BrushlessMotor.h"
#include "RotaryCamera.h"
#include "Timer.h"
#include "BrushMotor.h"
#include <chrono>
#include <vector>
#include "posix_serial.hpp"
extern "C" {
#include "packet.h"
#include "imu_data_decode.h"
}
#include "IMU.h"
using namespace std;

#define motor_1 5
#define motor_2 6
#define motor_3 13
#define motor_4 19
#define motor_5 26
#define motor_6 21
#define motor_7 20
#define motor_8 16

int main(void)
{
	gpioInitialise();

	gpioTerminate();
	return 0;
}