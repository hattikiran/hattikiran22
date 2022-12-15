/******************************************************************************
 * FILE NAME:  bsp_board_decc_3.h
 *
 * FILE FUNCTION:
 * Definitions of board hardware.
 * NOTES:
 *
 * PROTOCOL VERSIONS:
 *
 * FILE AUTHOR(S):  Hiren
 *****************************************************************************/

#ifndef BSP_BOARD_DECC_3_H_
#define BSP_BOARD_DECC_3_H_

/******************************************************************************
 * Defines
 *****************************************************************************/
#define UARTn 4//for uart4
#define COM1_UART 1

/******************************************************************************
 * Defines/Constants
 *****************************************************************************/
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
/******************************************************************************
 * Global Variables
 *****************************************************************************/


#endif /* BSP_BOARD_DECC_3_H_ */
