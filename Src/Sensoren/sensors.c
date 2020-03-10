/*
 * sensors.c
 *
 *  Created on: 15.01.2020
 *      Author: Matze
 */
#include "bme280.h"
#include "sensors.h"
#include "vl53l0x.h"
#include "i2c-board.h"
#include "delay.h"
//#include "required_version.h"
//#include "get_nucleo_serial_comm.h"
//#include <windows.h>

int8_t Bme280SpiRead(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len)
{
	int8_t rslt = 0; /* Return 0 for Success, non-zero for failure */

	uint8_t i;

	//NSS = 0;
	GpioWrite(&Bme280.Spi.Nss, 0);

	SpiInOut(&Bme280.Spi, reg_addr | 0x80);

	for (i = 0; i < len; i++)
	{
		reg_data[i] = SpiInOut(&Bme280.Spi, 0);
	}

	//NSS = 1;
	GpioWrite(&Bme280.Spi.Nss, 1);
	/*
	 * The parameter dev_id can be used as a variable to select which Chip Select pin has
	 * to be set low to activate the relevant device on the SPI bus
	 */

	/*
	 * Data on the bus should be like
	 * |----------------+---------------------+-------------|
	 * | MOSI           | MISO                | Chip Select |
	 * |----------------+---------------------|-------------|
	 * | (don't care)   | (don't care)        | HIGH        |
	 * | (reg_addr)     | (don't care)        | LOW         |
	 * | (don't care)   | (reg_data[0])       | LOW         |
	 * | (....)         | (....)              | LOW         |
	 * | (don't care)   | (reg_data[len - 1]) | LOW         |
	 * | (don't care)   | (don't care)        | HIGH        |
	 * |----------------+---------------------|-------------|
	 */

	return rslt;
}

int8_t Bme280SpiWrite(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len)
{
	int8_t rslt = 0; /* Return 0 for Success, non-zero for failure */

	uint8_t i;

	//NSS = 0;
	GpioWrite(&Bme280.Spi.Nss, 0);

	SpiInOut(&Bme280.Spi, reg_addr & 0x7F);
	for (i = 0; i < len; i++)
	{
		SpiInOut(&Bme280.Spi, reg_data[i]);
	}

	//NSS = 1;
	GpioWrite(&Bme280.Spi.Nss, 1);

	/*
	 * The parameter dev_id can be used as a variable to select which Chip Select pin has
	 * to be set low to activate the relevant device on the SPI bus
	 */

	/*
	 * Data on the bus should be like
	 * |---------------------+--------------+-------------|
	 * | MOSI                | MISO         | Chip Select |
	 * |---------------------+--------------|-------------|
	 * | (don't care)        | (don't care) | HIGH        |
	 * | (reg_addr)          | (don't care) | LOW         |
	 * | (reg_data[0])       | (don't care) | LOW         |
	 * | (....)              | (....)       | LOW         |
	 * | (reg_data[len - 1]) | (don't care) | LOW         |
	 * | (don't care)        | (don't care) | HIGH        |
	 * |---------------------+--------------|-------------|
	 */

	return rslt;
}

int8_t StreamBme280DataForcedMode(struct bme280_dev *dev, struct bme280_data *comp_data)
{
	int8_t rslt;
	uint8_t settings_sel;

//    struct bme280_data comp_data;
	/* Recommended mode of operation: Indoor navigation */
	dev->settings.osr_h = BME280_OVERSAMPLING_1X;
	dev->settings.osr_t = BME280_OVERSAMPLING_2X;
	dev->settings.filter = BME280_FILTER_COEFF_16;

	settings_sel = BME280_OSR_TEMP_SEL | BME280_OSR_HUM_SEL | BME280_FILTER_SEL;

	rslt = bme280_set_sensor_settings(settings_sel, dev);
	if (rslt != BME280_OK)
	{
//        fprintf(stderr, "Failed to set sensor settings (code %+d).", rslt);
		return rslt;
	}

	rslt = bme280_set_sensor_mode(BME280_FORCED_MODE, dev);
	if (rslt != BME280_OK)
	{
//            fprintf(stderr, "Failed to set sensor mode (code %+d).", rslt);
	}
	/* Wait for the measurement to complete and print data @25Hz */
	dev->delay_ms(300);
	rslt = bme280_get_sensor_data(BME280_TEMP | BME280_HUM, comp_data, dev);
	if (rslt != BME280_OK)
	{
//            fprintf(stderr, "Failed to get sensor data (code %+d).", rslt);
	}
	// print_sensor_data(&comp_data);
	dev->delay_ms(1);

	return rslt;
}

// Abstandssensor VL53L0x

int8_t Vl53l0xI2cWrite(uint16_t reg_addr, uint8_t *reg_data, uint16_t len)
{
	I2cWriteBuffer(&Vl53l0x.I2c, Vl53l0x.deviceAddr, reg_addr, reg_data, len);
	return 0;
}
int8_t Vl53l0xI2cRead(uint16_t reg_addr, uint8_t *reg_data, uint16_t len)
{
	I2cReadBuffer(&Vl53l0x.I2c, Vl53l0x.deviceAddr, reg_addr, reg_data, len);
	return 0;
}

int StreamVl53l0xDataForcedMode(void)
{
	int i;
	int iDistance;

	for (i = 0; i < 1; i++) // read values 20 times a second for 1 minute
	{
		iDistance = tofReadDistance(&Vl53l0x);
		DelayMs(50); // 50ms
	}
	return iDistance;
}
