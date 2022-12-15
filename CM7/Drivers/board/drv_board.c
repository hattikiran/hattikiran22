/******************************************************************************
 * FILE NAME:  drv_board.c
 *
 * FILE DESCRIPTION:
 * Implementation of the driver level initialization of the general board
 * features.
 *
 * NOTES:
 *
 * FILE AUTHOR(S):  Eric Roman
 *
 * Copyright (C) 2022 Armstrong Fluid Technology
 * All Rights Reserved.  Reproduction or transmission of this file, or a
 * portion thereof, is forbidden without prior written permission of Armstrong
 * Fluid Technology.  Contact, 23 Bertrand Avenue, Toronto, Ontario, Canada,
 * M1L 2P3, (416) 755-2291, armstrongfluidtechnology.com.
 *
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "drv_board.h"
#include "../mcu_stm32h7xx/drv_hal.h"

/******************************************************************************
 * FUNCTION NAME:  DRV_BoardInitialize
 *
 * DESCRIPTION:
 * Initialize the board through driver layer by initializing the HAL, clocks
 * and any other control peripherals.
 *
 * PARAMETERS:  None.
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void DRV_BoardInitialize(){
	DRV_BoardBootSequence1();
	DRV_HAL_Initialize();
	DRV_SystemClockConfig();
	DRV_BoardBootSequence2();
}

