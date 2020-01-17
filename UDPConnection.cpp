#include "UDPConnection.h"
#include <memory.h>
#include "Config.h"
#include "RovData.h"
#include <cstddef>
#include <iostream>

UDPConnection::UDPConnection()
{
}

void UDPConnection::init()
{
	m_UDP = socket(AF_INET, SOCK_DGRAM, 0);
	
	bzero((char*)(&m_self_addr), sizeof(m_self_addr));

	m_remote_addr.sin_family = AF_INET;
	m_remote_addr.sin_addr.s_addr = inet_addr("192.168.0.6");
	m_remote_addr.sin_port = htons(5115);
	m_self_addr.sin_family = AF_INET;
	m_self_addr.sin_addr.s_addr = inet_addr("192.168.0.5");
	m_self_addr.sin_port = htons(5115);
	std::cout << bind(m_UDP, (struct sockaddr*) (&m_self_addr), sizeof(m_self_addr)) << std::endl;
	m_timer.start();
}

bool UDPConnection::receivePacket(RovData& rov_data)
{
	char packetBuffer[sizeof(InputPacket)] = { 0 };
	int size = recvfrom(m_UDP, packetBuffer, sizeof(packetBuffer), MSG_DONTWAIT, NULL, NULL);
	//std::cout << size << std::endl;
	if (size > 0)
	{
		for (int i : packetBuffer)
		{
			//std::cout << (int8_t)i << std::endl;
		}
		//std::cout << "recv" << std::endl;
		InputPacket packet;
		memcpy(&packet, packetBuffer, sizeof(packetBuffer));
		parsePayload(packet, rov_data);
		return true;
	}
	else return false;
}

void UDPConnection::sendPacket(const OutputPacket& packet)
{
	//std::cout << m_timer.elapsed() << std::endl;
	if (m_timer.elapsed() > 100)
	{
		sendto(m_UDP, (unsigned char*)&packet, sizeof(packet), 0, (struct sockaddr*) & m_remote_addr, sizeof(m_remote_addr));
		m_timer.start();
	}}


bool UDPConnection::parsePayload(InputPacket& packet, RovData& rov_data)
{
	rov_data.m_axis_x = packet.axisX_p - 100;
	rov_data.m_axis_y = packet.axisY_p - 100;
	rov_data.m_axis_z = packet.axisZ_p - 100;
	rov_data.m_axis_w = packet.axisW_p - 100;
	//std::cout << "axis_x = " << (int)rov_data.m_axis_x << std::endl;
	//std::cout << "axis_y = " << (int)rov_data.m_axis_y << std::endl;
	//std::cout << "axis_z = " << (int)rov_data.m_axis_z << std::endl;
	//std::cout << "axis_w = " << (int)rov_data.m_axis_w << std::endl;
	// ...
}


void UDPConnection::write(RovData& rov_data)
{
	OutputPacket packet;

	//packet.yaw = 99;
	//packet.depth = 16;
	//packet.pitch = 19;
	//packet.roll = 129;

	packet.yaw = rov_data.m_yaw;
	packet.depth = rov_data.m_depth;
	packet.roll = rov_data.m_roll;
	packet.pitch = rov_data.m_pitch;
	//packet.temperature = rov_data.m_temperature;
	//packet.core = rov_data.m_is_core;

	sendPacket(packet);
}

void UDPConnection::read(RovData& rov_data)
{
	receivePacket(rov_data);
}
