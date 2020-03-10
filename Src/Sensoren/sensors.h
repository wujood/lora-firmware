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

// Errors of Sensors
#define VL53L0x_ERROR_GEN_SET						0x8000
#define VL53L0x_ERROR_GEN_RESET						0x7FFF
#define VL53L0x_ERROR_UPPER_LIMIT_SET				0x4000
#define VL53L0x_ERROR_UPPER_LIMIT_RESET				0xBFFF
#define VL53L0x_ERROR_LOWER_LIMIT_SET				0x2000
#define VL53L0x_ERROR_LOWER_LIMIT_RESET				0xDFFF

#define BME280_ERROR_TEMP_UPPER_LIMIT_SET			0x1000
#define BME280_ERROR_TEMP_UPPER_LIMIT_RESET			0xEFFF
#define BME280_ERROR_TEMP_LOWER_LIMIT_SET			0x0800
#define BME280_ERROR_TEMP_LOWER_LIMIT_RESET			0xF7FF
#define BME280_ERROR_HYDR_UPPER_LIMIT_SET			0x0400
#define BME280_ERROR_HYDR_UPPER_LIMIT_RESET			0xFBFF
#define BME280_ERROR_HYDR_LOWER_LIMIT_SET			0x0200
#define BME280_ERROR_HYDR_LOWER_LIMIT_RESET			0xFDFF
#define BME280_ERROR_NULL_PTR_SET                 	0x0100
#define BME280_ERROR_NULL_PTR_RESET                 0xFEFF
#define BME280_ERROR_DEV_NOT_FOUND_SET           	0x0080
#define BME280_ERROR_DEV_NOT_FOUND_RESET            0xFF7F
#define BME280_ERROR_INVALID_LEN_SET              	0x0040
#define BME280_ERROR_INVALID_LEN_RESET              0xFFBF
#define BME280_ERROR_COMM_FAIL_SET                	0x0020
#define BME280_ERROR_COMM_FAIL_RESET                0xFFDF
#define BME280_ERROR_SLEEP_MODE_FAIL_SET          	0x0010
#define BME280_ERROR_SLEEP_MODE_FAIL_RESET          0xFFEF
#define BME280_ERROR_NVM_COPY_FAILED_SET          	0x0008
#define BME280_ERROR_NVM_COPY_FAILED_RESET          0xFFF7
#define TRASHMONITOR_ERROR_IWDG_SET					0x0004
#define TRASHMONITOR_ERROR_IWDG_RESET				0xFFFB

// Range limits
#define VL53L0x_UPPER_LIMIT							2000
#define VL53L0x_LOWER_LIMIT							20
#define BME280_TEMP_UPPER_LIMIT						8500
#define BME280_TEMP_LOWER_LIMIT					   -4000
#define BME280_HYDR_UPPER_LIMIT			            102400
#define BME280_HYDR_LOWER_LIMIT						0

struct bme280_dev Bme280;

struct vl53l0x_dev Vl53l0x;

/*!
 * \brief Reads BME280 registers at address
 *
 * \param [IN] dev_addr Device address
 * \param [IN] reg_addr BME280 register address
 * \param [OUT] reg_data Buffer where to copy the registers data
 * \param [IN] len Length of register to be read
 *
 * \retval rslt Return value 0
 */
int8_t Bme280SpiRead(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);

/*!
 * \brief Writes BME280 registers at address
 *
 * \param [IN] dev_addr Device address
 * \param [IN] reg_addr BME280 register address
 * \param [IN] reg_data Buffer where to copy the registers data
 * \param [IN] len Length of register to be write
 *
 * \retval rslt Return value 0
 */
int8_t Bme280SpiWrite(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);

/*!
 * \brief Force to get Data from sensor
 *
 * \param [IN] dev BME280 device
 * \param [OUT] comp_data Compensated data from sensor
 *
 * \retval rslt Return error value
 */
int8_t StreamBme280DataForcedMode(struct bme280_dev *dev, struct bme280_data *comp_data);

/*!
 * \brief Reads VL53L0x registers at address
 *
 * \param [IN] reg_addr VL53L0x register address
 * \param [OUT] reg_data Buffer where to copy the registers data
 * \param [IN] len Length of register to be read
 *
 * \retval rslt Return value 0
 */
int8_t Vl53l0xI2cRead(uint16_t reg_addr, uint8_t *reg_data, uint16_t len);

/*!
 * \brief Writes VL53L0x registers at address
 *
 * \param [IN] reg_addr VL53L0x register address
 * \param [IN] reg_data Buffer where to copy the registers data
 * \param [IN] len Length of register to be write
 *
 * \retval rslt Return value 0
 */
int8_t Vl53l0xI2cWrite(uint16_t reg_addr, uint8_t *reg_data, uint16_t len);

/*!
 * \brief Force to get Data from VL53L0x
 *
 * \retval Measured distance
 */
int StreamVl53l0xDataForcedMode(void);
#endif /* LORABIB_SENSORS_H_ */
