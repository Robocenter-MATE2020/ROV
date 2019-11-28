#ifndef UDP_CONNECTION_H
#define UDP_CONNECTION_H

#include "UDPConnection.h"

UDPConnection::UDPConnection()
{
}

void UDPConnection::init()
{
	m_UDP = socket(AF_INET, SOCK_DGRAM, 0);
	m_self_addr.sin_family = AF_INET;
	m_self_addr.sin_addr.s_addr = ((in_addr_t) 0x00000000); //как указать ip???
	m_self_addr.sin_port = htons(5000);
	bind(m_UDP, (struct sockaddr*) & m_self_addr, sizeof(m_self_addr));

	m_remote_addr.sin_family = AF_INET;
	m_remote_addr.sin_addr.s_addr = ((in_addr_t) 0x00000000); //как указать ip???
	m_remote_addr.sin_port = htons(5000);
	connect(m_UDP, (struct sockaddr*) & m_remote_addr, sizeof(m_remote_addr));

	m_timer.start();
}

bool UDPConnection::receivePacket(RovData& rov_data)
{
	char packetBuffer[sizeof(InputPacket)] = { 0 };
	if (recv(m_UDP, packetBuffer, sizeof(packetBuffer), 0))
	{
		InputPacket packet;
		memcpy(&packet, packetBuffer, sizeof(packetBuffer));
		parsePayload(packet, rov_data);
		return true;
	}
	else return false;
}

void UDPConnection::sendPacket(const OutputPacket& packet)
{
	if (m_timer.elapsed() > 250)
	{
		send(m_UDP, (unsigned char*)&packet, sizeof(packet), 0);
		/*m_udp.beginPacket(m_remote_ip, m_remote_port);
		m_udp.write((byte*)&packet, sizeof(packet));
		m_udp.endPacket();*/
		m_timer.start();
	}
}

bool UDPConnection::parsePayload(InputPacket& packet, RovData& rov_data)
{
	rov_data.m_axis_x = packet.axisX_p;
	rov_data.m_axis_y = packet.axisY_p;
	rov_data.m_axis_z = packet.axisZ_p;
	rov_data.m_axis_w = packet.axisW_p;
	// ...
}


void UDPConnection::write(RovData& rov_data)
{
	OutputPacket packet;

	packet.yaw = rov_data.m_yaw;
	packet.depth = rov_data.m_depth;
	packet.roll = rov_data.m_roll;
	packet.pitch = rov_data.m_pitch;
	packet.temperature = rov_data.m_temperature;
	packet.core = rov_data.m_is_core;

	sendPacket(packet);
}

void UDPConnection::read(RovData& rov_data)
{
	receivePacket(rov_data);
}

#endif