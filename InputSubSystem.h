#pragma once

#include "SubSystem.h"
#include "RovData.h"
#include "rov_device_types.h"
#include "Config.h"
#include "IMU.h"
#include "Container.h"

class InputSubSystem :public SubSystem
{
public:
	InputSubSystem();
	void init() override;
	void apply(RovData& rov_data) override;
	PolymorphicArray<Input, SIZE_INPUT_DEVICES> m_devices;
};




