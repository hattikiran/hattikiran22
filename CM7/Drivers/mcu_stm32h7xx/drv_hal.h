/******************************************************************************
 * FILE NAME:  drv_hal.h
 *
 * FILE DESCRIPTION:
 * Initialization of the HAL layer code.
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

#ifndef MCU_STM32H7XX_DRV_HAL_H_
#define MCU_STM32H7XX_DRV_HAL_H_

/******************************************************************************
 * Function Prototypes
 *****************************************************************************/
void DRV_HAL_Initialize();
void DRV_SystemClockConfig();
void DRV_BoardBootSequence1();
void DRV_BoardBootSequence2();


#endif /* MCU_STM32H7XX_DRV_HAL_H_ */
