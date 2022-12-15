/******************************************************************************
 * FILE NAME:  mw_board.c
 *
 * FILE DESCRIPTION:
 * Middleware layer initialization of the general board features.
 *
 * NOTES:
 *
 * FILE AUTHOR(S):  Hiren Tank, Eric Roman
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
#include "mw_board.h"
#include "../../BSP/bsp_board_decc_3.h"
#include "../../Drivers/board/drv_board.h"
#include "../../Drivers/board/drv_dio.h"

/******************************************************************************
 * FUNCTION NAME:  MW_BoardInitialize
 *
 * DESCRIPTION:
 * Initialize the board through middleware.
 *
 * PARAMETERS:  None.
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void MW_BoardInitialize() {
	DRV_BoardInitialize();

}

/******************************************************************************
 * FUNCTION NAME:  MW_BoardInitialize
 *
 * DESCRIPTION:
 * Initialize all the i/o pins in this function.
 *
 * PARAMETERS:
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void MW_DIOInitialize(){
	DRV_DIOInitialize();
}

/******************************************************************************
 * FUNCTION NAME:  MW_TestLEDs
 *
 * DESCRIPTION:
 * display the LED pattern
 *
 * PARAMETERS:
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void MW_TestLEDs(){
	DRV_LEDPattern1();
}
