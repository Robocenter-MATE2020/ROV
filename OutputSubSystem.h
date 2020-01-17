#pragma once

#include "SubSystem.h"
#include "ThrustersSubSystem.h"
#include "rov_device_types.h"
#include "Container.h"

class OutputSubSystem :public SubSystem
{
public:
	OutputSubSystem();
	void init() override;
	void apply(RovData& rov_data)override;
	PolymorphicArray<Output, SIZE_OUTPUT_DEVICES> m_devices;
};


