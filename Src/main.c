/*!
 * \file      main.c
 *
 * \brief     Performs a periodic uplink
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
 *              (C)2013-2018 Semtech
 *
 * \endcode
 *
 * \author    Miguel Luis ( Semtech )
 */

/*! \file periodic-uplink/NucleoL476/main.c */

#include <stdbool.h>
#include <stddef.h>
#include <sys/_stdint.h>

#include "LmhpCompliance.h"
#include "LmHandler.h"
#include "LmHandlerMsgDisplay.h"
#include "LmHandlerTypes.h"
#include "bme280_defs.h"
#include "board.h"
#include "Commissioning.h"
#include "gpio.h"
#include "iwdg-board.h"
#include "LoRaMac.h"
#include "LoRaMacTypes.h"
#include "sensors.h"
#include "timer.h"
#include "utilities.h"

#define ACTIVE_REGION LORAMAC_REGION_EU868

#ifndef ACTIVE_REGION

#warning "No active region defined, LORAMAC_REGION_EU868 will be used as default."

#define ACTIVE_REGION LORAMAC_REGION_EU868

#endif

/*!
 * LoRaWAN default end-device class
 */
#define LORAWAN_DEFAULT_CLASS                       CLASS_A

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
#define APP_FIRST_TX                      			20000

/*!
 * LoRaWAN Adaptive Data Rate
 *
 * \remark Please note that when ADR is enabled the end-device should be static
 */
#define LORAWAN_ADR_STATE                           LORAMAC_HANDLER_ADR_ON

/*!
 * Default datarate
 *
 * \remark Please note that LORAWAN_DEFAULT_DATARATE is used only when ADR is disabled 
 */
#define LORAWAN_DEFAULT_DATARATE                    DR_0

/*!
 * LoRaWAN confirmed messages
 */
#define LORAWAN_DEFAULT_CONFIRMED_MSG_STATE         LORAMAC_HANDLER_UNCONFIRMED_MSG

/*!
 * User application data buffer size
 */
#define LORAWAN_APP_DATA_BUFFER_MAX_SIZE            242

/*!
 * LoRaWAN ETSI duty cycle control enable/disable
 *
 * \remark Please note that ETSI mandates duty cycled transmissions. Use only for test purposes
 */
#define LORAWAN_DUTYCYCLE_ON                        true

/*!
 * LoRaWAN application port
 * @remark The allowed port range is from 1 up to 223. Other values are reserved.
 */
#define LORAWAN_APP_PORT                            2

/*!
 *
 */
typedef enum {
	LORAMAC_HANDLER_TX_ON_TIMER, LORAMAC_HANDLER_TX_ON_EVENT,
} LmHandlerTxEvents_t;

/*!
 * User application data
 */
static uint8_t AppDataBuffer[LORAWAN_APP_DATA_BUFFER_MAX_SIZE];

/*!
 * User application data structure
 */
static LmHandlerAppData_t AppData = { .Buffer = AppDataBuffer, .BufferSize = 0, .Port = 0 };

/*!
 * Specifies the state of the application LED
 */
static bool AppLedStateOn = false;

/*!
 * Timer to handle the application data transmission duty cycle
 */
static TimerEvent_t TxTimer;

/*!
 * Timer to handle the first application data transmission
 */
static TimerEvent_t JoinedTimer;


/*!
 * Timer to handle the state of LED beacon indicator
 */
static TimerEvent_t LedBeaconTimer;

static void OnMacProcessNotify(void);
static void OnNvmContextChange(LmHandlerNvmContextStates_t state);
static void OnNetworkParametersChange(CommissioningParams_t* params);
static void OnMacMcpsRequest(LoRaMacStatus_t status, McpsReq_t *mcpsReq);
static void OnMacMlmeRequest(LoRaMacStatus_t status, MlmeReq_t *mlmeReq);
static void OnJoinRequest(LmHandlerJoinParams_t* params);
static void OnTxData(LmHandlerTxParams_t* params);
static void OnRxData(LmHandlerAppData_t* appData, LmHandlerRxParams_t* params);
static void OnClassChange(DeviceClass_t deviceClass);
static void OnBeaconStatusChange(LoRaMAcHandlerBeaconParams_t* params);

static void PrepareTxFrame(void);
static void ErrorFrame(uint16_t distance, int8_t rslt);
static void StartTxProcess(LmHandlerTxEvents_t txEvent);
static void StartJoinedProcess(LmHandlerTxEvents_t txEvent);
static void UplinkProcess(void);

/*!
 * Function executed on TxTimer event
 */
static void OnTxTimerEvent(void* context);

/*!
 * Function executed on JoinedTimer event
 */
