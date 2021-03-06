/*!
 * \file      Commissioning.h
 *
 * \brief     End device commissioning parameters
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
 * \endcode
 *
 * \author    Miguel Luis ( Semtech )
 *
 * \author    Gregory Cristian ( Semtech )
 */
#ifndef __LORA_COMMISSIONING_H__
#define __LORA_COMMISSIONING_H__


/*!
 ******************************************************************************
 ********************************** WARNING ***********************************
 ******************************************************************************
 The crypto-element implementation supports both 1.0.x and 1.1.x LoRaWAN
 versions of the specification.
 Thus it has been decided to use the 1.1.x keys and EUI name definitions.
 The below table shows the names equivalence between versions:
 +---------------------+-------------------------+
 |       1.0.x         |          1.1.x          |
 +=====================+=========================+
 | LORAWAN_DEVICE_EUI  | LORAWAN_DEVICE_EUI      |
 +---------------------+-------------------------+
 | LORAWAN_APP_EUI     | LORAWAN_JOIN_EUI        |
 +---------------------+-------------------------+
 | LORAWAN_GEN_APP_KEY | LORAWAN_APP_KEY         |
 +---------------------+-------------------------+
 | LORAWAN_APP_KEY     | LORAWAN_NWK_KEY         |
 +---------------------+-------------------------+
 | LORAWAN_NWK_S_KEY   | LORAWAN_F_NWK_S_INT_KEY |
 +---------------------+-------------------------+
 | LORAWAN_NWK_S_KEY   | LORAWAN_S_NWK_S_INT_KEY |
 +---------------------+-------------------------+
 | LORAWAN_NWK_S_KEY   | LORAWAN_NWK_S_ENC_KEY   |
 +---------------------+-------------------------+
 | LORAWAN_APP_S_KEY   | LORAWAN_APP_S_KEY       |
 +---------------------+-------------------------+
 ******************************************************************************
 ******************************************************************************
 ******************************************************************************
 */

/*!
 * When set to 1 the application uses the Over-the-Air activation procedure
 * When set to 0 the application uses the Personalization activation procedure
 */
#define OVER_THE_AIR_ACTIVATION                            1

/*!
 * When set to 1 the application uses the Low Power Run Mode and the Shutdown Mode
 * When set to 0 the application uses the Normal Run Mode and the Sleep Mode
 */
#define LP_RUN_SHUTDOWN_MODE							   1


/*!
 * Defines the application data transmission duty cycle. 5s, value in [ms].
 */
#define APP_TX_DUTYCYCLE                            180000

/*!
 * Defines a random delay for application data transmission duty cycle. 1s,
 * value in [ms].
 */
#define APP_TX_DUTYCYCLE_RND                        1000

/*!
 *  Defines the first application data transmission  timer value in [ms].
 */
#define APP_FIRST_TX                      			30000


/*!
 * Mote device IEEE EUI (big endian)
 *
 * \remark In this application the value is automatically generated by calling
 *         BoardGetUniqueId function
 */
#define LORAWAN_DEVICE_EUI                                 { 0x00, 0xB7, 0x04, 0xFB, 0xF7, 0xB8, 0x86, 0x69 }

/*!
 * App/Join server IEEE EUI (big endian)
 */
#define LORAWAN_JOIN_EUI                                   { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x02, 0x4A, 0x7C }

/*!
 * Application root key
 * WARNING: NOT USED FOR 1.0.x DEVICES
 */
#define LORAWAN_APP_KEY                                    { 0x9D, 0x86, 0xD4, 0x48, 0x9E, 0x36, 0x7B, 0xC5, 0x16, 0x2B, 0x28, 0x76, 0x9B, 0xD4, 0xBF, 0xEB }


/*!
 * Application root key - Used to derive Multicast keys on 1.0.x devices.
 * WARNING: USED only FOR 1.0.x DEVICES
 */
#define LORAWAN_GEN_APP_KEY                                { 0x9D, 0x86, 0xD4, 0x48, 0x9E, 0x36, 0x7B, 0xC5, 0x16, 0x2B, 0x28, 0x76, 0x9B, 0xD4, 0xBF, 0xEB }


/*!
 * Network root key
 * WARNING: FOR 1.0.x DEVICES IT IS THE \ref LORAWAN_APP_KEY
 */
#define LORAWAN_NWK_KEY                                    { 0x9D, 0x86, 0xD4, 0x48, 0x9E, 0x36, 0x7B, 0xC5, 0x16, 0x2B, 0x28, 0x76, 0x9B, 0xD4, 0xBF, 0xEB }



#if(OVER_THE_AIR_ACTIVATION==0)


/*!
 * Current network ID
 */
#define LORAWAN_NETWORK_ID                                 ( uint32_t )0x0

/*!
 * Device address on the network (big endian)
 *
 * \remark In this application the value is automatically generated using
 *         a pseudo random generator seeded with a value derived from
 *         BoardUniqueId value if LORAWAN_DEVICE_ADDRESS is set to 0
 */
#define LORAWAN_DEVICE_ADDRESS                             ( uint32_t )0x260111AB

/*!
 * Forwarding Network session integrity key
 * WARNING: NWK_S_KEY FOR 1.0.x DEVICES
 */
#define LORAWAN_F_NWK_S_INT_KEY                            { 0xE7, 0xB8, 0xAD, 0x45, 0xF9, 0x76, 0x35, 0x7F, 0x8A, 0x7F, 0xD3, 0x02, 0x48, 0xDF, 0xF6, 0xC4 }

/*!
 * Serving Network session integrity key
 * WARNING: NOT USED FOR 1.0.x DEVICES. MUST BE THE SAME AS \ref LORAWAN_F_NWK_S_INT_KEY
 */
#define LORAWAN_S_NWK_S_INT_KEY                            { 0xE7, 0xB8, 0xAD, 0x45, 0xF9, 0x76, 0x35, 0x7F, 0x8A, 0x7F, 0xD3, 0x02, 0x48, 0xDF, 0xF6, 0xC4 }

/*!
 * Network session encryption key
 * WARNING: NOT USED FOR 1.0.x DEVICES. MUST BE THE SAME AS \ref LORAWAN_F_NWK_S_INT_KEY
 */
#define LORAWAN_NWK_S_ENC_KEY                              { 0xE7, 0xB8, 0xAD, 0x45, 0xF9, 0x76, 0x35, 0x7F, 0x8A, 0x7F, 0xD3, 0x02, 0x48, 0xDF, 0xF6, 0xC4 }


/*!
 * Application session key
 */
#define LORAWAN_APP_S_KEY                                  { 0xAD, 0x1F, 0x1B, 0xE2, 0x81, 0x40, 0xB5, 0x0F, 0x3D, 0x0C, 0x88, 0x78, 0x39, 0xA8, 0xC5, 0x55 }


#endif


#endif // __LORA_COMMISSIONING_H__
