#include "OutputSubSystem.h"
#include "RovData.h"


 OutputSubSystem::OutputSubSystem()
{
#if MANIPULATOR_ENABLE
	m_devices.create<ROVBuilderManipulator>();
#endif
#if THRUSTERSSUBSYSTEM_ENABLE
	m_devices.create<ThrustersSubSystem>();
#endif
#if ROTARYCAMERA_ENABLE
	m_devices.create<Cameras>();
#endif
#if COILER_ENABLE
	m_devices.create<Coiler>(); 
#endif
#if HELIX_ENABLE
	m_devices.create<Helix>();
#endif
#if ELECTROMAGNET_ENABLE
	m_devices.create<Electromagnet>();
#endif
}

void OutputSubSystem::init()
{
	invoke_all(m_devices, &Output::init);
}

void OutputSubSystem::apply(RovData& rov_data)
{
	invoke_all(m_devices, &Output::write, rov_data);
}
