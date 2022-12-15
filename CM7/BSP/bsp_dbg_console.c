/******************************************************************************
 * FILE NAME:  bsp_dbg_console.c
 *
 * FILE FUNCTION: Print to console or serial port
 *
 * NOTES:
 *
 * FILE AUTHOR(S):  KIRAN, ERIC
 *
 * Copyright (C) 2022 Armstrong Fluid Technology
 * All Rights Reserved.  Reproduction or transmission of this file, or a
 * portion thereof, is forbidden without prior written permission of Armstrong
 * Fluid Technology.  Contact, 23 Bertrand Avenue, Toronto, Ontario, Canada,
 * M1L 2P3, (416) 755-2291, armstrongfluidtechnology.com.
 *
 * FILE USAGE:
 * This file provides the functions to make printf retarget to the console or UART
 *				  based on the selection
 *
 *=========================================================================
 *					##### Features #####
 *=========================================================================
 *[..]
 *		(+) There are 3 types of consoles where we can select and print
 *			(++) CONSOLE_STLINK
 *			(++) CONSOLE_SEGGER_JLINK
 *			(++) CONSOLE_SERIAL
 *
 *=========================================================================
 * 					##### How to configure the console print#####
 *=========================================================================
 *[..]
 *		(#) To Enable the CONSOLE print using STLink
 *			(+) Configure CONSOLE in preprocessor in project
 *				properties.
 * 				(++) Goto debug properties->C/C++ build->Settings
 * 				->MCU GCC compiler-> preprocessor,
 * 				set CONSOLE as CONSOLE_STLINK
 *
 * 		(#) To Enable the CONSOLE print using Segger Jlink
 * 			(+) Configure CONSOLE in preprocessor in project
 *				properties.
 * 				(++) Goto debug properties->C/C++ build->Settings
 * 				->MCU GCC compiler-> preprocessor,
 * 				set CONSOLE as CONSOLE_STLINK
 *
 *		(#) To Enable the CONSOLE print using Serial port
 * 			(+) Configure CONSOLE in preprocessor in project
 *				properties.
 * 				(++) Goto debug properties->C/C++ build->Settings
 * 				->MCU GCC compiler-> preprocessor,
 * 				set CONSOLE as CONSOLE_SERIAL
 *
 *		(#) Configure CONSOLE as STOP_CONSOLE_PRINT to disable the print.
 *
 *		Note: If CONSOLE is not defined in the preprocessor then by default
 * 				it will be defined in bsp_dbg_config.h.
 *
 *****************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "bsp_dbg_config.h"
#include "bsp_dbg_console.h"
#include "stm32h757xx.h"



//#if (DEBUG_PRINT_FLAG >= )DEBUG_PRINT_SERIAL || DEBUG_PRINT_STLINK_CONSOLE ||DEBUG_PRINT_JLINK_CONSOLE
////#ifdef __GNUC__
///* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
//   set to 'Yes') calls __io_putchar() */
//#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
//#else
//#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
//#endif /* __GNUC__ */
////#endif


/******************************************************************************
 * FUNCTION NAME: __io_putchar
 *
 * DESCRIPTION: Retarget printf to console or UART
 *
 *
 * PARAMETERS:
 *
 * RETURN VALUE:  int.
 *
 * Notes:  None.
 *
 *****************************************************************************/
int __io_putchar(int ch)
{
#if(CONSOLE > STOP_CONSOLE_PRINT)
#if (CONSOLE == CONSOLE_SERIAL)
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART1 and Loop until the end of transmission */
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
  return ch;
#endif
#if (CONSOLE >= CONSOLE_STLINK)
  ITM_SendChar(ch);
  return ch;
#endif
#endif
}



