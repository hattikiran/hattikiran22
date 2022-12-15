/******************************************************************************
 * FILE NAME:  drv_gpio.c
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
#include "drv_gpio.h"
#include "stm32h7xx_hal.h"



/******************************************************************************
 * Function Prototypes
 *****************************************************************************/
//void EnableClock(uint16_t port);
void InitGPIO(uint16_t port, GPIO_InitTypeDef *GPIO_InitStruct);
uint16_t PinConvert(uint16_t pin);
uint32_t ModeConvert(uint32_t mode);
uint32_t PullConvert(uint32_t pull);
uint32_t SpeedConvert(uint32_t speed);
uint32_t AlternateFunctionConvert(uint32_t alt_fcn);
uint8_t GetPinNumfromBaseAdd(uint16_t pinAddressValue);
GPIO_TypeDef *PortConvert(uint16_t port);

/******************************************************************************
 * FUNCTION NAME:  DRV_GPIOClockEnable
 *
 * DESCRIPTION:
 * Enable port clock.
 *
 * PARAMETERS:
 * port		uint16_t		port of the clock
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void DRV_GPIOClockEnable(uint16_t port){
	switch (port){
	case DRV_GPIOA:
		__HAL_RCC_GPIOA_CLK_ENABLE();
		break;
	case DRV_GPIOB:
		__HAL_RCC_GPIOB_CLK_ENABLE();
		break;
	case DRV_GPIOC:
		__HAL_RCC_GPIOC_CLK_ENABLE();
		break;
	case DRV_GPIOD:
		__HAL_RCC_GPIOD_CLK_ENABLE();
		break;
	case DRV_GPIOE:
		__HAL_RCC_GPIOE_CLK_ENABLE();
		break;
	case DRV_GPIOF:
		__HAL_RCC_GPIOF_CLK_ENABLE();
		break;
	case DRV_GPIOG:
		__HAL_RCC_GPIOG_CLK_ENABLE();
		break;
	case DRV_GPIOH:
		__HAL_RCC_GPIOH_CLK_ENABLE();
		break;
	case DRV_GPIOI:
		__HAL_RCC_GPIOI_CLK_ENABLE();
		break;
	case DRV_GPIOJ:
		__HAL_RCC_GPIOJ_CLK_ENABLE();
		break;
	case DRV_GPIOK:
		__HAL_RCC_GPIOK_CLK_ENABLE();
		break;
	default:
		//TODO put error message here
		break;
	}

}

/******************************************************************************
 * FUNCTION NAME:  DRV_GPIOInitialize
 *
 * DESCRIPTION:
 * This function takes the Middleware GPIO handle structure and  calls the
 * HAL layer GPIO Init function to initialize the GPIO pin.
 *
 * PARAMETERS:
 * *gpio		dio_t		GPIO handle structure
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void DRV_GPIOInitialize(const dio_t *gpio){
	//this is where bsp_gpio.h define conversion to HAL is done
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_TypeDef *port;

	uint16_t pin;
	uint32_t mode;
	uint32_t pull;
	uint32_t speed;
	uint32_t alternate_fcn;

	port = PortConvert(gpio->port);
	pin = PinConvert(gpio->pins);
	mode = ModeConvert(gpio->mode);
	pull = PullConvert(gpio->pull);
	speed = SpeedConvert(gpio->speed);
	alternate_fcn = AlternateFunctionConvert(gpio->alternate_fcn);

	HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
	GPIO_InitStruct.Pin = pin;
	GPIO_InitStruct.Mode = mode;
	GPIO_InitStruct.Pull = pull;
	GPIO_InitStruct.Speed = speed;
	GPIO_InitStruct.Alternate = alternate_fcn;

	DRV_GPIOClockEnable(gpio->port);
	HAL_GPIO_Init(port, &GPIO_InitStruct);

}

/******************************************************************************
 * FUNCTION NAME:  DRV_GPIODeInitialize
 *
 * DESCRIPTION:
 * This function takes the Middleware GPIO handle structure and  calls the
 * HAL layer GPIO DeInit function to deinitialize the GPIO pin.
 *
 * PARAMETERS:
 * *gpio		dio_t		GPIO handle structure
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void DRV_GPIODeInitialize(const dio_t *gpio){
	GPIO_TypeDef *port;
	uint16_t pin;

	port = PortConvert(gpio->port);
	pin = PinConvert(gpio->pins);

	HAL_GPIO_DeInit(port, pin);
}

/******************************************************************************
 * FUNCTION NAME:  DRV_GPIOToggle
 *
 * DESCRIPTION:
 * This function takes the Middleware GPIO handle structure and  calls the
 * HAL layer GPIO DeInit function to deinitialize the GPIO pin.
 *
 * PARAMETERS:
 * *gpio		dio_t		GPIO handle structure
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void DRV_GPIOToggle(dio_t *gpio){
	GPIO_TypeDef *port;
	uint16_t pin;

	port = PortConvert(gpio->port);
	pin = PinConvert(gpio->pins);

	HAL_GPIO_TogglePin(port, pin);
}

/******************************************************************************
 * FUNCTION NAME:  DRV_GPIOSet
 *
 * DESCRIPTION:
 * This function sets the pin's state to high or low based on the received
 * value.
 *
 * PARAMETERS:
 * *gpio		dio_t		GPIO handle structure
 * value		bool		Value to set
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void DRV_GPIOSet(dio_t *gpio, bool value){
	GPIO_TypeDef *port;
	uint16_t pin;

	port = PortConvert(gpio->port);
	pin = PinConvert(gpio->pins);

	if (value){
		HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
	}else{
		HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
	}
}

/******************************************************************************
 * FUNCTION NAME:  DRV_GPIOGet
 *
 * DESCRIPTION:
 * This function gets the pin's state from UC and returns the value.
 *
 * PARAMETERS:
 * *gpio		dio_t		GPIO handle structure
 * *value		uint32_t	value received from the UC
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void DRV_GPIOGet(dio_t *gpio, uint32_t *value){
	GPIO_TypeDef *port;
	uint16_t pin;

	port = PortConvert(gpio->port);
	pin = PinConvert(gpio->pins);

	if(HAL_GPIO_ReadPin(port,pin)){
		*value = 1;
	}else{
		*value = 0;
	}
}

void (*EXTI_Callback)(uint16_t pin);

//this goes in drv gpio file
void DRV_ITConfig(void (*callback)(uint16_t)){
	EXTI_Callback = callback;
	//TODO: See if we can put it in an array
	//For Tamper pin
	HAL_NVIC_SetPriority(EXTI0_IRQn, 7, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
	//For Wakeup pin
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 7, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI0_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(PinConvert(DRV_GPIO_PIN_0));
}

void EXTI15_10_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(PinConvert(DRV_GPIO_PIN_13));
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_pin){
	//Call a function
	uint8_t pin = GetPinNumfromBaseAdd(GPIO_pin);
	EXTI_Callback(pin);

}

/******************************************************************************
 * FUNCTION NAME:  PortConvert
 *
 * DESCRIPTION:
 * Convert Driver port to HAL port base value.
 *
 * PARAMETERS:
 * port		uint16_t		driver port value
 *
 * RETURN VALUE: 
 * *GPIO_TypeDef		HAL base port value
 *
 * NOTES:   None.
 *
 *****************************************************************************/
