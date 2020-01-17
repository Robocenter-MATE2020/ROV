#ifndef ROV_DEVICE_TYPES_H
#define ROV_DEVICE_TYPES_H

#include "RovData.h"

class Input
{
public:
	virtual void init() = 0;
	virtual void read(RovData& rov_data) = 0;
};

class Output
{
public:
	virtual void init() = 0;
	virtual void write(RovData& rov_data) = 0;
};

class InputOutput
{
public:
	virtual void init() = 0;
	virtual void read(RovData& rov_data) = 0;
	virtual void write(RovData& rov_data) = 0;
};

#endif