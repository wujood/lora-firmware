/*
 * vl54l0x.h
 *
 *  Created on: 16.01.2020
 *      Author: Matze
 */

#ifndef DISTANCE_VL54L0X_H_
#define DISTANCE_VL54L0X_H_

#include "i2c.h"

#define calcMacroPeriod(vcsel_period_pclks) ((((uint32_t)2304 * (vcsel_period_pclks) * 1655) + 500) / 1000)
// Encode VCSEL pulse period register value from period in PCLKs
// based on VL53L0X_encode_vcsel_period()
#define encodeVcselPeriod(period_pclks) (((period_pclks) >> 1) - 1)

#define SEQUENCE_ENABLE_FINAL_RANGE 0x80
#define SEQUENCE_ENABLE_PRE_RANGE   0x40
#define SEQUENCE_ENABLE_TCC         0x10
#define SEQUENCE_ENABLE_DSS         0x08
#define SEQUENCE_ENABLE_MSRC        0x04




typedef enum vcselperiodtype { VcselPeriodPreRange, VcselPeriodFinalRange } vcselPeriodType;

typedef int8_t (*vl53l0x_com_fptr_t)(uint16_t reg_addr, uint8_t *data, uint16_t len);
typedef void (*vl53l0x_delay_fptr_t)(uint32_t period);

struct vl53l0x_dev {

	uint8_t deviceAddr;

	/*! Read function pointer */
	vl53l0x_com_fptr_t read;

	/*! Write function pointer */
	vl53l0x_com_fptr_t write;

	vl53l0x_delay_fptr_t delay_ms;

	I2c_t I2c;
};


typedef struct tagSequenceStepTimeouts
    {
      uint16_t pre_range_vcsel_period_pclks, final_range_vcsel_period_pclks;

      uint16_t msrc_dss_tcc_mclks, pre_range_mclks, final_range_mclks;
      uint32_t msrc_dss_tcc_us,    pre_range_us,    final_range_us;
    } SequenceStepTimeouts;

int getSpadInfo(struct vl53l0x_dev *dev, unsigned char *pCount, unsigned char *pTypeIsAperture);
int setVcselPulsePeriod(struct vl53l0x_dev *dev, vcselPeriodType type, uint8_t period_pclks);
int setMeasurementTimingBudget(struct vl53l0x_dev *dev, uint32_t budget_us);
uint32_t getMeasurementTimingBudget(struct vl53l0x_dev *dev);
int initSensor(struct vl53l0x_dev *dev, int bLongRangeMode);
uint16_t readRangeContinuousMillimeters(struct vl53l0x_dev *dev);
int tofReadDistance(struct vl53l0x_dev *dev);

int performSingleRefCalibration(struct vl53l0x_dev *dev, uint8_t vhv_init_byte);

unsigned char readReg(struct vl53l0x_dev *dev, unsigned char ucAddr);
unsigned short readReg16(struct vl53l0x_dev *dev, unsigned char ucAddr);
void readMulti(struct vl53l0x_dev *dev, unsigned char ucAddr, unsigned char *pBuf, int iCount);
void writeReg16(struct vl53l0x_dev *dev, unsigned char ucAddr, unsigned short usValue);
void writeReg(struct vl53l0x_dev *dev, unsigned char ucAddr, unsigned char ucValue);
void writeRegList(struct vl53l0x_dev *dev, unsigned char *ucList);
void writeMulti(struct vl53l0x_dev *dev, unsigned char ucAddr, unsigned char *pBuf, int iCount);
#endif /* DISTANCE_VL54L0X_H_ */
