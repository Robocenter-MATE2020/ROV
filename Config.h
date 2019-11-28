#ifndef CONFIG_H
#define CONFIG_H

#include "Timer.h"

/////////////////////////////////////////////////
//////////////////Devices////////////////////////
/////////////////////////////////////////////////


#define OUTPUTSUBSYSTEM_ENABLE				0
#define INPUTSUBSYSTEM_ENABLE				1
#define IOSUBSYSTEM_ENABLE					0

#define MANIPULATOR_ENABLE					0
#define THRUSTERSSUBSYSTEM_ENABLE			0
#define ROTARYCAMERA_ENABLE					0

#define COILER_ENABLE						0
#define HELIX_ENABLE						0
#define ELECTROMAGNET_ENABLE				0

#define METALDETECTOR_ENABLE				0
#define TEMPERATURE_SENSOR_ENABLE			0
#define DEPTH_SENSOR_ENABLE					0
#define IMU_ENABLE							1

#define UDP_ENABLE							0

#define __MS5803__							0
#define __MS5837__							1

constexpr int SIZE_OUTPUT_DEVICES = 

MANIPULATOR_ENABLE + 
THRUSTERSSUBSYSTEM_ENABLE + 
ROTARYCAMERA_ENABLE + 
COILER_ENABLE + 
HELIX_ENABLE + 
ELECTROMAGNET_ENABLE;

constexpr int SIZE_INPUT_DEVICES =  

IMU_ENABLE + 
DEPTH_SENSOR_ENABLE +
TEMPERATURE_SENSOR_ENABLE + 
METALDETECTOR_ENABLE;

constexpr int SIZE_IO_DEVICES =    

UDP_ENABLE;

constexpr int SUBSYSTEM_SIZE =     

INPUTSUBSYSTEM_ENABLE + 
OUTPUTSUBSYSTEM_ENABLE + 
IOSUBSYSTEM_ENABLE;

constexpr uint8_t MAX_POWER	=					85;
constexpr float DEFAULT_PITCH =				149.0f;
constexpr float DEFAULT_ROLL =				 0.27f;

/////////////////////////////////////////////////
/////////////ROVBuilderManipulator///////////////
/////////////////////////////////////////////////

constexpr uint8_t MANIPULATOR_RELEASE_LEFT =	29;
constexpr uint8_t MANIPULATOR_RELEASE_RIGHT =	27;

constexpr uint8_t MANIPULATOR_ROTATE_LEFT =		31;
constexpr uint8_t MANIPULATOR_ROTATE_RIGHT =	33;

/////////////////////////////////////////////////
//////////////ThrustersSubSystem/////////////////
/////////////////////////////////////////////////

constexpr uint8_t H_FRONT_LEFT =				5;
constexpr bool H_FRONT_LEFT_INVERSE =		false;
constexpr uint8_t H_FRONT_RIGHT =				3;
constexpr bool H_FRONT_RIGHT_INVERSE =		 true;
constexpr uint8_t H_BACK_LEFT =					4;
constexpr bool H_BACK_LEFT_INVERSE =		 true;
constexpr uint8_t H_BACK_RIGHT =				6;
constexpr bool H_BACK_RIGHT_INVERSE =		false;

constexpr uint8_t V_FRONT_LEFT =				2;
constexpr bool V_FRONT_LEFT_INVERSE =		 true;
constexpr uint8_t V_FRONT_RIGHT =				44;
constexpr bool V_FRONT_RIGHT_INVERSE =		false;
constexpr uint8_t V_BACK_LEFT =				   46;
constexpr bool V_BACK_LEFT_INVERSE =		 true;
constexpr uint8_t V_BACK_RIGHT =			   7;
constexpr bool V_BACK_RIGHT_INVERSE =		false;

constexpr uint8_t THRUSTER_SIZE =				8;


/////////////////////////////////////////////////
//////////////////RotaryCamera///////////////////
/////////////////////////////////////////////////

constexpr uint8_t ROTARY_CAMERA_1 =				40;
constexpr uint8_t ROTARY_CAMERA_2 =				41;

/////////////////////////////////////////////////
/////////////////UDPConnection///////////////////
/////////////////////////////////////////////////


/////////////////////////////////////////////////
///////////////////Payloads//////////////////////
/////////////////////////////////////////////////

#endif