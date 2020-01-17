//#ifndef PIDREGULATOR_H
//#define PIDREGULATOR_H
//
//#include "Timer.h"
//
//class PIDRegulator
//{
//
//public:
//	PIDRegulator();
//	PIDRegulator(float pK, float iK, float dK);
//	void set_k(float pK, float iK, float dK);
//	int apply(float to_set, float current, bool flag = false);
//	void set_pk(float pk);
//	void set_ik(float ik);
//	void set_dk(float dk);
//private:
//	float m_error_old = 0;
//	float m_integral = 0;
//	float m_pK = 0;
//	float m_dK = 0;
//	float m_iK = 0;
//	bool is_first = true;
//	Timer m_timer;
//};
//#endif