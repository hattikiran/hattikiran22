/*
 * bsp_mcu_stm32h757.h
 *
 *  Created on: Jul 6, 2022
 *      Author: htank
 */

#ifndef BSP_MCU_STM32H757_H_
#define BSP_MCU_STM32H757_H_

#include "bsp_gpio.h"


dio_t user_dio[] = {
		{ DRV_GPIO_MODE_OUTPUT_PP,  DRV_GPIO_SPEED_FREQ_MEDIUM, DRV_GPIO_NOPULL,   		DRV_GPIO_PIN_3,  	DRV_GPIOK, DRV_GPIO_ALTERNATE_FC0, NULL }, //BSP_DIO_OUTPUT_01
		{ DRV_GPIO_MODE_OUTPUT_PP,  DRV_GPIO_SPEED_FREQ_MEDIUM, DRV_GPIO_NOPULL,   		DRV_GPIO_PIN_4,  	DRV_GPIOK, DRV_GPIO_ALTERNATE_FC0, NULL }, //BSP_DIO_OUTPUT_02
		{ DRV_GPIO_MODE_OUTPUT_PP, 	DRV_GPIO_SPEED_FREQ_MEDIUM, DRV_GPIO_NOPULL, 		DRV_GPIO_PIN_5, 	DRV_GPIOK, DRV_GPIO_ALTERNATE_FC0, NULL }, //BSP_DIO_OUTPUT_03
		{ DRV_GPIO_MODE_OUTPUT_PP, 	DRV_GPIO_SPEED_FREQ_MEDIUM, DRV_GPIO_NOPULL, 		DRV_GPIO_PIN_6, 	DRV_GPIOK, DRV_GPIO_ALTERNATE_FC0, NULL }, //BSP_DIO_OUTPUT_04
		{ DRV_GPIO_MODE_IT_FALLING,	DRV_GPIO_SPEED_FREQ_VERY_HIGH, DRV_GPIO_NOPULL,   	DRV_GPIO_PIN_13, 	DRV_GPIOC, DRV_GPIO_ALTERNATE_FC0, TamperButtonPressed }, //Tamper push button
		{ DRV_GPIO_MODE_IT_FALLING, DRV_GPIO_SPEED_FREQ_VERY_HIGH, DRV_GPIO_NOPULL,   	DRV_GPIO_PIN_0,  	DRV_GPIOA, DRV_GPIO_ALTERNATE_FC0, WakeupButtonPressed }, //Wakeup push button
};

const dio_t spi_dio[]={};

dio_t uart_dio[] = {
		{ DRV_GPIO_MODE_OUTPUT_PP,  DRV_GPIO_SPEED_FREQ_MEDIUM, DRV_GPIO_NOPULL,   		DRV_GPIO_PIN_14,  	DRV_GPIOB, DRV_GPIO_ALTERNATE_FC4, NULL },//USART 1 TX
		{ DRV_GPIO_MODE_OUTPUT_PP,  DRV_GPIO_SPEED_FREQ_MEDIUM, DRV_GPIO_NOPULL,   		DRV_GPIO_PIN_15,  	DRV_GPIOB, DRV_GPIO_ALTERNATE_FC4, NULL },//USART 1 RX
};

#endif /* BSP_MCU_STM32H757_H_ */
