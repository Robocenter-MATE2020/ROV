#include "InputSubSystem.h"
#include "RovData.h"


InputSubSystem::InputSubSystem()
{
#if TEMPERATURE_SENSOR_ENABLE
	m_devices.create<TemperatureSensor>();
#endif
#if DEPTH_SENSOR_ENABLE
#if __MS5803__
	m_devices.create<DepthSensorMS5803>();
#endif
#if __MS5837__
	m_devices.create<DepthSensorMS5837>();
#endif
#endif
#if IMU_ENABLE
	m_devices.create<IMU>();
#endif
#if METALDETECTOR_ENABLE
	m_devices.create<MetalDetector>();
#endif

}

void InputSubSystem::init()
{
	invoke_all(m_devices, &Input::init);
}

void InputSubSystem::apply(RovData& rov_data)
{
	invoke_all(m_devices, &Input::read, rov_data);
}
