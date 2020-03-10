/*
 * dma-board.c
 *
 *  Created on: 27.02.2020
 *      Author: Matze
 */
#include "stm32l4xx.h"
#include "dma-board.h"
#include "board-config.h"
#include "Spi.h"

static DMA_HandleTypeDef hdma_tx[2];
static DMA_HandleTypeDef hdma_rx[2];


void DmaInit(SPI_HandleTypeDef *hspi, SpiId_t spiId)
{
    /* Enable DMA clock */
	__HAL_RCC_DMA1_CLK_ENABLE();

	if (spiId == SPI_1)
	{
		/*##-3- Configure the DMA ##################################################*/
		/* Configure the DMA handler for Transmission process */
		hdma_tx[0].Instance = DMA_SPI1_TX;
		hdma_tx[0].Init.Request = DMA_SPI1_TX_REQ;
		hdma_tx[0].Init.Direction = DMA_MEMORY_TO_PERIPH;
		hdma_tx[0].Init.PeriphInc = DMA_PINC_DISABLE;
		hdma_tx[0].Init.MemInc = DMA_MINC_ENABLE;
		hdma_tx[0].Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
		hdma_tx[0].Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
		hdma_tx[0].Init.Mode = DMA_NORMAL;
		hdma_tx[0].Init.Priority = DMA_PRIORITY_HIGH;

		HAL_DMA_Init(&hdma_tx[0]);

		/* Associate the initialized DMA handle to the the SPI handle */
		__HAL_LINKDMA(hspi, hdmatx, hdma_tx[0]);

		/* Configure the DMA handler for Transmission process */
		hdma_rx[0].Instance = DMA_SPI1_RX;
		hdma_rx[0].Init.Request = DMA_SPI1_RX_REQ;
		hdma_rx[0].Init.Direction = DMA_PERIPH_TO_MEMORY;
		hdma_rx[0].Init.PeriphInc = DMA_PINC_DISABLE;
		hdma_rx[0].Init.MemInc = DMA_MINC_ENABLE;
		hdma_rx[0].Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
		hdma_rx[0].Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
		hdma_rx[0].Init.Mode = DMA_NORMAL;
		hdma_rx[0].Init.Priority = DMA_PRIORITY_HIGH;

		HAL_DMA_Init(&hdma_rx[0]);

		/* Associate the initialized DMA handle to the the SPI handle */
		__HAL_LINKDMA(hspi, hdmarx, hdma_rx[0]);

		/*##-4- Configure the NVIC for DMA #########################################*/
		/* NVIC configuration for DMA transfer complete interrupt (SPI1_TX) */
		HAL_NVIC_SetPriority(SPI1_DMA_TX_IRQn, 1, 3);
		HAL_NVIC_EnableIRQ(SPI1_DMA_TX_IRQn);

		/* NVIC configuration for DMA transfer complete interrupt (SPI1_RX) */
		HAL_NVIC_SetPriority(SPI1_DMA_RX_IRQn, 1, 2);
		HAL_NVIC_EnableIRQ(SPI1_DMA_RX_IRQn);
	}
	else
	{
		/*##-3- Configure the DMA ##################################################*/
		/* Configure the DMA handler for Transmission process */
		hdma_tx[1].Instance = DMA_SPI2_TX;
		hdma_tx[1].Init.Request = DMA_SPI2_TX_REQ;
		hdma_tx[1].Init.Direction = DMA_MEMORY_TO_PERIPH;
		hdma_tx[1].Init.PeriphInc = DMA_PINC_DISABLE;
		hdma_tx[1].Init.MemInc = DMA_MINC_ENABLE;
		hdma_tx[1].Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
		hdma_tx[1].Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
		hdma_tx[1].Init.Mode = DMA_NORMAL;
		hdma_tx[1].Init.Priority = DMA_PRIORITY_LOW;

		HAL_DMA_Init(&hdma_tx[1]);

		/* Associate the initialized DMA handle to the the SPI handle */
		__HAL_LINKDMA(hspi, hdmatx, hdma_tx[1]);

		/* Configure the DMA handler for Transmission process */
		hdma_rx[1].Instance = DMA_SPI2_RX;
		hdma_rx[1].Init.Request = DMA_SPI2_RX_REQ;
		hdma_rx[1].Init.Direction = DMA_PERIPH_TO_MEMORY;
		hdma_rx[1].Init.PeriphInc = DMA_PINC_DISABLE;
		hdma_rx[1].Init.MemInc = DMA_MINC_ENABLE;
		hdma_rx[1].Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
		hdma_rx[1].Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
		hdma_rx[1].Init.Mode = DMA_NORMAL;
		hdma_rx[1].Init.Priority = DMA_PRIORITY_HIGH;

		HAL_DMA_Init(&hdma_rx[1]);

		/* Associate the initialized DMA handle to the the SPI handle */
		__HAL_LINKDMA(hspi, hdmarx, hdma_rx[1]);

		/*##-4- Configure the NVIC for DMA #########################################*/
		/* NVIC configuration for DMA transfer complete interrupt (SPI1_TX) */
		HAL_NVIC_SetPriority(SPI2_DMA_TX_IRQn, 1, 1);
		HAL_NVIC_EnableIRQ(SPI2_DMA_TX_IRQn);

		/* NVIC configuration for DMA transfer complete interrupt (SPI1_RX) */
		HAL_NVIC_SetPriority(SPI2_DMA_RX_IRQn, 1, 0);
		HAL_NVIC_EnableIRQ(SPI2_DMA_RX_IRQn);

	}
}

void DmaDeInit(void)
{
	/*##-3- Disable the DMA ####################################################*/
	/* De-Initialize the DMA associated to transmission process */
	HAL_DMA_DeInit(&hdma_tx[0]);
	/* De-Initialize the DMA associated to reception process */
	HAL_DMA_DeInit(&hdma_rx[0]);
	/*##-3- Disable the DMA ####################################################*/
	/* De-Initialize the DMA associated to transmission process */
	HAL_DMA_DeInit(&hdma_tx[1]);
	/* De-Initialize the DMA associated to reception process */
	HAL_DMA_DeInit(&hdma_rx[1]);
}

/******************************************************************************/
/*                 STM32L4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32l4xx.s).                                               */
/******************************************************************************/
/**
  * @brief  This function handles DMA SPI1 Rx interrupt request.
  * @param  None
  * @retval None
  */
void DMA1_Channel2_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&hdma_rx[0]);
}

/**
  * @brief  This function handles DMA SPI1 Tx interrupt request.
  * @param  None
  * @retval None
  */
void DMA1_Channel3_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&hdma_tx[0]);
}

/**
  * @brief  This function handles DMA SPI2 Rx interrupt request.
  * @param  None
  * @retval None
  */
void DMA1_Channel4_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&hdma_rx[1]);
}

/**
  * @brief  This function handles DMA SPI2 Tx interrupt request.
  * @param  None
  * @retval None
  */
void DMA1_Channel5_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&hdma_tx[1]);
}

///**
//  * @brief  This function handles DMA I2C1 Rx interrupt request.
//  * @param  None
//  * @retval None
//  */
//void DMA1_Channel6_IRQHandler(void)
//{
//  HAL_DMA_IRQHandler(SpiHandle.hdmarx);
//}
//
///**
//  * @brief  This function handles DMA I2C1 Tx interrupt request.
//  * @param  None
//  * @retval None
//  */
//void DMA1_Channel7_IRQHandler(void)
//{
//  HAL_DMA_IRQHandler(SpiHandle.hdmatx);
//}

