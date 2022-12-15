/******************************************************************************
 * FILE NAME:  bsp_dbg_config.h
 *
 * FILE FUNCTION: This file provides the selection between
 * the different interfaces to print- STLINK, J-LINK and SERIAL
 *
 * NOTES:
 * (#) CONSOLE_STLINK : We need to do following modifications in debug configuration
 *
 * 		(++) Debugger-> Debug probe-> ST LINK
 * 		(++) Debugger-> Interface-> SWD
 * 		(++) Debugger-> Serial wire viewer-> Enable
 * 		(++) Core clock: You have to configure the correct clock frequency, that you have initialize within
 * 		 your application
 * 		(++) SWO clock should be 2000KHz
 *
 * (#) CONSOLE_SEGGER_JLINK : We need to do following modifications in debug configuration
 *
 * 		(++) Debugger-> Debug probe-> Segger J-Link
 * 		(++) Debugger-> Interface-> SWD
 * 		(++) Debugger-> Serial wire viewer-> Enable
 * 		(++) Core clock: You have to configure the correct clock frequency, that you have initialize within
 * 			your application
 * 		(++) SWO clock should be 2000KHz
 *
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
 * This file provides the macros to configure different levels of debug print.
 *
 *****************************************************************************/

#ifndef CONFIG_BSP_DBG_CONFIG_H_
#define CONFIG_BSP_DBG_CONFIG_H_


#define CONSOLE_SERIAL				3
#define CONSOLE_SEGGER_JLINK		2
#define CONSOLE_STLINK				1
#define STOP_CONSOLE_PRINT			0

/*Function Return states*/
#define PRINT_LOG_MORE      6
#define PRINT_LOG           5
#define PRINT_STUFF_DUMP    4
#define PRINT_ERROR         3
#define PRINT_MINIMUM       2
#define PRINT_ESSENTIALS    1
#define STOP_PRINT          0

#ifndef DEBUG_PRINT_FLAG
	#define DEBUG_PRINT_FLAG  PRINT_ESSENTIALS
#endif

#ifndef CONSOLE
	#define CONSOLE	DEBUG_PRINT_SERIAL
#endif



#endif /* CONFIG_BSP_DBG_CONFIG_H_ */
