#ifndef UDP_CONNECTION_H
#define UDP_CONNECTION_H

#include <cstdint>
#include "rov_device_types.h"
#include "Timer.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>


struct InputPacket
{
	//signed char button_data1 = 0;
	//signed char button_data2 = 0;
	//signed char button_data3 = 0;
	int8_t axisX_p = 0; 
	int8_t axisY_p = 0;    
	int8_t axisZ_p = 0;   
	int8_t axisW_p = 0;
	//int8_t camera_rotate = 0;
	//int8_t manipulator_rotate = 0;
	//float Pitch = 149.0f;
	//float Roll = 0.27f;
};

struct OutputPacket
{
	float yaw = 0;
	float roll = 0;
	float pitch = 0;
	float depth = 0;
};

class UDPConnection : public InputOutput
{
public:
	UDPConnection();
	void init();
	void write(RovData& rov_data);
	void read(RovData& rov_data);
	bool receivePacket(RovData& rov_data);
	void sendPacket(const OutputPacket& packet);
	bool parsePayload(InputPacket& packet, RovData& rov_data);
private:
	int m_UDP;
	sockaddr_in m_self_addr;
	sockaddr_in m_remote_addr;
	Timer m_timer;
	bool is_settings = false;
	bool button_3_release = false;
};

#endif