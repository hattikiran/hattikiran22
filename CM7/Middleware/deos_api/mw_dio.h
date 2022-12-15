/******************************************************************************
 * FILE NAME:  mw_dio.h
 *
 * FILE FUNCTION:
 *
 * NOTES:
 *
 * PROTOCOL VERSIONS:
 *
 * FILE AUTHOR(S):  Hiren
 *****************************************************************************/
 
#ifndef DEOS_API_MW_DIO_H_
#define DEOS_API_MW_DIO_H_

/******************************************************************************
 * Includes
 *****************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "../../BSP/bsp_board_decc_3.h"

/******************************************************************************
 * Function Prototypes
 *****************************************************************************/
//API's for User LED's
//don't need init or de-init because I included it in the MW_BoardInitialize function
uintptr_t MW_DIOOpen(mw_dio_e user_io);
void MW_DIOClose(uintptr_t handle, mw_dio_e user_io);
void MW_DIOOutputToggle(uintptr_t handle, mw_dio_e user_io);
void MW_DIOOutputTurnOn(uintptr_t handle, mw_dio_e user_io);
void MW_DIOOutputTurnOff(uintptr_t handle, mw_dio_e user_io);
void MW_DIOInputGet(uintptr_t handle, mw_dio_e user_io, uint32_t *value);
void MW_DIOInputCallback(uintptr_t handle);

#endif /* DEOS_API_MW_DIO_H_ */
