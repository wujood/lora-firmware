/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
    (C)2013 Semtech
 ___ _____ _   ___ _  _____ ___  ___  ___ ___
/ __|_   _/_\ / __| |/ / __/ _ \| _ \/ __| __|
\__ \ | |/ _ \ (__| ' <| _| (_) |   / (__| _|
|___/ |_/_/ \_\___|_|\_\_| \___/|_|_\\___|___|
embedded.connectivity.solutions===============

Description: LoRa MAC layer message parser functionality implementation

License: Revised BSD License, see LICENSE.TXT file include in the project

Maintainer: Miguel Luis ( Semtech ), Gregory Cristian ( Semtech ),
            Daniel Jaeckle ( STACKFORCE ),  Johannes Bruder ( STACKFORCE )
*/
#include "LoRaMacParser.h"
#include "utilities.h"

#include "rtc-board.h"




LoRaMacParserStatus_t LoRaMacParserJoinAccept( LoRaMacMessageJoinAccept_t* macMsg )
{
    uint32_t tempVal = 0;

	if( ( macMsg == 0 ) || ( macMsg->Buffer == 0 ) )
    {
        return LORAMAC_PARSER_ERROR_NPE;
    }

    uint16_t bufItr = 0;

    macMsg->MHDR.Value = macMsg->Buffer[bufItr++];

    RtcBackupWrite(  macMsg->MHDR.Value , MHDRValue );

    memcpy1( macMsg->JoinNonce, &macMsg->Buffer[bufItr], 3 );
    bufItr = bufItr + 3;

    tempVal = ( uint32_t ) macMsg->JoinNonce[0];
    tempVal |= (( uint32_t ) macMsg->JoinNonce[1] << 8 );
    tempVal |= (( uint32_t ) macMsg->JoinNonce[2] << 16 );
    RtcBackupWrite(  tempVal , JoinNonce );

    memcpy1( macMsg->NetID, &macMsg->Buffer[bufItr], 3 );
    bufItr = bufItr + 3;

    tempVal = 0;
    tempVal = ( uint32_t ) macMsg->NetID[0];
    tempVal |= (( uint32_t ) macMsg->NetID[1] << 8 );
    tempVal |= (( uint32_t ) macMsg->NetID[2] << 16 );

    RtcBackupWrite(  tempVal , NetID );

    macMsg->DevAddr = ( uint32_t ) macMsg->Buffer[bufItr++];
    macMsg->DevAddr |= ( ( uint32_t ) macMsg->Buffer[bufItr++] << 8 );
    macMsg->DevAddr |= ( ( uint32_t ) macMsg->Buffer[bufItr++] << 16 );
    macMsg->DevAddr |= ( ( uint32_t ) macMsg->Buffer[bufItr++] << 24 );

    RtcBackupWrite(  macMsg->DevAddr , DevAddr );

    macMsg->DLSettings.Value = macMsg->Buffer[bufItr++];

    RtcBackupWrite(  macMsg->DLSettings.Value , DLSettings );

    macMsg->RxDelay = macMsg->Buffer[bufItr++];

    RtcBackupWrite(  macMsg->RxDelay , RxDelay );

    if( ( macMsg->BufSize - LORAMAC_MIC_FIELD_SIZE - bufItr ) == LORAMAC_C_FLIST_FIELD_SIZE )
    {
        memcpy1( macMsg->CFList, &macMsg->Buffer[bufItr], LORAMAC_C_FLIST_FIELD_SIZE );
        bufItr = bufItr + LORAMAC_C_FLIST_FIELD_SIZE;

        tempVal = 0;
        tempVal = ( uint32_t ) macMsg->CFList[0];
        tempVal |= (( uint32_t ) macMsg->CFList[1] << 8 );
        tempVal |= (( uint32_t ) macMsg->CFList[2] << 16 );
        tempVal |= (( uint32_t ) macMsg->CFList[3] << 24 );
        RtcBackupWrite(  tempVal , CFList1 );

        tempVal = 0;
        tempVal = ( uint32_t ) macMsg->CFList[4];
        tempVal |= (( uint32_t ) macMsg->CFList[5] << 8 );
        tempVal |= (( uint32_t ) macMsg->CFList[6] << 16 );
        tempVal |= (( uint32_t ) macMsg->CFList[7] << 24 );
        RtcBackupWrite(  tempVal , CFList2 );

        tempVal = 0;
        tempVal = ( uint32_t ) macMsg->CFList[8];
        tempVal |= (( uint32_t ) macMsg->CFList[9] << 8 );
        tempVal |= (( uint32_t ) macMsg->CFList[10] << 16 );
        tempVal |= (( uint32_t ) macMsg->CFList[11] << 24 );
        RtcBackupWrite(  tempVal , CFList3 );

        tempVal = 0;
        tempVal = ( uint32_t ) macMsg->CFList[12];
        tempVal |= (( uint32_t ) macMsg->CFList[13] << 8 );
        tempVal |= (( uint32_t ) macMsg->CFList[14] << 16 );
        tempVal |= (( uint32_t ) macMsg->CFList[15] << 24 );
        RtcBackupWrite(  tempVal , CFList4 );
    }
    else if( ( macMsg->BufSize - LORAMAC_MIC_FIELD_SIZE - bufItr ) > 0 )
    {
        return LORAMAC_PARSER_FAIL;
    }

    macMsg->MIC = ( uint32_t ) macMsg->Buffer[bufItr++];
    macMsg->MIC |= ( ( uint32_t ) macMsg->Buffer[bufItr++] << 8 );
    macMsg->MIC |= ( ( uint32_t ) macMsg->Buffer[bufItr++] << 16 );
    macMsg->MIC |= ( ( uint32_t ) macMsg->Buffer[bufItr++] << 24 );

    RtcBackupWrite(  macMsg->MIC , MIC );

    return LORAMAC_PARSER_SUCCESS;
}

LoRaMacParserStatus_t LoRaMacParserData( LoRaMacMessageData_t* macMsg )
{
    if( ( macMsg == 0 ) || ( macMsg->Buffer == 0 ) )
    {
        return LORAMAC_PARSER_ERROR_NPE;
    }

    uint16_t bufItr = 0;

    macMsg->MHDR.Value = macMsg->Buffer[bufItr++];

    macMsg->FHDR.DevAddr = macMsg->Buffer[bufItr++];
    macMsg->FHDR.DevAddr |= ( ( uint32_t ) macMsg->Buffer[bufItr++] << 8 );
    macMsg->FHDR.DevAddr |= ( ( uint32_t ) macMsg->Buffer[bufItr++] << 16 );
    macMsg->FHDR.DevAddr |= ( ( uint32_t ) macMsg->Buffer[bufItr++] << 24 );

    macMsg->FHDR.FCtrl.Value = macMsg->Buffer[bufItr++];

    macMsg->FHDR.FCnt = macMsg->Buffer[bufItr++];
    macMsg->FHDR.FCnt |= macMsg->Buffer[bufItr++] << 8;

    if( macMsg->FHDR.FCtrl.Bits.FOptsLen <= 15 )
    {
        memcpy1( macMsg->FHDR.FOpts, &macMsg->Buffer[bufItr], macMsg->FHDR.FCtrl.Bits.FOptsLen );
        bufItr = bufItr + macMsg->FHDR.FCtrl.Bits.FOptsLen;
    }
    else
    {
        return LORAMAC_PARSER_FAIL;
    }

    // Initialize anyway with zero.
    macMsg->FPort = 0;
    macMsg->FRMPayloadSize = 0;

    if( ( macMsg->BufSize - bufItr - LORAMAC_MIC_FIELD_SIZE ) > 0 )
    {
        macMsg->FPort = macMsg->Buffer[bufItr++];

        macMsg->FRMPayloadSize = ( macMsg->BufSize - bufItr - LORAMAC_MIC_FIELD_SIZE );
        memcpy1( macMsg->FRMPayload, &macMsg->Buffer[bufItr], macMsg->FRMPayloadSize );
        bufItr = bufItr + macMsg->FRMPayloadSize;
    }

    macMsg->MIC = ( uint32_t ) macMsg->Buffer[( macMsg->BufSize - LORAMAC_MIC_FIELD_SIZE )];
    macMsg->MIC |= ( ( uint32_t ) macMsg->Buffer[( macMsg->BufSize - LORAMAC_MIC_FIELD_SIZE ) + 1] << 8 );
    macMsg->MIC |= ( ( uint32_t ) macMsg->Buffer[( macMsg->BufSize - LORAMAC_MIC_FIELD_SIZE ) + 2] << 16 );
    macMsg->MIC |= ( ( uint32_t ) macMsg->Buffer[( macMsg->BufSize - LORAMAC_MIC_FIELD_SIZE ) + 3] << 24 );

    return LORAMAC_PARSER_SUCCESS;
}


LoRaMacParserStatus_t LoRaMacRestoreJoinAccept( LoRaMacMessageJoinAccept_t* macMsg )
{
//    uint16_t bufItr = 13;
    uint32_t tempVal = 0;


    uint16_t bufItr = 0;


    macMsg->MHDR.Value = RtcBackupRead( MHDRValue );
    macMsg->Buffer[0] = macMsg->MHDR.Value;
    bufItr++;
    tempVal = RtcBackupRead( JoinNonce );
    macMsg->JoinNonce[0] = tempVal;
    macMsg->JoinNonce[1] = tempVal >> 8;
    macMsg->JoinNonce[2] = tempVal >> 16;

    memcpy1( &macMsg->Buffer[bufItr], macMsg->JoinNonce , 3 );
    bufItr = bufItr + 3;

    tempVal = RtcBackupRead( NetID );
    macMsg->NetID[0] = tempVal;
    macMsg->NetID[1] = tempVal >> 8;
    macMsg->NetID[2] = tempVal >> 16;

    memcpy1( &macMsg->Buffer[bufItr], macMsg->NetID, 3 );
   	bufItr = bufItr + 3;


   	macMsg->DevAddr = RtcBackupRead( DevAddr );

   	macMsg->Buffer[bufItr++] = macMsg->DevAddr;
   	macMsg->Buffer[bufItr++] = macMsg->DevAddr >> 8;
   	macMsg->Buffer[bufItr++] = macMsg->DevAddr >> 16;
   	macMsg->Buffer[bufItr++] = macMsg->DevAddr >> 24;


   	macMsg->DLSettings.Value = RtcBackupRead( DLSettings );
   	macMsg->Buffer[bufItr++] = macMsg->DLSettings.Value;
    macMsg->RxDelay = RtcBackupRead( RxDelay );
    macMsg->Buffer[bufItr++] = macMsg->RxDelay;


//    if( ( macMsg->BufSize - LORAMAC_MIC_FIELD_SIZE - bufItr ) == LORAMAC_C_FLIST_FIELD_SIZE )
//    {
        tempVal = RtcBackupRead( CFList1 );
        macMsg->CFList[0] = tempVal;
        macMsg->CFList[1] = tempVal >> 8;
        macMsg->CFList[2] = tempVal >> 16;
        macMsg->CFList[3] = tempVal >> 24;

        tempVal = RtcBackupRead( CFList2 );
        macMsg->CFList[4] = tempVal;
        macMsg->CFList[5] = tempVal >> 8;
        macMsg->CFList[6] = tempVal >> 16;
        macMsg->CFList[7] = tempVal >> 24;

        tempVal = RtcBackupRead( CFList3 );
        macMsg->CFList[8] = tempVal;
        macMsg->CFList[9] = tempVal >> 8;
        macMsg->CFList[10] = tempVal >> 16;
        macMsg->CFList[11] = tempVal >> 24;

        tempVal = RtcBackupRead( CFList4 );
        macMsg->CFList[12] = tempVal;
        macMsg->CFList[13] = tempVal >> 8;
        macMsg->CFList[14] = tempVal >> 16;
        macMsg->CFList[15] = tempVal >> 24;

        memcpy1( &macMsg->Buffer[bufItr], macMsg->CFList, LORAMAC_C_FLIST_FIELD_SIZE );
        bufItr = bufItr + LORAMAC_C_FLIST_FIELD_SIZE;
//    }
//    else if( ( macMsg->BufSize - LORAMAC_MIC_FIELD_SIZE - bufItr ) > 0 )
//    {
//        return LORAMAC_PARSER_FAIL;
//    }

    macMsg->MIC =  RtcBackupRead( MIC );

    macMsg->Buffer[bufItr++] = macMsg->MIC;
    macMsg->Buffer[bufItr++] = macMsg->MIC >> 8;
    macMsg->Buffer[bufItr++] = macMsg->MIC >> 16;
    macMsg->Buffer[bufItr++] = macMsg->MIC >> 24;

    return LORAMAC_PARSER_SUCCESS;
}
