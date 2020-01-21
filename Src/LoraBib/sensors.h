/*
 * sensors.h
 *
 *  Created on: 15.01.2020
 *      Author: Matze
 */

#ifndef LORABIB_SENSORS_H_
#define LORABIB_SENSORS_H_

#include "bme280.h"
#include "spi.h"
#include "vl53l0x.h"

#define BME280_MOSI                                  PA_7    // ok
#define BME280_MISO                                  PA_6    // ok
#define BME280_SCLK                                  PA_5    // ok

#define BME280_NSS                                   PB_5

#define VL53L0x_SCL									 PB_8
#define VL53L0x_SDA									 PB_7


struct bme280_dev bme280;

struct vl53l0x_dev vl53l0x;

void user_delay_ms(uint32_t period);

int8_t bme280_spi_read(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);

int8_t bme280_spi_write(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);

int8_t stream_bme280_data_forced_mode(struct bme280_dev *dev, struct bme280_data *comp_data);

int8_t vl53l0x_i2c_read(uint16_t reg_addr, uint8_t *reg_data, uint16_t len);

int8_t vl53l0x_i2c_write(uint16_t reg_addr, uint8_t *reg_data, uint16_t len);

int stream_vl53l0x_data_forced_mode(void);
#endif /* LORABIB_SENSORS_H_ */
