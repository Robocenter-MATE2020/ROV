#include "IOSubSystem.h"
#include "RovData.h"

IOSubSystem::IOSubSystem()
{
#if UDP_ENABLE
	m_devices.create<UDPConnection>();
#endif
}
void IOSubSystem::init()
{
	invoke_all(m_devices, &InputOutput::init);
}

void IOSubSystem::apply(RovData& rov_data)
{
	invoke_all(m_devices, &InputOutput::write, rov_data);
	invoke_all(m_devices, &InputOutput::read, rov_data);
}
