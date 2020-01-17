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

Rov::Rov()
{
	m_thrusterssubsystem = new ThrustersSubSystem;
	m_udpconnection = new UDPConnection;
	m_imu = new IMU;
	m_rotarycameras = new RotaryCameras;
}

void Rov::init()
{
	m_thrusterssubsystem->init();
	m_udpconnection->init();
	m_imu->init();
	m_rotarycameras->init();
	gpioDelay(7000000);
}

void Rov::run()
{
	m_imu->read(m_rov_data);
	m_udpconnection->read(m_rov_data);
	m_udpconnection->write(m_rov_data);
	m_thrusterssubsystem->write(m_rov_data);
	m_rotarycameras->write(m_rov_data);
}


