#ifndef ROTARYCAMERAS_H
#define ROTARYCAMERAS_H

#include "RotaryCameras.h"

#define FRONT_CAMERA_PIN 00
#define BACK_CAMERA_PIN 00

RotaryCameras::RotaryCameras()
{
	m_front_camera = new RotaryCamera(FRONT_CAMERA_PIN);
	m_front_camera = new RotaryCamera(BACK_CAMERA_PIN);
}

void RotaryCameras::init()
{
	m_front_camera->init();
	m_back_camera->init();
	m_front_camera->setRotationTime(30);
	m_back_camera->setRotationTime(30);
}

void RotaryCameras::write(RovData& rov_data)
{
	m_front_camera->write(rov_data.m_rotary_camera[0]);
	m_back_camera->write(rov_data.m_rotary_camera[1]);
}

#endif