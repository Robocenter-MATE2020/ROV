#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <memory.h>
#include "Timer.h"
#include "Config.h"
#include "RovData.h"
#include <cstddef>
#include "rov_device_types.h"


struct InputPacket
{
	signed char button_data1 = 0;
	signed char button_data2 = 0;
	signed char button_data3 = 0;
	int8_t axisX_p = 0; 
	int8_t axisY_p = 0;    
	int8_t axisZ_p = 0;   
	int8_t axisW_p = 0;
	int8_t camera_rotate = 0;
	int8_t manipulator_rotate = 0;
	//float Pitch = 149.0f;
	//float Roll = 0.27f;
};

struct OutputPacket
{
	float yaw = 0;
	float roll = 0;
	float pitch = 0;
	float depth = 0;
	float temperature = 0;
	uint8_t core = 0;
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
