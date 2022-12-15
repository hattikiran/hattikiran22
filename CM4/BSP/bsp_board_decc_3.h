/*
 * bsp_board_decc_3.h
 *
 *  Created on: Jul 6, 2022
 *      Author: htank
 */

#ifndef BSP_BOARD_DECC_3_H_
#define BSP_BOARD_DECC_3_H_

//visible to application

#define UARTn 4//for uart4
#define COM1_UART 1

typedef enum{
	BSP_DIO_OUTPUT_01,
	BSP_DIO_OUTPUT_02,
	BSP_DIO_OUTPUT_03,
	BSP_DIO_OUTPUT_04,
	BSP_DIO_INPUT_TAMPER_BUTTON,
	BSP_DIO_INPUT_WAKEUP_BUTTON,
	BSP_DIO_COUNT
}mw_dio_e;

typedef enum{
	BSP_USART1_TX,
	BSP_USART1_RX,
	BSP_USART1_COUNT
}mw_usart1_e;

typedef enum{
	DRV_STATUS_UNINITIALIZED,
	DRV_STATUS_INITIALIZED,
	DRV_STATUS_ERROR,

}driver_status_e;

#endif /* BSP_BOARD_DECC_3_H_ */
