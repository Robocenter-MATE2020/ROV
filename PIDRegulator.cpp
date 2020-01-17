//#include "PIDRegulator.h"
//#include "Config.h"
//#include "AdditionalFunctions.h"
//
//PIDRegulator::PIDRegulator()
//{
//}
//
//PIDRegulator::PIDRegulator(float pK, float iK, float dK)
//{
//	m_pK = pK;
//	m_dK = dK;
//	m_iK = iK;
//}
//
//int PIDRegulator::apply(float to_set, float current, bool flag = false)
//{
//	if (!m_timer.is_started()) m_timer.start();
//	float result;
//	float integral_part;
//	float proportional_part;
//	float differential_part;
//	float time_elaplsed = (m_timer.elapsed() / 1000.00) < 0.0000001 ?  0.000001 : m_timer.elapsed() / 1000.00;
//
//	m_timer.stop();
//	float error = to_set - current;
//	if (!flag)
//	{
//		if (error < 0) error += 360;
//		if (error > 180) error -= 360;
//	}
//	m_integral = constrain(error * time_elaplsed + m_integral, -MAX_POWER, MAX_POWER);
//	proportional_part = m_pK * error;
//	integral_part = m_iK * m_integral;
//	differential_part = m_dK * (error - m_error_old) / time_elaplsed;
//	result = proportional_part + integral_part + differential_part;
//	m_error_old = error;
//	m_timer.start();
//	result = constrain(result, -MAX_POWER, MAX_POWER);
//	return result;
//}
//
//void PIDRegulator::set_k(float pK, float iK, float dK)
//{
//	m_pK = pK;
//	m_dK = iK;
//	m_iK = dK;
//}
//
//void PIDRegulator::set_pk(float pK)
//{
//	m_pK = pK;
//}
//
//void PIDRegulator::set_ik(float iK)
//{
//	m_iK = iK;
//}
//
//void PIDRegulator::set_dk(float dK)
//{
//	m_dK = dK;
//}