#ifndef MS5837_HPP
#define MS5837_HPP

#include <stdint.h>

class MS5837 {
public:
// Плотность жидкости в кг/м^3 (надо уточнить)
	static constexpr float density = 1000.f;

	static const uint8_t crc4(uint16_t* n_prom);
	MS5837() { };

	const bool init();
	const bool read();

	// Давление в миллибарах
	const float pressure() const;
	// Температура в градусах цельсия
	const float temperature() const;
	// Глубина в метрах
	const float depth() const;
private:
	uint16_t C[8];
	uint32_t D1, D2;
	int32_t TEMP;
	int32_t P;
	int fd;
};


#endif
