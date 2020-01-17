#ifndef THRUSTERSSUBSYSTEM_H
#define THRUSTERSSUBSYSTEM_H

#include "BrushlessMotor.h"
#include "Config.h"
#include "rov_device_types.h"
#include "Timer.h"

class PIDRegulator;
class BrushlessMotor;
struct RovData;

class ThrustersSubSystem : public Output
{
public:
	ThrustersSubSystem();
	void init();
	void write(RovData& rov_data);
	void set_power(int8_t x, int8_t y, int8_t w, int8_t z, RovData& rov_data);
private:
	/*void applyYawReg(int8_t power[], RovData& rov_data);
	void applyDepthReg(int8_t power[], RovData& rov_data);
	void applyPitchReg(int8_t power[], RovData& rov_data);
	void applyRollReg(int8_t power[], RovData& rov_data);*/
	//void regulator_check(int8_t power[], RovData& rov_data);
	void manual_regulator(int8_t power[], int8_t x, int8_t y, int8_t w, int8_t z, RovData& rov_data);
	BrushlessMotor m_motors[THRUSTER_SIZE];
	//PIDRegulator m_depth_reg;
	//PIDRegulator m_pitch_reg;
	//PIDRegulator m_roll_reg;
	//PIDRegulator m_yaw_reg;
	Timer timer_;
	bool flag_depth = false;
	bool flag_yaw = false;
	uint8_t regulator_type = 0;
};

#endif