#ifndef ROTARYCAMERAS_H
#define ROTARYCAMERAS_H

#include "rov_device_types.h"

struct RovData;
class RotaryCamera;

class RotaryCameras : public Output
{
public:
	RotaryCameras();
	void init();
	void write(RovData& rov_data);
private:
	RotaryCamera* m_front_camera;
	//RotaryCamera* m_back_camera;
};

#endif