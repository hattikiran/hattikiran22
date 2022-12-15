/******************************************************************************
 * FILE NAME:  drv_dio.c
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
#include "drv_dio.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "../../BSP/bsp_mcu_stm32h757.h"
#include "../../BSP/bsp_board_decc_3.h"
#include "../mcu_stm32h7xx/drv_gpio.h"

/******************************************************************************
 * TypeDefs
 *****************************************************************************/
typedef struct {
	uint8_t index;
	driver_status_e status;
	bool in_use;
	dio_t *user_dio;
	void (*Callback_fcn_ptr)();
}gpio_t;

/******************************************************************************
 * Variables
 *****************************************************************************/
static gpio_t gpio_handle[BSP_DIO_COUNT];
static gpio_t gpio_usart_handle[BSP_USART1_COUNT];

/******************************************************************************
 * Function Prototypes
 *****************************************************************************/
void DIO_Callbacks(uint16_t pin);

/******************************************************************************
 * FUNCTION NAME:  DRV_DIOInitialize
 *
 * DESCRIPTION:
 * Initialize the GPIO pins declared in bsp_mcu_stm32h757.h file. Set the basic
 * driver parameters.
 *
 * PARAMETERS: None.
 *
 * RETURN VALUE:  None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void DRV_DIOInitialize(){
	uint8_t i = 0;

	//LED's and push buttons
	for (i=0; i < BSP_DIO_COUNT; i++){
		DRV_GPIOInitialize(&user_dio[i]);
		//DRV_InitiCallbackFcns(&user_dio[i],i);
		gpio_handle[i].status = DRV_STATUS_INITIALIZED;
		gpio_handle[i].in_use = false;
		gpio_handle[i].index = i;
		gpio_handle[i].user_dio = &user_dio[i];
		gpio_handle[i].Callback_fcn_ptr = user_dio[i].io_callback;
	}

	//USART
	for (i=0; i < BSP_USART1_COUNT; i++){
		DRV_GPIOInitialize(&uart_dio[i]);
		//DRV_InitiCallbackFcns(&user_dio[i],i);
		gpio_usart_handle[i].status = DRV_STATUS_INITIALIZED;
		gpio_usart_handle[i].in_use = false;
		gpio_usart_handle[i].index = i;
		gpio_usart_handle[i].user_dio = &uart_dio[i];
		gpio_handle[i].Callback_fcn_ptr = uart_dio[i].io_callback;
	}

	//Adding EXTI Callbacks
	DRV_ITConfig(DIO_Callbacks);

}

/******************************************************************************
 * FUNCTION NAME:  DIO_Callbacks
 *
 * DESCRIPTION:
 * This is the callback function pointer which calls the functions in the
 * application.
 *
 * PARAMETERS:
 * pin           uint16_t       mcu pin on which Interrupt occured.
 *
 * RETURN VALUE:  None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/

void DIO_Callbacks(uint16_t pin){
	if (pin == DRV_GPIO_PIN_13) {
		gpio_handle[BSP_DIO_INPUT_TAMPER_BUTTON].Callback_fcn_ptr();
	}

	if (pin == DRV_GPIO_PIN_0) {
		gpio_handle[BSP_DIO_INPUT_WAKEUP_BUTTON].Callback_fcn_ptr();
	}
}

/******************************************************************************
 * FUNCTION NAME:  DRV_DIODeInitialize
 *
 * DESCRIPTION:
 * DeInitialize the GPIO pins declared in bsp_mcu_stm32h757.h file. Set the
 * basic driver parameters.
 *
 * PARAMETERS: None.
 *
 * RETURN VALUE:  None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void DRV_DIODeInitialize(){
	uint8_t i = 0;

	//LED's and push buttons
	for (i=0; i < BSP_DIO_COUNT; i++){
		DRV_GPIODeInitialize(&user_dio[i]);
		gpio_handle[i].status = DRV_STATUS_UNINITIALIZED;
		gpio_handle[i].in_use = false;
		gpio_handle[i].index = 0;
		gpio_handle[i].user_dio = (dio_t *) NULL;
		gpio_handle[i].Callback_fcn_ptr = (void *) NULL;
	}

	//USART
	for (i=0; i < BSP_USART1_COUNT; i++){
		DRV_GPIODeInitialize(&uart_dio[i]);
		gpio_usart_handle[i].status = DRV_STATUS_UNINITIALIZED;
		gpio_usart_handle[i].in_use = false;
		gpio_usart_handle[i].index = 0;
		gpio_usart_handle[i].user_dio = &uart_dio[i];
		gpio_usart_handle[i].Callback_fcn_ptr = (void *) NULL;
	}
}

/******************************************************************************
 * FUNCTION NAME:  DRV_DIOOpen
 *
 * DESCRIPTION:
 * A parameter used by application to know if the pin is already in use.
 *
 * PARAMETERS:
 * dio           mw_dio_e       MCU pin
 *
 * RETURN VALUE:  None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
uintptr_t DRV_DIOOpen(mw_dio_e dio){
	uintptr_t handle = (uintptr_t) NULL;

	if (!gpio_handle[dio].in_use){
		gpio_handle[dio].in_use = true;
		handle = (uintptr_t) gpio_handle[dio].user_dio;
	}

	return handle;
}

/******************************************************************************
 * FUNCTION NAME:  DRV_DIOClose
 *
 * DESCRIPTION:
 * Set the handle value to false after de-initialization
 *
 * PARAMETERS:
 * uintptr_t           uint8_t *       pointer to handle that's de-initialized.
 * mw_dio_e      	   void *          MCU Pin
 *
 * RETURN VALUE:  None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void DRV_DIOClose(uintptr_t handle, mw_dio_e dio){
	if (handle == (uintptr_t) NULL){
		return;
	}

	if (gpio_handle[dio].user_dio == (dio_t *) handle){
		gpio_handle[dio].in_use = false;
		gpio_handle[dio].user_dio = (dio_t *) NULL;
	}
}

/******************************************************************************
 * FUNCTION NAME:  DRV_DIOSet
 *
 * DESCRIPTION:
 * Set the pin high or low
 *
 * PARAMETERS:
 * handle           uintptr_t       pointer to GPIO pin handle
 * dio      	   	mw_dio_e        MCU Pin
 * value			bool			value to be set
 *
 * RETURN VALUE:  None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void DRV_DIOSet(uintptr_t handle, mw_dio_e dio, bool value){
	if (handle == (uintptr_t) NULL){
		return;
	}
	DRV_GPIOSet(gpio_handle[dio].user_dio, value);
}

/******************************************************************************
 * FUNCTION NAME:  DRV_DIOGet
 *
 * DESCRIPTION:
 * read the pin
 *
 * PARAMETERS:
 * handle           uintptr_t       pointer to GPIO pin handle
 * dio      	   	mw_dio_e        MCU Pin
 * value*			uint32_t		pointer to the value read
 *
 * RETURN VALUE:  None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void DRV_DIOGet(uintptr_t handle, mw_dio_e dio, uint32_t *value){
	if (handle == (uintptr_t) NULL){
		return;
	}
	DRV_GPIOGet(gpio_handle[dio].user_dio, value);
}

/******************************************************************************
 * FUNCTION NAME:  DRV_DIOToggle
 *
 * DESCRIPTION:
 * Toggle the pin
 *
 * PARAMETERS:
 * handle           uintptr_t       pointer to GPIO pin handle
 * dio      	   	mw_dio_e        MCU Pin
 *
 * RETURN VALUE:  None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void DRV_DIOToggle(uintptr_t handle, mw_dio_e dio){
	if (handle == (uintptr_t) NULL){
		return;
	}
	DRV_GPIOToggle(gpio_handle[dio].user_dio);
}

/******************************************************************************
 * FUNCTION NAME:  DRV_USARTOpen
 *
 * DESCRIPTION:
 * A parameter used by application to know if the pin is already in use.
 *
 * PARAMETERS:
 * dio           mw_usart1_e       MCU pin
 *
 * RETURN VALUE:
 * uintptr_t		handle		handle for the pin
 *
 * NOTES:   None.
 *
 *****************************************************************************/