GPIO_TypeDef *PortConvert(uint16_t port){
	GPIO_TypeDef *result_port;
	switch (port){
	case DRV_GPIOA:
		result_port = GPIOA;
		break;
	case DRV_GPIOB:
		result_port = GPIOB;
		break;
	case DRV_GPIOC:
		result_port = GPIOC;
		break;
	case DRV_GPIOD:
		result_port = GPIOD;
		break;
	case DRV_GPIOE:
		result_port = GPIOE;
		break;
	case DRV_GPIOF:
		result_port = GPIOF;
		break;
	case DRV_GPIOG:
		result_port = GPIOG;
		break;
	case DRV_GPIOH:
		result_port = GPIOH;
		break;
	case DRV_GPIOI:
		result_port = GPIOI;
		break;
	case DRV_GPIOJ:
		result_port = GPIOJ;
		break;
	case DRV_GPIOK:
		result_port = GPIOK;
		break;
	default:
		//TODO put error message here
		break;
	}
	return result_port;
}

/******************************************************************************
 * FUNCTION NAME:  PinConvert
 *
 * DESCRIPTION:
 * Convert Driver pin to HAL pin base value.
 *
 * PARAMETERS:
 * uint16_t		pin		Driver pin value
 *
 * RETURN VALUE:
 * uint16_t		return_value	HAL base pin value
 *
 * NOTES:   None.
 *
 *****************************************************************************/
