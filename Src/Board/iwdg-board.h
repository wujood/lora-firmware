/*
 * iwdg-board.h
 *
 *  Created on: 17.02.2020
 *      Author: Matze
 */

#ifndef LORABIB_IWDG_BOARD_H_
#define LORABIB_IWDG_BOARD_H_

/*!
 * \brief Initialize the Independent Watchdog object
 *
 */
void IWDG_Init( void );

/*!
 * \brief Refresh the Independent Watchdog object
 *
 */
void IWDG_Refresh (void);
#endif /* LORABIB_IWDG_BOARD_H_ */
