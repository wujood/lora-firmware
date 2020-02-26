/*!
 * \file      LoRaMacParser.h
 *
 * \brief     LoRa MAC layer message parser functionality implementation
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
 *              (C)2013 Semtech
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
 *
 * addtogroup LORAMAC
 * \{
 *
 */
#ifndef __LORAMAC_PARSER_H__
#define __LORAMAC_PARSER_H__

#include <stdint.h>
#include "LoRaMacMessageTypes.h"

/*!
 * LoRaMac Parser Status
 */
typedef enum eLoRaMacParserStatus
{
    /*!
     * No error occurred
     */
    LORAMAC_PARSER_SUCCESS = 0,
    /*!
     * Failure during parsing occurred
     */
    LORAMAC_PARSER_FAIL,
    /*!
     * Null pointer exception
     */
    LORAMAC_PARSER_ERROR_NPE,
    /*!
     * Undefined Error occurred
     */
    LORAMAC_PARSER_ERROR,
}LoRaMacParserStatus_t;

enum Backups
{
	MHDRValue = 2,
	JoinNonce = 3,
	NetID  	= 4,
	DevAddr = 5,
	DLSettings = 6,
	RxDelay = 7,
	MIC = 8,
	FCntUp = 9,
	DevNonce = 10,
	NetworkActivation = 11,
	CFList1 = 12,
	CFList2 = 13,
	CFList3 = 14,
	CFList4 = 15,
	LastRxDone = 16,
	Payload = 17,
	Size = 18,
	Rssi = 19,
	Snr = 20,
};

/*!
 * Parse a serialized join-accept message and fills the structured object.
 *
 * \param[IN/OUT] macMsg       - Join-accept message object
 * \retval                     - Status of the operation
 */
LoRaMacParserStatus_t LoRaMacParserJoinAccept( LoRaMacMessageJoinAccept_t *macMsg );

/*!
 * Parse a serialized data message and fills the structured object.
 *
 * \param[IN/OUT] macMsg       - Data message object
 * \retval                     - Status of the operation
 */
LoRaMacParserStatus_t LoRaMacParserData( LoRaMacMessageData_t *macMsg );

/*!
 * Restore a serialized join-accept message and fills the structured object after Shutdown Reset.
 *
 * \param[IN/OUT] macMsg       - Join-accept message object
 * \retval                     - Status of the operation
 */
LoRaMacParserStatus_t LoRaMacRestoreJoinAccept( LoRaMacMessageJoinAccept_t* macMsg );
/*! \} addtogroup LORAMAC */

#endif // __LORAMAC_PARSER_H__