static void OnJoinedTimerEvent(void* context);

static LmHandlerCallbacks_t LmHandlerCallbacks = {
		.GetBatteryLevel = BoardGetBatteryLevel,
		.GetTemperature = NULL,
		.GetUniqueId = BoardGetUniqueId,
		.GetRandomSeed = BoardGetRandomSeed,
		.OnMacProcess = OnMacProcessNotify,
		.OnNvmContextChange = OnNvmContextChange,
		.OnNetworkParametersChange = OnNetworkParametersChange,
		.OnMacMcpsRequest = OnMacMcpsRequest,
		.OnMacMlmeRequest = OnMacMlmeRequest,
		.OnJoinRequest = OnJoinRequest,
		.OnTxData = OnTxData,
		.OnRxData = OnRxData,
		.OnClassChange = OnClassChange,
		.OnBeaconStatusChange = OnBeaconStatusChange };

static LmHandlerParams_t LmHandlerParams = {
		.Region = ACTIVE_REGION,
		.AdrEnable = LORAWAN_ADR_STATE,
		.TxDatarate = LORAWAN_DEFAULT_DATARATE,
		.PublicNetworkEnable = LORAWAN_PUBLIC_NETWORK,
		.DutyCycleEnabled = LORAWAN_DUTYCYCLE_ON,
		.DataBufferMaxSize = LORAWAN_APP_DATA_BUFFER_MAX_SIZE,
		.DataBuffer = AppDataBuffer };

static LmhpComplianceParams_t LmhpComplianceParams = {
		.AdrEnabled = LORAWAN_ADR_STATE,
		.DutyCycleEnabled = LORAWAN_DUTYCYCLE_ON,
		.StopPeripherals = NULL,
		.StartPeripherals = NULL, };

/*!
 * Indicates if LoRaMacProcess call is pending.
 * 
 * \warning If variable is equal to 0 then the MCU can be set in low power mode
 */
static volatile uint8_t IsMacProcessPending = 0;

static volatile uint8_t IsTxFramePending = 0;

/*!
 * LED GPIO pins objects
 */

static uint16_t errorTrashMonitor;
struct bme280_data bmeData;

/*!
 * Main application entry point.
 */
int main(void)
{
	BoardInitMcu();
	BoardInitPeriph();

	const Version_t appVersion = { .Fields.Major = 1, .Fields.Minor = 0, .Fields.Revision = 0 };
	const Version_t gitHubVersion = { .Fields.Major = 4, .Fields.Minor = 4, .Fields.Revision = 2 };
	DisplayAppInfo("My Class A", &appVersion, &gitHubVersion);

	LmHandlerInit(&LmHandlerCallbacks, &LmHandlerParams);

	// The LoRa-Alliance Compliance protocol package should always be
	// initialized and activated.
	LmHandlerPackageRegister( PACKAGE_ID_COMPLIANCE, &LmhpComplianceParams);


	if ( LP_RUN_SHUTDOWN_MODE && GetNetworkActivation() && OVER_THE_AIR_ACTIVATION)
	{
		CRITICAL_SECTION_BEGIN( );
		RestoreLmHandlerJoin();
		RestoreRxDone();
		RestoreMacCtx();
		CRITICAL_SECTION_END( );
		StartTxProcess(LORAMAC_HANDLER_TX_ON_TIMER);

	}
	else
	{
		LmHandlerJoin();
		if (OVER_THE_AIR_ACTIVATION)
		{
			StartJoinedProcess(LORAMAC_HANDLER_TX_ON_TIMER);
		}
		else
			StartTxProcess(LORAMAC_HANDLER_TX_ON_TIMER);
	}

	while (1)
	{

		IWDG_Refresh();

		// Processes the LoRaMac events
		LmHandlerProcess();

		// Process application uplinks management
		UplinkProcess();

		CRITICAL_SECTION_BEGIN( );
		if (IsMacProcessPending == 1)
		{
			// Clear flag and prevent MCU to go into low power modes.
			IsMacProcessPending = 0;
		}
		else
		{
			// The MCU wakes up through events
			BoardLowPowerHandler();
		}
		CRITICAL_SECTION_END( );
	}
}

static void OnMacProcessNotify(void)
{
	IsMacProcessPending = 1;
}

static void OnNvmContextChange(LmHandlerNvmContextStates_t state)
{
	DisplayNvmContextChange(state);
}

static void OnNetworkParametersChange(CommissioningParams_t* params)
{
	DisplayNetworkParametersUpdate(params);
}

static void OnMacMcpsRequest(LoRaMacStatus_t status, McpsReq_t *mcpsReq)
{
	DisplayMacMcpsRequestUpdate(status, mcpsReq);
}

