/*!
 * \file      board-config.h
 *
 * \brief     Board configuration
 *
 * \copyright Revised BSD License, see section \ref LICENSE.
 *
 * \code
 *                ______                              _
 *               / _____)             _              | |
 *              ( (____  _____ ____ _| |_ _____  ____| |__
 *               \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 *               _____) ) ____| | | || |_| ____( (___| | | |
 *              (______/|_____)_|_|_| \__)_____)\____)_| |_|
 *              (C)2013-2017 Semtech
 *
 *               ___ _____ _   ___ _  _____ ___  ___  ___ ___
 *              / __|_   _/_\ / __| |/ / __/ _ \| _ \/ __| __|
 *              \__ \ | |/ _ \ (__| ' <| _| (_) |   / (__| _|
 *              |___/ |_/_/ \_\___|_|\_\_| \___/|_|_\\___|___|
 *              embedded.connectivity.solutions===============
 *
 * \endcode
 *
 * \author    Miguel Luis ( Semtech )
 *
 * \author    Gregory Cristian ( Semtech )
 *
 * \author    Daniel Jaeckle ( STACKFORCE )
 *
 * \author    Johannes Bruder ( STACKFORCE )
 */
#ifndef __BOARD_CONFIG_H__
#define __BOARD_CONFIG_H__

#define DRAGINO14
/*!
 * Defines the time required for the TCXO to wakeup [ms].
 */
#if defined( SX1262MBXDAS )
#define BOARD_TCXO_WAKEUP_TIME                      5
#else
#define BOARD_TCXO_WAKEUP_TIME                      0
#endif

/*!
 * Board MCU pins definitions
 */
#define RADIO_RESET                                 PC_7    // ok

#define RADIO_MOSI                                  PA_7    // ok
#define RADIO_MISO                                  PA_6    // ok
#define RADIO_SCLK                                  PA_5    // ok

#if defined( SX1261MBXBAS ) || defined( SX1262MBXCAS ) || defined( SX1262MBXDAS )

#define RADIO_NSS                                   PA_8
#define RADIO_BUSY                                  PB_3
#define RADIO_DIO_1                                 PB_4

#define RADIO_ANT_SWITCH_POWER                      PA_9
#define RADIO_FREQ_SEL                              PA_1
#define RADIO_XTAL_SEL                              PB_0
#define RADIO_DEVICE_SEL                            PA_4

#define LED_1                                       PC_1
#define LED_2                                       PC_0

// Debug pins definition.
#define RADIO_DBG_PIN_TX                            PB_6
#define RADIO_DBG_PIN_RX                            PC_7

#elif defined( SX1272MB2DAS) || defined( SX1276MB1LAS ) || defined( SX1276MB1MAS )

#define RADIO_NSS                                   PB_6

#define RADIO_DIO_0                                 PA_10
#define RADIO_DIO_1                                 PB_3
#define RADIO_DIO_2                                 PB_5
#define RADIO_DIO_3                                 PB_4
#define RADIO_DIO_4                                 PA_9
#define RADIO_DIO_5                                 PC_7

#define RADIO_ANT_SWITCH                            PC_1

#define LED_1                                       NC
#define LED_2                                       NC

// Debug pins definition.
#define RADIO_DBG_PIN_TX                            PB_0
#define RADIO_DBG_PIN_RX                            PA_4

#elif defined( DRAGINO14 )

#define RADIO_NSS                                   PB_6    // ok

#define RADIO_DIO_0                                 PA_10    // ok
#define RADIO_DIO_1                                 PB_4    // ok
#define RADIO_DIO_2                                 PA_8    // ok
#define RADIO_DIO_3                                 PA_0    // ok
#define RADIO_DIO_4                                 PA_1    // ok
#define RADIO_DIO_5                                 PA_9    // ok

#define RADIO_ANT_SWITCH                            PB_0

#define LED_1                                       NC
#define LED_2                                       NC

// Debug pins definition.
#define RADIO_DBG_PIN_TX                            PC_0
#define RADIO_DBG_PIN_RX                            PC_1

#endif

#define OSC_LSE_IN                                  PC_14    // ok
#define OSC_LSE_OUT                                 PC_15    // ok

#define OSC_HSE_IN                                  PH_0    // ok
#define OSC_HSE_OUT                                 PH_1    // ok

#define SWCLK                                       PA_14    // ok
#define SWDAT                                       PA_13    // ok

#define I2C_SCL                                     PB_8
#define I2C_SDA                                     PB_7

#define UART_TX                                     PA_2    // ok
#define UART_RX                                     PA_3    // ok

#define DMA_SPI1_TX									DMA1_Channel3
#define DMA_SPI1_RX									DMA1_Channel2

#define DMA_SPI2_TX									DMA1_Channel5
#define DMA_SPI2_RX									DMA1_Channel4

#define DMA_I2C_TX									DMA1_Channel7
#define DMA_I2C_RX									DMA1_Channel6

#define DMA_SPI1_TX_REQ								DMA_REQUEST_1
#define DMA_SPI1_RX_REQ								DMA_REQUEST_1

#define DMA_SPI2_TX_REQ								DMA_REQUEST_1
#define DMA_SPI2_RX_REQ								DMA_REQUEST_1

#define DMA_I2C_TX_REQ								DMA_REQUEST_3
#define DMA_I2C_RX_REQ								DMA_REQUEST_3

#define SPI1_DMA_TX_IRQn               				DMA1_Channel3_IRQn
#define SPI1_DMA_RX_IRQn                 			DMA1_Channel2_IRQn

#define SPI2_DMA_TX_IRQn                 			DMA1_Channel5_IRQn
#define SPI2_DMA_RX_IRQn                 			DMA1_Channel4_IRQn

#define I2C_DMA_TX_IRQn                 			DMA1_Channel7_IRQn
#define I2C_DMA_RX_IRQn                 			DMA1_Channel6_IRQn
#endif // __BOARD_CONFIG_H__
