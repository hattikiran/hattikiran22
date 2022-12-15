/*
 * bsp_gpio.h
 *
 *  Created on: Jul 6, 2022
 *      Author: htank
 */

#ifndef BSP_GPIO_H_
#define BSP_GPIO_H_

//MW GPIO PINS def //bsp_gpio.h
#define DRV_GPIO_PIN_0		0
#define DRV_GPIO_PIN_1		1
#define DRV_GPIO_PIN_2		2
#define DRV_GPIO_PIN_3		3
#define DRV_GPIO_PIN_4		4
#define DRV_GPIO_PIN_5		5
#define DRV_GPIO_PIN_6		6
#define DRV_GPIO_PIN_7		7
#define DRV_GPIO_PIN_8		8
#define DRV_GPIO_PIN_9		9
#define DRV_GPIO_PIN_10		10
#define DRV_GPIO_PIN_11		11
#define DRV_GPIO_PIN_12		12
#define DRV_GPIO_PIN_13		13
#define DRV_GPIO_PIN_14		14
#define DRV_GPIO_PIN_15		15

//GPIO ports
#define DRV_GPIOA	1
#define DRV_GPIOB	2
#define DRV_GPIOC	3
#define DRV_GPIOD	4
#define DRV_GPIOE	5
#define DRV_GPIOF	6
#define DRV_GPIOG	7
#define DRV_GPIOH	8
#define DRV_GPIOI	9
#define DRV_GPIOJ	10
#define DRV_GPIOK	11

//GPIO Speed
#define  DRV_GPIO_SPEED_FREQ_LOW         1
#define  DRV_GPIO_SPEED_FREQ_MEDIUM      2
#define  DRV_GPIO_SPEED_FREQ_HIGH        3
#define  DRV_GPIO_SPEED_FREQ_VERY_HIGH	 4

//GPIO PULL
#define  DRV_GPIO_NOPULL        1
#define  DRV_GPIO_PULLUP        2
#define  DRV_GPIO_PULLDOWN  	3

//GPIO Modes
#define DRV_GPIO_MODE_INPUT                 1         /*!< Input Floating Mode                                                */
#define DRV_GPIO_MODE_OUTPUT_PP             2         /*!< Output Push Pull Mode                                              */
#define DRV_GPIO_MODE_OUTPUT_OD             3         /*!< Output Open Drain Mode                                             */
#define DRV_GPIO_MODE_AF_PP                 4         /*!< Alternate Function Push Pull Mode                                  */
#define DRV_GPIO_MODE_AF_OD  			    5
#define DRV_GPIO_MODE_ANALOG				6
#define DRV_GPIO_MODE_IT_RISING				7
#define DRV_GPIO_MODE_IT_FALLING			8
#define DRV_GPIO_MODE_IT_RISING_FALLING		9

#define	DRV_GPIO_ALTERNATE_FC0		0
#define	DRV_GPIO_ALTERNATE_FC1		1
#define	DRV_GPIO_ALTERNATE_FC2		2
#define	DRV_GPIO_ALTERNATE_FC3		3
#define	DRV_GPIO_ALTERNATE_FC4		4
#define	DRV_GPIO_ALTERNATE_FC5		5
#define	DRV_GPIO_ALTERNATE_FC6		6
#define	DRV_GPIO_ALTERNATE_FC7		7
#define	DRV_GPIO_ALTERNATE_FC8		8
#define	DRV_GPIO_ALTERNATE_FC9		9
#define	DRV_GPIO_ALTERNATE_FC10		10
#define	DRV_GPIO_ALTERNATE_FC11		11
#define	DRV_GPIO_ALTERNATE_FC12		12
#define	DRV_GPIO_ALTERNATE_FC13		13
#define	DRV_GPIO_ALTERNATE_FC14		14
#define	DRV_GPIO_ALTERNATE_FC15		15

//

//need to complete the list

//GPIO pin states
#define DRV_GPIO_PIN_RESET			0
#define DRV_GPIO_PIN_SET			1


//TODO: use the defines above for IO/Analog/pull and other settings
typedef struct{
	uint32_t mode;
	uint32_t speed;
	uint32_t pull;
	uint16_t pins;
	uint16_t port;
	uint32_t alternate_fcn;
	void (*io_callback)();
} dio_t;

void TamperButtonPressed();
void WakeupButtonPressed();

#endif /* BSP_GPIO_H_ */
