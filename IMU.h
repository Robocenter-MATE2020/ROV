#ifndef IMU_H
#define IMU_H

#include "rov_device_types.h"

class posix_serial;
struct RovData;

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

#endif