#ifndef ADDITIONALFUNCTION_H
#define ADDITIONALFUNCTION_H

constexpr long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

inline int constrain(int x, int min, int max)
{
	if (x > max) return max;
	if (x < min) return min;
	return x;
}

#endif 
