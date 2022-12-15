/******************************************************************************
 * FILE NAME:  drv_gpio.h
 *
 * FILE FUNCTION:
 *
 * NOTES:
 *
 * PROTOCOL VERSIONS:
 *
 * FILE AUTHOR(S):  Hiren
 *****************************************************************************/
 
#ifndef MCU_DRV_GPIO_H_
#define MCU_DRV_GPIO_H_
/******************************************************************************
 * Includes
 *****************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "../../BSP/bsp_gpio.h"
#include "../../BSP/bsp_board_decc_3.h"
//#include "../../bsp/bsp_mcu_stm32h757.h"

/******************************************************************************
 * Function Prototypes
 *****************************************************************************/
void DRV_GPIOInitialize(const dio_t *gpio);
void DRV_GPIODeInitialize(const dio_t *gpio);

void DRV_GPIOToggle(dio_t *gpio);
void DRV_GPIOSet(dio_t *gpio, bool value);
void DRV_GPIOGet(dio_t *gpio, uint32_t *value);
void DRV_GPIOCallback();
//void DRV_GPIOCLockEnable(uint16_t port);

void DRV_ITConfig(void (*callback)(uint16_t pin));

#endif /* MCU_DRV_GPIO_H_ */