uint16_t PinConvert(uint16_t pin){

	uint16_t return_value;

	switch(pin){
	case DRV_GPIO_PIN_0:
		return_value = GPIO_PIN_0;
		break;
	case DRV_GPIO_PIN_1:
		return_value = GPIO_PIN_1;
		break;
	case DRV_GPIO_PIN_2:
		return_value = GPIO_PIN_2;
		break;
	case DRV_GPIO_PIN_3:
		return_value = GPIO_PIN_3;
		break;
	case DRV_GPIO_PIN_4:
		return_value = GPIO_PIN_4;
		break;
	case DRV_GPIO_PIN_5:
		return_value = GPIO_PIN_5;
		break;
	case DRV_GPIO_PIN_6:
		return_value = GPIO_PIN_6;
		break;
	case DRV_GPIO_PIN_7:
		return_value = GPIO_PIN_7;
		break;
	case DRV_GPIO_PIN_8:
		return_value = GPIO_PIN_8;
		break;
	case DRV_GPIO_PIN_9:
		return_value = GPIO_PIN_9;
		break;
	case DRV_GPIO_PIN_10:
		return_value = GPIO_PIN_10;
		break;
	case DRV_GPIO_PIN_11:
		return_value = GPIO_PIN_11;
		break;
	case DRV_GPIO_PIN_12:
		return_value = GPIO_PIN_12;
		break;
	case DRV_GPIO_PIN_13:
		return_value = GPIO_PIN_13;
		break;
	case DRV_GPIO_PIN_14:
		return_value = GPIO_PIN_14;
		break;
	case DRV_GPIO_PIN_15:
		return_value = GPIO_PIN_15;
		break;
	default:
		break;
	}

	return return_value;
}

/******************************************************************************
 * FUNCTION NAME:  PullConvert
 *
 * DESCRIPTION:
 * Convert push pull value to HAL base push pull value.
 *
 * PARAMETERS:
 * uint32_t		pull	Driver port value
 *
 * RETURN VALUE: HAL base push pull value
 *
 * NOTES:   None.
 *
 *****************************************************************************/
uint32_t PullConvert(uint32_t pull){
	uint32_t return_value;

	switch(pull){
	case DRV_GPIO_NOPULL:
		return_value = GPIO_NOPULL;
		break;
	case DRV_GPIO_PULLUP:
		return_value = GPIO_PULLUP;
		break;
	case DRV_GPIO_PULLDOWN:
		return_value = GPIO_PULLDOWN;
		break;
	default:
		break;
	}
	return return_value;
}

/******************************************************************************
 * FUNCTION NAME:  SpeedConvert
 *
 * DESCRIPTION:
 * Convert Driver pin speed value to HAL base pin speed value.
 *
 * PARAMETERS:
 * uint32_t		speed		Driver speed value
 *
 * RETURN VALUE:
 * uint32_t		return_value	HAL base speed value
 *
 * NOTES:   None.
 *
 *****************************************************************************/
uint32_t SpeedConvert(uint32_t speed){
	uint32_t return_value;

	switch(speed){
	case DRV_GPIO_SPEED_FREQ_LOW:
		return_value = GPIO_SPEED_FREQ_LOW;
		break;
	case DRV_GPIO_SPEED_FREQ_MEDIUM:
		return_value = GPIO_SPEED_FREQ_MEDIUM;
		break;
	case DRV_GPIO_SPEED_FREQ_HIGH:
		return_value = GPIO_SPEED_FREQ_HIGH;
		break;
	case DRV_GPIO_SPEED_FREQ_VERY_HIGH:
		return_value = GPIO_SPEED_FREQ_VERY_HIGH;
		break;
	default:
		break;
	}
	return return_value;
}

