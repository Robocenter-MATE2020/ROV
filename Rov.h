#ifndef ROV_H
#define ROV_H

#include "RovData.h"

class ThrustersSubSystem;
class UDPConnection;
class IMU;
class RotaryCameras;

class Rov {
public:
	Rov();
	void init();
	void run();
	RovData m_rov_data;
	ThrustersSubSystem* m_thrusterssubsystem;
	UDPConnection* m_udpconnection;
	IMU* m_imu;
	RotaryCameras* m_rotarycameras;
	//PolymorphicArray<SubSystem, SUBSYSTEM_SIZE> m_subsystem;
};

#endif
