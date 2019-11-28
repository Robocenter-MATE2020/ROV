
#include "RotaryCamera.h"
#include "RovData.h"
#include "rov_device_types.h"

class RotaryCameras : public Output
{
public:
	RotaryCameras();
	void init();
	void write(RovData& rov_data);
private:
	RotaryCamera* m_front_camera;
	RotaryCamera* m_back_camera;
};