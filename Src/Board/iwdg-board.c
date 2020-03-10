/*
 * iwdg-board.c
 *
 *  Created on: 17.02.2020
 *      Author: Matze
 */


#include "stm32l4xx.h"
#include "utilities.h"
#include "board-config.h"
#include "iwdg-board.h"

static IWDG_HandleTypeDef   IwdgHandle;
static FLASH_OBProgramInitTypeDef pOBInit;

void IWDG_Init( void )
{
	IwdgHandle.Instance = IWDG;
	IwdgHandle.Init.Prescaler = IWDG_PRESCALER_128;
	IwdgHandle.Init.Reload = 0x9C4;
	IwdgHandle.Init.Window = IWDG_WINDOW_DISABLE;

	// During the Standby and Stop mode the IWDG should be freezed
	HAL_FLASH_Unlock();
	HAL_FLASH_OB_Unlock();

	pOBInit.OptionType = OPTIONBYTE_USER;
	pOBInit.USERConfig = OB_IWDG_STOP_FREEZE|OB_IWDG_STDBY_FREEZE;
	pOBInit.USERType = OB_USER_IWDG_STOP|OB_USER_IWDG_STDBY;

	HAL_FLASHEx_OBProgram(&pOBInit);

	HAL_FLASH_OB_Lock();
	HAL_FLASH_Lock();
	HAL_FLASHEx_OBGetConfig(&pOBInit);

	HAL_IWDG_Init(&IwdgHandle);
}

void IWDG_Refresh (void)
{
	HAL_IWDG_Refresh(&IwdgHandle);
}
