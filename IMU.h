#include <iostream>
#include <vector>
#include "Timer.h"
#include "RovData.h"
#include "posix_serial.hpp"
#include "rov_device_types.h"
extern "C" {
#include "packet.h"
#include "imu_data_decode.h"
}

class IMU : public Input
{
public:
	IMU();
	void init();
	void read(RovData& rov_data);
private:
	//Timer* m_timer;
	posix_serial* m_serial;
};