static void OnMacMlmeRequest(LoRaMacStatus_t status, MlmeReq_t *mlmeReq)
{
	DisplayMacMlmeRequestUpdate(status, mlmeReq);
}

static void OnJoinRequest(LmHandlerJoinParams_t* params)
{
	DisplayJoinRequestUpdate(params);
	if (params->Status == LORAMAC_HANDLER_ERROR)
	{
		LmHandlerJoin();
	}
	else
	{
		LmHandlerRequestClass( LORAWAN_DEFAULT_CLASS);
	}
}

static void OnTxData(LmHandlerTxParams_t* params)
{
	DisplayTxUpdate(params);
}

static void OnRxData(LmHandlerAppData_t* appData, LmHandlerRxParams_t* params)
{
	DisplayRxUpdate(appData, params);

	switch (appData->Port)
	{
		case 1: // The application LED can be controlled on port 1 or 2
		case LORAWAN_APP_PORT:
		{
			AppLedStateOn = appData->Buffer[0] & 0x01;
		}
			break;
		default:
			break;
	}
}

static void OnClassChange(DeviceClass_t deviceClass)
{
	DisplayClassUpdate(deviceClass);

	// Inform the server as soon as possible that the end-device has switched to ClassB
	LmHandlerAppData_t appData = { .Buffer = NULL, .BufferSize = 0, .Port = 0 };
	LmHandlerSend(&appData, LORAMAC_HANDLER_UNCONFIRMED_MSG);
}

static void OnBeaconStatusChange(LoRaMAcHandlerBeaconParams_t* params)
{
	switch (params->State)
	{
		case LORAMAC_HANDLER_BEACON_RX:
		{
			TimerStart(&LedBeaconTimer);
			break;
		}
		case LORAMAC_HANDLER_BEACON_LOST:
		case LORAMAC_HANDLER_BEACON_NRX:
		{
			TimerStop(&LedBeaconTimer);
			break;
		}
		default:
		{
			break;
		}
	}

	DisplayBeaconUpdate(params);
}

/*!
 * Prepares the payload of the frame and transmits it.
 */
static void PrepareTxFrame(void)
{
	uint16_t temperature = 0xFFFF;
	uint16_t humidity = 0xFFFF;
	uint16_t distance = 0xFFFF;
	int8_t rslt = BME280_OK;

	rslt = stream_bme280_data_forced_mode(&bme280, &bmeData);
	distance = stream_vl53l0x_data_forced_mode();
	temperature = bmeData.temperature + 5000;
	humidity = bmeData.humidity / 2;

	if (LmHandlerIsBusy() == true)
	{
		return;
	}

	ErrorFrame(distance, rslt);

	AppData.Port = LORAWAN_APP_PORT;

	AppData.Buffer[0] = distance >> 8;
	AppData.Buffer[1] = distance;
	AppData.Buffer[2] = humidity >> 8;
	AppData.Buffer[3] = humidity;
	AppData.Buffer[4] = temperature >> 8;
	AppData.Buffer[5] = temperature;
	AppData.Buffer[6] = errorTrashMonitor >> 8;
	AppData.Buffer[7] = errorTrashMonitor;
	AppData.BufferSize = 8;

	LmHandlerSend(&AppData, LORAWAN_DEFAULT_CONFIRMED_MSG_STATE);

}

/*!
 * Updates the ErrorTrashMonitor
 */
