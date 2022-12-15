/**
 *****************************************************************************
 * FILE NAME:  bsp_dbg_console.h
 *
 * FILE FUNCTION: Marcos- Print to console or serial port
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
 * This file provides the macros to configure different levels of debug print.
 *
 *[..]
 *=========================================================================
 *					##### Features #####
 *=========================================================================
 *[..]
 *		(+) There are 6 types of print statements where we can select and print
 *			(++) PRINT_ESSENTIALS
 *			(++) PRINT_MINIMUM
 *			(++) PRINT_ERROR
 *			(++) PRINT_STUFF_DUMP
 *			(++) PRINT_LOG
 *			(++) PRINT_LOG_MORE
 *=========================================================================
 * 			##### How to configure the different levels of print#####
 *=========================================================================
 *	(#) Configure DEBUG_PRINT_FLAG in preprocessor in project properties.
 *
 * 		(+) For DEBUG_ESSENTIAL_PRINT to be enabled, then follow the steps below
 * 			(++) Goto debug properties->C/C++ build->Settings->MCU GCC compiler
 * 				-> preprocessor, set DEBUG_PRINT_FLAG as PRINT_ESSENTIALS
 *
 *		(+) Configure DEBUG_PRINT_FLAG as STOP_PRINT to disable the print.
 *
 *		Note: If DEBUG_PRINT_FLAG is not defined in the preprocessor then by default
 * 				it will be defined in bsp_dbg_config.h.
 *
 *
 *****************************************************************************/

#ifndef BSP_DBG_CONSOLE_H_
#define BSP_DBG_CONSOLE_H_


//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <stdint.h>
//#include <string.h>
//#include "math.h"
/* Includes ------------------------------------------------------------------*/
#include "bsp_dbg_config.h"



//The definition of DEBUG_PRINT_FLAG is done in the project->compiler->predefined
//symbols using the above defines as the setting

#if (DEBUG_PRINT_FLAG >= PRINT_ESSENTIALS)
	#define DEBUG_ESSENTIAL_PRINT(...)      do{printf(" [%s][%d]",__FUNCTION__,__LINE__); printf(__VA_ARGS__);printf("\n");}while(0)
#else
	#define DEBUG_ESSENTIAL_PRINT(...)
 	#define DEBUG_MIN_PRINT(...)
    #define DEBUG_ERR(...)
	#define DEBUG_STUFF_DUMP(...)
	#define DEBUG_LOG(...)
	#define DEBUG_LOG_MORE(...)
#endif

#if (DEBUG_PRINT_FLAG >= PRINT_MINIMUM)
	#define DEBUG_MIN_PRINT(...)        do{printf(" (DBG)[%s][%d]",__FUNCTION__,__LINE__); printf(__VA_ARGS__);printf("\n");}while(0)
#else
	#define DEBUG_MIN_PRINT(...)
	#define DEBUG_ERR(...)
	#define DEBUG_STUFF_DUMP(...)
	#define DEBUG_LOG(...)
	#define DEBUG_LOG_MORE(...)
#endif

#if (DEBUG_PRINT_FLAG >= PRINT_ERROR)
	#define DEBUG_ERR(...)      do{printf(" !!!!!! (ERR)[%s][%d]",__FUNCTION__,__LINE__); printf(__VA_ARGS__);printf("\n");}while(0)
#else
	#define DEBUG_ERR(...)
	#define DEBUG_STUFF_DUMP(...)
	#define DEBUG_LOG(...)
	#define DEBUG_LOG_MORE(...)
#endif

#if  (DEBUG_PRINT_FLAG >= PRINT_STUFF_DUMP)
	#define DEBUG_STUFF_DUMP(...)       do{printf(" (DUMP)[%s][%d]",__FUNCTION__,__LINE__); printf(__VA_ARGS__);printf("\n");}while(0)
#else
	#define DEBUG_STUFF_DUMP(...)
	#define DEBUG_LOG(...)
    #define DEBUG_LOG_MORE(...)
#endif

#if (DEBUG_PRINT_FLAG >= PRINT_LOG)
	#define DEBUG_LOG(...)      do{printf(" (LOG)[%s][%d]",__FUNCTION__,__LINE__); printf(__VA_ARGS__);printf("\n");}while(0)
#else
	#define DEBUG_LOG(...)
	#define DEBUG_LOG_MORE(...)
#endif

#if (DEBUG_PRINT_FLAG >= PRINT_LOG_MORE)
	#define DEBUG_LOG_MORE(...) do{printf(" (LOG_MORE)[%s][%d]",__FUNCTION__,__LINE__); printf(__VA_ARGS__);printf("\n");}while(0)
#else
    #define DEBUG_LOG_MORE(...)
#endif



#if 0
#define DEBUG_PRINT_NO_OVERHEAD(...) do {printf(__VA_ARGS__);} while(0)
#else
#define DEBUG_PRINT_NO_OVERHEAD(...)
#endif

#if 0
#define DEBUG_WIFI_PRINT_NO_OVERHEAD(...) do {printf(__VA_ARGS__);} while(0)
#else
#define DEBUG_WIFI_PRINT_NO_OVERHEAD(...)
#endif



#endif /* BSP_DBG_CONSOLE_H_ */
