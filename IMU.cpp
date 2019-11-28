#ifndef IMU_H
#define IMU_H

#include "IMU.h"

IMU::IMU()
{
	m_serial = new posix_serial("/dev/ttyS0");
}

void IMU::init()
{
//	m_timer = new Timer;
//	m_timer->start();
	imu_data_decode_init();
}

void IMU::read(RovData& rov_data)
{
	float eular[3];
	std::vector<uint8_t> buf;
	size_t size = m_serial->read_bytes(buf);
	if (size)
	{
		for (auto i : buf)
		{
			Packet_Decode(i);
		}
	}
	get_eular(eular);
	rov_data.m_yaw = eular[2];
	rov_data.m_roll = eular[1];
	rov_data.m_pitch = eular[0];
	//std::cout << "time_elapsed = " << m_timer->elapsed() << std::endl;
	//std::cout << "pitch = " << eular[0] << std::endl;
	//std::cout << "roll = " << eular[1] << std::endl;
	//std::cout << "yaw = " << eular[2] << std::endl;
	//gpioDelay(100);
}

#endif