uintptr_t DRV_USARTOpen(mw_usart1_e usart1){
	uintptr_t handle = (uintptr_t) NULL;

	if (!gpio_usart_handle[usart1].in_use){
		gpio_usart_handle[usart1].in_use = true;
		handle = (uintptr_t) gpio_usart_handle[usart1].user_dio;
	}

	return handle;
}

/******************************************************************************
 * FUNCTION NAME:  DRV_DIOClose
 *
 * DESCRIPTION:
 * Set the handle value to false after de-initialization
 *
 * PARAMETERS:
 * uintptr_t           handle       pointer to handle that's de-initialized.
 * mw_dio_e      	   usart1       driver status
 *
 * RETURN VALUE:  None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void DRV_USARTClose(uintptr_t handle, driver_status_e usart1){
	if (handle == (uintptr_t) NULL){
		return;
	}

	if (gpio_handle[usart1].user_dio == (dio_t *) handle){
		gpio_handle[usart1].in_use = false;
		gpio_handle[usart1].user_dio = (dio_t *) NULL;
	}
}


/******************************************************************************
 * FUNCTION NAME:  DRV_LEDPattern1
 *
 * DESCRIPTION: LED display pattern.
 *
 *
 * PARAMETERS:
 *
 * RETURN VALUE:  None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void DRV_LEDPattern1(){
	//uint8_t i;
//	for(i = 0 ; i < 4 ; i++){
//		DRV_GPIOToggle(&user_dio[i]);
//	}
	//HAL_Delay(500);
}

/******************************************************************************
 * FUNCTION NAME:  TamperButtonPressed
 *
 * DESCRIPTION: Toggles LED's when the button is pressed.
 *
 *
 * PARAMETERS:
 *
 * RETURN VALUE:  None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void TamperButtonPressed(){
	DRV_GPIOToggle(&user_dio[0]);
	DRV_GPIOToggle(&user_dio[1]);
}

/******************************************************************************
 * FUNCTION NAME:  WakeupButtonPressed
 *
 * DESCRIPTION: Toggles LED's when the button is pressed.
 *
 *
 * PARAMETERS:
 *
 * RETURN VALUE:  None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void WakeupButtonPressed(){
	DRV_GPIOToggle(&user_dio[2]);
	DRV_GPIOToggle(&user_dio[3]);
}
