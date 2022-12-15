/******************************************************************************
 * FILE NAME:  mw_dio.c
 *
 * FILE FUNCTION:
 *
 * NOTES:
 *
 * PROTOCOL VERSIONS:
 *
 * FILE AUTHOR(S):  Hiren
 *****************************************************************************/
 
/******************************************************************************
 * Includes
 *****************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "mw_dio.h"
#include "../../Drivers/board/drv_dio.h"

/******************************************************************************
 * FUNCTION NAME:  MW_DIOOpen
 *
 * DESCRIPTION:
 * set the parameters to be used by application.
 *
 * PARAMETERS:
 * user_io		mw_dio_e		user io pin to open
 *
 * RETURN VALUE: None.
 * uintptr_t		return the structure to the handle
 *
 * NOTES:   None.
 *
 *****************************************************************************/
uintptr_t MW_DIOOpen(mw_dio_e user_io){
	uintptr_t handle = (uintptr_t) NULL;

	handle = DRV_DIOOpen(user_io);

	return handle;
}

/******************************************************************************
 * FUNCTION NAME:  MW_DIOClose
 *
 * DESCRIPTION:
 * set the parameters to be used by application.
 *
 * PARAMETERS:
 * user_io		mw_dio_e		user io pin to open
 * handle		uintptr_t		struct handle to the pin
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void MW_DIOClose(uintptr_t handle, mw_dio_e user_io){
	DRV_DIOClose(handle, user_io);
}

/******************************************************************************
 * FUNCTION NAME:  MW_DIOOutputToggle
 *
 * DESCRIPTION:
 * Toggle the pin
 *
 * PARAMETERS:
 * user_io		mw_dio_e		user io pin to toggle
 * handle		uintptr_t		struct handle to the pin
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void MW_DIOOutputToggle(uintptr_t handle, mw_dio_e user_io){
	if (user_io < BSP_DIO_INPUT_TAMPER_BUTTON){
		DRV_DIOToggle(handle, user_io);
	}
}

/******************************************************************************
 * FUNCTION NAME:  MW_DIOOutputTurnOn
 *
 * DESCRIPTION:
 * Set the pin to high.
 *
 * PARAMETERS:
 * user_io		mw_dio_e		user io pin to turn on
 * handle		uintptr_t		struct handle to the pin
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void MW_DIOOutputTurnOn(uintptr_t handle, mw_dio_e user_io){
	if (user_io < BSP_DIO_INPUT_TAMPER_BUTTON){
		DRV_DIOSet(handle, user_io, true);
	}
}

/******************************************************************************
 * FUNCTION NAME:  MW_DIOOutputTurnOff
 *
 * DESCRIPTION:
 * Set the pin to low.
 *
 * PARAMETERS:
 * user_io		mw_dio_e		user io pin to turn off
 * handle		uintptr_t		struct handle to the pin
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void MW_DIOOutputTurnOff(uintptr_t handle, mw_dio_e user_io){
	if (user_io < BSP_DIO_INPUT_TAMPER_BUTTON){
		DRV_DIOSet(handle, user_io, false);
	}
}

/******************************************************************************
 * FUNCTION NAME:  MW_DIOOutputTurnOff
 *
 * DESCRIPTION:
 * this get get value of input and output as well
 *
 * PARAMETERS:
 * user_io		mw_dio_e		user io pin
 * handle		uintptr_t		struct handle to the pin
 * *value		uint32_t		output value
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void MW_DIOInputGet(uintptr_t handle, mw_dio_e user_io, uint32_t *value){
	if (user_io < BSP_DIO_COUNT){
		DRV_DIOGet(handle, user_io, value);
	}
}
