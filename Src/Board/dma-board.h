/*
 * dma-board.h
 *
 *  Created on: 27.02.2020
 *      Author: Matze
 */

#ifndef BOARD_DMA_BOARD_H_
#define BOARD_DMA_BOARD_H_

#include "spi-board.h"

void DmaInit(SPI_HandleTypeDef *hspi, SpiId_t spiId);

void DmaDeInit(void);

#endif /* BOARD_DMA_BOARD_H_ */