/******************************************************************************
 * FUNCTION NAME:  AlternateFunctionConvert
 *
 * DESCRIPTION:
 * Convert Driver alt_fcn value to HAL base alt_fcn value.
 *
 * PARAMETERS:
 * alt_fcn			uint32_t		alternate function driver value
 *
 * RETURN VALUE:
 * uint32_t			alternate function HAL base value
 *
 * NOTES:   None.
 *
 *****************************************************************************/
uint32_t AlternateFunctionConvert(uint32_t alt_fcn){
	uint32_t return_value;

	switch(alt_fcn){
	case DRV_GPIO_ALTERNATE_FC0:
		return_value = (uint8_t)0x00;
		break;
	case DRV_GPIO_ALTERNATE_FC1:
		return_value = (uint8_t)0x01;
			break;
	case DRV_GPIO_ALTERNATE_FC2:
		return_value = (uint8_t)0x02;
			break;
	case DRV_GPIO_ALTERNATE_FC3:
		return_value = (uint8_t)0x03;
			break;
	case DRV_GPIO_ALTERNATE_FC4:
		return_value = (uint8_t)0x04;
			break;
	case DRV_GPIO_ALTERNATE_FC5:
		return_value = (uint8_t)0x05;
			break;
	case DRV_GPIO_ALTERNATE_FC6:
		return_value = (uint8_t)0x06;
			break;
	case DRV_GPIO_ALTERNATE_FC7:
		return_value = (uint8_t)0x07;
			break;
	case DRV_GPIO_ALTERNATE_FC8:
		return_value = (uint8_t)0x08;
			break;
	case DRV_GPIO_ALTERNATE_FC9:
		return_value = (uint8_t)0x09;
			break;
	case DRV_GPIO_ALTERNATE_FC10:
		return_value = (uint8_t)0x10;
			break;
	case DRV_GPIO_ALTERNATE_FC11:
		return_value = (uint8_t)0x11;
			break;
	case DRV_GPIO_ALTERNATE_FC12:
		return_value = (uint8_t)0x12;
			break;
	case DRV_GPIO_ALTERNATE_FC13:
		return_value = (uint8_t)0x13;
			break;
	case DRV_GPIO_ALTERNATE_FC14:
		return_value = (uint8_t)0x14;
			break;
	case DRV_GPIO_ALTERNATE_FC15:
		return_value = (uint8_t)0x15;
			break;
	}

	return return_value;
}

/******************************************************************************
 * FUNCTION NAME:  InitGPIO
 *
 * DESCRIPTION:
 * call HAL GPIO init function.
 *
 * PARAMETERS:
 * port					uint16_t				port of the pin
 * *GPIO_InitStruct		GPIO_InitTypeDef		pin init values
 *
 * RETURN VALUE: None.
 *
 * NOTES:   None.
 *
 *****************************************************************************/
void InitGPIO(uint16_t port, GPIO_InitTypeDef *GPIO_InitStruct){
	switch (port){
	case DRV_GPIOA:
		HAL_GPIO_Init(GPIOA, GPIO_InitStruct);
		break;
	case DRV_GPIOB:
		HAL_GPIO_Init(GPIOB, GPIO_InitStruct);
		break;
	case DRV_GPIOC:
		HAL_GPIO_Init(GPIOC, GPIO_InitStruct);
		break;
	case DRV_GPIOD:
		HAL_GPIO_Init(GPIOD, GPIO_InitStruct);
		break;
	case DRV_GPIOE:
		HAL_GPIO_Init(GPIOE, GPIO_InitStruct);
		break;
	case DRV_GPIOF:
		HAL_GPIO_Init(GPIOF, GPIO_InitStruct);
		break;
	case DRV_GPIOG:
		HAL_GPIO_Init(GPIOG, GPIO_InitStruct);
		break;
	case DRV_GPIOH:
		HAL_GPIO_Init(GPIOH, GPIO_InitStruct);
		break;
	case DRV_GPIOI:
		HAL_GPIO_Init(GPIOI, GPIO_InitStruct);
		break;
	case DRV_GPIOJ:
		HAL_GPIO_Init(GPIOJ, GPIO_InitStruct);
		break;
	case DRV_GPIOK:
		HAL_GPIO_Init(GPIOK, GPIO_InitStruct);
		break;
	default:
		//TODO put error message here
		break;
	}

}

