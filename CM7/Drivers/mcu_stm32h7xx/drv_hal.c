/******************************************************************************
 * FILE NAME:  drv_hal.c
 *
 * FILE DESCRIPTION:
 * Implementation of the initialization functions for the HAL layer code.
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
#include "stm32h7xx.h"

/******************************************************************************
 * Defines
 *****************************************************************************/
#ifndef HSEM_ID_0
#define HSEM_ID_0 (0U) /* HW semaphore 0*/
#endif

/******************************************************************************
 * FUNCTION NAME:  DRV_HAL_Initialize
 *
 * DESCRIPTION:
 * Initialize the HAL layer code.
 *
 * PARAMETERS:  None.
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void DRV_HAL_Initialize(){
	HAL_Init();
}

/******************************************************************************
 * FUNCTION NAME:  DRV_SystemClockConfig
 *
 * DESCRIPTION:
 * Initialize system clock.  Use the cube generated code to fill in the
 * information.
 *
 * PARAMETERS:  None.
 *
 * RETURN VALUE: None.
 *
 * NOTES:
 * TODO: add in error handling
 *
 *****************************************************************************/
void DRV_SystemClockConfig(){
	 RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	  /** Supply configuration update enable
	  */
	  HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);

	  /** Configure the main internal regulator output voltage
	  */
	  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

	  /** Initializes the RCC Oscillators according to the specified parameters
	  * in the RCC_OscInitTypeDef structure.
	  */
	  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
	  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	  RCC_OscInitStruct.PLL.PLLM = 4;
	  RCC_OscInitStruct.PLL.PLLN = 50;
	  RCC_OscInitStruct.PLL.PLLP = 2;
	  RCC_OscInitStruct.PLL.PLLQ = 1;
	  RCC_OscInitStruct.PLL.PLLR = 2;
	  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
	  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
	  RCC_OscInitStruct.PLL.PLLFRACN = 0;
	  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	  {
//	    Error_Handler();
	  }

	  /** Initializes the CPU, AHB and APB buses clocks
	  */
	  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
	                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
	                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
	  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
	  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
	  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
	  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
	  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
	  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

	  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
	  {
//	    Error_Handler();
	  }
}

/******************************************************************************
 * FUNCTION NAME:  DRV_BoardBootSequence1
 *
 * DESCRIPTION:
 * Initialize the first MCU.
 *
 * PARAMETERS:  None.
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 * TODO: add error handling.
 *
 *****************************************************************************/
void DRV_BoardBootSequence1(){
	int32_t timeout;
	/* Wait until CPU2 boots and enters in stop mode or timeout*/
	timeout = 0xFFFF;
	while ((__HAL_RCC_GET_FLAG(RCC_FLAG_D2CKRDY) != RESET) && (timeout-- > 0)) {
		;
	}
	if (timeout < 0) {
//		Error_Handler();
	}
}

/******************************************************************************
 * FUNCTION NAME:  DRV_BoardBootSequence2
 *
 * DESCRIPTION:
 * Initialize the second MCU.
 *
 * PARAMETERS:  None.
 *
 * RETURN VALUE: None.
 *
 * NOTES:
 * TODO: add error handling.
 *
 *****************************************************************************/
void DRV_BoardBootSequence2(){
	int32_t timeout;

	/* When system initialization is finished, Cortex-M7 will release Cortex-M4 by means of
	 HSEM notification */
	/*HW semaphore Clock enable*/
	__HAL_RCC_HSEM_CLK_ENABLE();
	/*Take HSEM */
	HAL_HSEM_FastTake(HSEM_ID_0);
	/*Release HSEM in order to notify the CPU2(CM4)*/
	HAL_HSEM_Release(HSEM_ID_0, 0);
	/* wait until CPU2 wakes up from stop mode */
	timeout = 0xFFFF;
	while ((__HAL_RCC_GET_FLAG(RCC_FLAG_D2CKRDY) == RESET) && (timeout-- > 0))
		;
	if (timeout < 0) {
//		Error_Handler();
	}

}


