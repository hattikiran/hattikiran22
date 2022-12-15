/******************************************************************************
 * FILE NAME:  drv_dio.h
 *
 * FILE FUNCTION:
 *
 * NOTES:
 *
 * PROTOCOL VERSIONS:
 *
 * FILE AUTHOR(S):  Hiren
 *****************************************************************************/
#ifndef BOARD_DRV_DIO_H_
#define BOARD_DRV_DIO_H_

/******************************************************************************
 * Includes
 *****************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "stm32h757xx.h"
#include "../../BSP/bsp_board_decc_3.h"
#include "../../BSP/bsp_gpio.h"


/******************************************************************************
 * Function Prototypes
 *****************************************************************************/
void DRV_DIOInitialize();
void DRV_DIODeInitialize();
//open and close only needed for user DIO pins.  Other pins used
//with peripherals don't need open/closed.
void DRV_DIOInitialize();
uintptr_t DRV_DIOOpen(mw_dio_e dio);
void DRV_DIOClose(uintptr_t handle, mw_dio_e dio);
void DRV_DIOSet(uintptr_t handle, mw_dio_e dio, bool value);
void DRV_DIOGet(uintptr_t handle, mw_dio_e dio, uint32_t *value);
void DRV_DIOToggle(uintptr_t handle, mw_dio_e dio);
void DRV_DIOCallback();

//LEDS
void DRV_LEDPattern1();

void TamperButtonPressed();
void WakeupButtonPressed();

#endif /* BOARD_DRV_DIO_H_ */