/******************************************************************************
 * FUNCTION NAME:  ModeConvert
 *
 * DESCRIPTION:
 * Convert Driver mode value to HAL base mode value.
 *
 * PARAMETERS:
 * mode		uint32_t		Driver port value
 *
 * RETURN VALUE:
 * uint32_t				HAL base port value
 *
 * NOTES:   None.
 *
 *****************************************************************************/
uint32_t ModeConvert(uint32_t mode){
	uint32_t return_val;
	switch(mode){
	case DRV_GPIO_MODE_INPUT:
		return_val = GPIO_MODE_INPUT;
		break;
	case DRV_GPIO_MODE_OUTPUT_PP:
		return_val = GPIO_MODE_OUTPUT_PP;
		break;
	case DRV_GPIO_MODE_OUTPUT_OD:
		return_val = GPIO_MODE_OUTPUT_OD;
		break;
	case DRV_GPIO_MODE_AF_PP:
		return_val = GPIO_MODE_AF_PP;
		break;
	case DRV_GPIO_MODE_AF_OD:
		return_val = GPIO_MODE_AF_OD;
		break;
	case DRV_GPIO_MODE_ANALOG:
		return_val = GPIO_MODE_ANALOG;
		break;
	case DRV_GPIO_MODE_IT_RISING:
		return_val = GPIO_MODE_IT_RISING;
		break;
	case DRV_GPIO_MODE_IT_FALLING:
		return_val = GPIO_MODE_IT_FALLING;
		break;
	case DRV_GPIO_MODE_IT_RISING_FALLING:
		return_val = GPIO_MODE_IT_RISING_FALLING;
		break;
	default:
		break;
	}
	return return_val;
}

/******************************************************************************
 * FUNCTION NAME:  GetPinNumfromBaseAdd
 *
 * DESCRIPTION:
 * Convert Driver pin value to HAL base pin address value.
 *
 * PARAMETERS:
 * pinAddressValue	uint16_t		Driver pin value
 *
 * RETURN VALUE:
 * uint8_t				HAL base pin address value
 *
 * NOTES:   None.
 *
 *****************************************************************************/
uint8_t GetPinNumfromBaseAdd(uint16_t pinAddressValue){
	uint16_t return_value;

	switch(pinAddressValue){
	case GPIO_PIN_0:
		return_value = DRV_GPIO_PIN_0;
		break;
	case GPIO_PIN_1:
		return_value = DRV_GPIO_PIN_1;
		break;
	case GPIO_PIN_2:
		return_value = DRV_GPIO_PIN_2;
		break;
	case GPIO_PIN_3:
		return_value = DRV_GPIO_PIN_3;
		break;
	case GPIO_PIN_4:
		return_value = DRV_GPIO_PIN_4;
		break;
	case GPIO_PIN_5:
		return_value = DRV_GPIO_PIN_5;
		break;
	case GPIO_PIN_6:
		return_value = DRV_GPIO_PIN_6;
		break;
	case GPIO_PIN_7:
		return_value = DRV_GPIO_PIN_7;
		break;
	case GPIO_PIN_8:
		return_value = DRV_GPIO_PIN_8;
		break;
	case GPIO_PIN_9:
		return_value = DRV_GPIO_PIN_9;
		break;
	case GPIO_PIN_10:
		return_value = DRV_GPIO_PIN_10;
		break;
	case GPIO_PIN_11:
		return_value = DRV_GPIO_PIN_11;
		break;
	case GPIO_PIN_12:
		return_value = DRV_GPIO_PIN_12;
		break;
	case GPIO_PIN_13:
		return_value = DRV_GPIO_PIN_13;
		break;
	case GPIO_PIN_14:
		return_value = DRV_GPIO_PIN_14;
		break;
	case GPIO_PIN_15:
		return_value = DRV_GPIO_PIN_15;
		break;
	default:
		break;
	}

	return return_value;
}
