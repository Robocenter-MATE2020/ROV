#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include "ms5837.hpp"
#include "logging.hpp"

const uint8_t MS5837::crc4(uint16_t* n_prom) {
  uint16_t n_rem = 0;

	n_prom[0] = ((n_prom[0]) & 0x0FFF);
	n_prom[7] = 0;

	for ( uint8_t i = 0 ; i < 16; i++ ) {
		if ( i%2 == 1 ) {
			n_rem ^= (uint16_t)((n_prom[i>>1]) & 0x00FF);
		} else {
			n_rem ^= (uint16_t)(n_prom[i>>1] >> 8);
		}
		for ( uint8_t n_bit = 8 ; n_bit > 0 ; n_bit-- ) {
			if ( n_rem & 0x8000 ) {
				n_rem = (n_rem << 1) ^ 0x3000;
			} else {
				n_rem = (n_rem << 1);
			}
		}
	}

	n_rem = ((n_rem >> 12) & 0x000F);

	return n_rem ^ 0x00;
}

const bool MS5837::init() {
  log::info("Started ms5837 init; opening i2c device file");
  if((fd = open("/dev/i2c-0", O_RDWR)) < 0) { // Может надо будет поменять
    log::interprit_errno();
    return false;
  }

  log::info("Setting i2c to ms5837 adress");
  if(ioctl(fd, I2C_SLAVE, 0x76) < 0) { // 0x76 - адрес датчика
    log::interprit_errno();
    return false;
  }

  log::info("Resetting ms5837");
  uint8_t command = 0x1E; // Сброс настроек датчика
  if(write(fd, &command, 1) != 1) {
    log::interprit_errno();
    return false;
  }

  usleep(10); // Ждём сброса

  log::info("Reading ms5837 calibration values");
  for (uint8_t i = 0; i != 7; ++i) {
    uint8_t command = 0xA0 + i * 2;
    if (write(fd, &command, 1) != 1) {
      log::interprit_errno();
      return false;
    }
    if (::read(fd, (C + i), 2) != 2) {
      log::interprit_errno();
      return false;
    }
    C[i] = (C[i] & 0xFF) << 8 | C[i] >> 8;
  }
  if (C[0] >> 12 != crc4(C)) {
    log::error("Recieved and calculated ms5837's crc4 mismatch");
    return false;
  }
  return true;
}

const bool MS5837::read() {
  uint8_t command = 0x00; // Считать аналоговые данные
  log::info("Reading actual data");
  if (write(fd, &command, 1) != 1) {
    log::interprit_errno();
    return false;
  }
  usleep(1000);

  command = 0x44; // Получить рассчитанное D1
  log::info("Reading ms5837 D1");
  if (write(fd, &command, 1) != 1) {
    log::interprit_errno();
    return false;
  }
  usleep(2200); // Считает

  if (::read(fd, &D1, 3) != 3) {
    log::interprit_errno();
    return false;
  }
  // Порядок байт
  D1 = ((D1 & 0xFF) << 16) | (D1 & 0xFF00) | ((D1 & 0xFF0000) >> 16);

  command = 0x54; // Получить рассчитанное D2
  log::info("Reading ms5837 D2");
  if (write(fd, &command, 1) != 1) {
    log::interprit_errno();
    return false;
  }
  usleep(2200); // Считает

  if (::read(fd, &D2, 3) != 3) {
    log::interprit_errno();
    return false;
  }
  // Порядок байт
  D2 = ((D2 & 0xFF) << 16) | (D2 & 0xFF00) | ((D2 & 0xFF0000) >> 16);

  // Оставь надежду, всяк сюда входящий
  // Рассчёт температуры и давления из показаний датчика
  int32_t dT = 0;
	int64_t SENS = 0;
	int64_t OFF = 0;
	int32_t SENSi = 0;
	int32_t OFFi = 0;
	int32_t Ti = 0;
	int64_t OFF2 = 0;
	int64_t SENS2 = 0;

	dT = D2 - (uint32_t)(C[5]) * 256l;
	SENS = (int64_t)(C[1]) * 65536l  + (int64_t)(C[3]) * dT / 128l;
	OFF  = (int64_t)(C[2]) * 131072l + (int64_t)(C[4]) * dT / 64l;
	P = (D1 * SENS / 2097152l - OFF) / (32768l);

	TEMP = 2000l + (int64_t)(dT) * C[6] / 8388608LL;

	if(TEMP / 100 < 20) {
		Ti = (11 * (int64_t)(dT) * (int64_t)(dT)) / 34359738368LL;
		OFFi  = (31 * (TEMP-2000) * (TEMP-2000)) / 8;
		SENSi = (63 * (TEMP-2000) * (TEMP-2000)) / 32;
	}

	OFF2 = OFF - OFFi;
	SENS2 = SENS - SENSi;

	TEMP = TEMP - Ti;

	P = (((D1 * SENS2) / 2097152l - OFF2) / 32768l);
  return true;
}

const float MS5837::pressure() const {
  return P / 100.f;
}

const float MS5837::temperature() const {
  return TEMP / 100.f;
}

const float MS5837::depth() const {
  return (pressure() * 100.f - 101300.f) / (density * 9.80665f);
}
