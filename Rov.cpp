#include "Rov.h"
#include <pigpio.h>
//#include "OutputSubSystem.h"
//#include "InputSubSystem.h"
//#include "IOSubSystem.h"
#include "Config.h"
#include "IMU.h"
#include "ThrustersSubSystem.h"
#include "RotaryCameras.h"
#include "UDPConnection.h"
#include "ms5837.hpp"
#include <iostream>

Rov::Rov()
{
	m_thrusterssubsystem = new ThrustersSubSystem;
	m_udpconnection = new UDPConnection;
	m_imu = new IMU;
	m_rotarycameras = new RotaryCameras;
	//m_depthsensor = new MS5837;
}

void Rov::init()
{
	m_thrusterssubsystem->init();
	//m_udpconnection->init();
	m_imu->init();
	//m_rotarycameras->init();
	//m_depthsensor->init();
	gpioDelay(7000000);
}

void Rov::run()
{
	m_rov_data.m_axis_x = 50;
	m_rov_data.m_axis_w = 50;
	//m_depthsensor->read();
	//m_rov_data.m_depth = m_depthsensor->pressure();
	m_imu->read(m_rov_data);
	//m_udpconnection->read(m_rov_data);
	//m_udpconnection->write(m_rov_data);
	m_thrusterssubsystem->write(m_rov_data);
	//m_rotarycameras->write(m_rov_data);
	std::cout << "depth = " << m_rov_data.m_depth << std::endl;
	std::cout << "yaw = " << m_rov_data.m_yaw << std::endl;
	std::cout << "pitch = " << m_rov_data.m_pitch << std::endl;
	std::cout << "roll = " << m_rov_data.m_roll << std::endl;
}