static void ErrorFrame(uint16_t distance, int8_t rslt)
{

	if (distance == 0xFFFF)
		errorTrashMonitor |= VL53L0x_ERROR_GEN_SET;
	else
		errorTrashMonitor &= VL53L0x_ERROR_GEN_RESET;

	if (distance > VL53L0x_UPPER_LIMIT)
		errorTrashMonitor |= VL53L0x_ERROR_UPPER_LIMIT_SET;
	else
		errorTrashMonitor &= VL53L0x_ERROR_UPPER_LIMIT_RESET;

	if (distance < VL53L0x_LOWER_LIMIT)
		errorTrashMonitor |= VL53L0x_ERROR_LOWER_LIMIT_SET;
	else
		errorTrashMonitor &= VL53L0x_ERROR_LOWER_LIMIT_RESET;

	if (bmeData.temperature > BME280_TEMP_UPPER_LIMIT)
		errorTrashMonitor |= BME280_ERROR_TEMP_UPPER_LIMIT_SET;
	else
		errorTrashMonitor &= BME280_ERROR_TEMP_UPPER_LIMIT_RESET;

	if (bmeData.temperature < BME280_TEMP_LOWER_LIMIT)
		errorTrashMonitor |= BME280_ERROR_TEMP_LOWER_LIMIT_SET;
	else
		errorTrashMonitor &= BME280_ERROR_TEMP_LOWER_LIMIT_RESET;

	if (bmeData.humidity > BME280_HYDR_UPPER_LIMIT)
		errorTrashMonitor |= BME280_ERROR_HYDR_UPPER_LIMIT_SET;
	else
		errorTrashMonitor &= BME280_ERROR_HYDR_UPPER_LIMIT_RESET;

	if (bmeData.humidity < BME280_HYDR_LOWER_LIMIT)
		errorTrashMonitor |= BME280_ERROR_HYDR_LOWER_LIMIT_SET;
	else
		errorTrashMonitor &= BME280_ERROR_HYDR_LOWER_LIMIT_RESET;

	if (rslt == BME280_E_NULL_PTR)
		errorTrashMonitor |= BME280_ERROR_NULL_PTR_SET;
	else
		errorTrashMonitor &= BME280_ERROR_NULL_PTR_RESET;

	if (rslt == BME280_E_DEV_NOT_FOUND)
		errorTrashMonitor |= BME280_ERROR_DEV_NOT_FOUND_SET;
	else
		errorTrashMonitor &= BME280_ERROR_DEV_NOT_FOUND_RESET;

	if (rslt == BME280_E_INVALID_LEN)
		errorTrashMonitor |= BME280_ERROR_INVALID_LEN_SET;
	else
		errorTrashMonitor &= BME280_ERROR_INVALID_LEN_RESET;

	if (rslt == BME280_E_COMM_FAIL)
		errorTrashMonitor |= BME280_ERROR_COMM_FAIL_SET;
	else
		errorTrashMonitor &= BME280_ERROR_COMM_FAIL_RESET;

	if (rslt == BME280_E_SLEEP_MODE_FAIL)
		errorTrashMonitor |= BME280_ERROR_SLEEP_MODE_FAIL_SET;
	else
		errorTrashMonitor &= BME280_ERROR_SLEEP_MODE_FAIL_RESET;

	if (rslt == BME280_E_NVM_COPY_FAILED)
		errorTrashMonitor |= BME280_ERROR_NVM_COPY_FAILED_SET;
	else
		errorTrashMonitor &= BME280_ERROR_NVM_COPY_FAILED_RESET;
}

static void StartTxProcess(LmHandlerTxEvents_t txEvent)
{
	switch (txEvent)
	{
		default:
			// Intentional fall through
		case LORAMAC_HANDLER_TX_ON_TIMER:
		{
			// Schedule 1st packet transmission
			TimerInit(&TxTimer, OnTxTimerEvent);
			TimerSetValue(&TxTimer,
			APP_TX_DUTYCYCLE + randr(-APP_TX_DUTYCYCLE_RND,
			APP_TX_DUTYCYCLE_RND));
			OnTxTimerEvent( NULL);
		}
			break;
		case LORAMAC_HANDLER_TX_ON_EVENT:
		{
		}
			break;
	}
}

static void StartJoinedProcess(LmHandlerTxEvents_t txEvent)
{
	switch (txEvent)
	{
		default:
			// Intentional fall through
		case LORAMAC_HANDLER_TX_ON_TIMER:
		{
			// Schedule 1st packet transmission
			TimerInit(&JoinedTimer, OnJoinedTimerEvent);
			TimerSetValue(&JoinedTimer, APP_FIRST_TX);
			TimerStart(&JoinedTimer);
		}
			break;
		case LORAMAC_HANDLER_TX_ON_EVENT:
		{
		}
			break;
	}
}

static void UplinkProcess(void)
{
	uint8_t isPending = 0;
	CRITICAL_SECTION_BEGIN( );
	isPending = IsTxFramePending;
	IsTxFramePending = 0;
	CRITICAL_SECTION_END( );
	if (isPending == 1)
	{
		PrepareTxFrame();
	}
}

static void OnTxTimerEvent(void* context)
{

	TimerStop(&TxTimer);

	IsTxFramePending = 1;

	// Schedule next transmission
	TimerSetValue(&TxTimer,
	APP_TX_DUTYCYCLE + randr(-APP_TX_DUTYCYCLE_RND, APP_TX_DUTYCYCLE_RND));
	TimerStart(&TxTimer);
}

static void OnJoinedTimerEvent(void* context)
{

	TimerStop(&JoinedTimer);

	IsTxFramePending = 1;

	// Schedule next transmission
	TimerSetValue(&TxTimer,
	APP_TX_DUTYCYCLE + randr(-APP_TX_DUTYCYCLE_RND, APP_TX_DUTYCYCLE_RND));
	TimerStart(&TxTimer);
}

