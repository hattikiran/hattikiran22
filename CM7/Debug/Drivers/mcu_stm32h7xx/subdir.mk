################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/mcu_stm32h7xx/drv_gpio.c \
../Drivers/mcu_stm32h7xx/drv_hal.c 

OBJS += \
./Drivers/mcu_stm32h7xx/drv_gpio.o \
./Drivers/mcu_stm32h7xx/drv_hal.o 

C_DEPS += \
./Drivers/mcu_stm32h7xx/drv_gpio.d \
./Drivers/mcu_stm32h7xx/drv_hal.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/mcu_stm32h7xx/%.o Drivers/mcu_stm32h7xx/%.su: ../Drivers/mcu_stm32h7xx/%.c Drivers/mcu_stm32h7xx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H757xx -c -I../BSP/STM32H7XX -I../BSP/Config -I../../Middleware/threadx/ports/cortex_m7/gnu/inc -I../../Middleware/threadx/common/inc -I../../HAL/STM32H7xx_HAL_Driver/Inc -I../../HAL/STM32H7xx_HAL_Driver/Inc/Legacy -I../../HAL/CMSIS/Device/ST/STM32H7xx/Include -I../../HAL/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-mcu_stm32h7xx

clean-Drivers-2f-mcu_stm32h7xx:
	-$(RM) ./Drivers/mcu_stm32h7xx/drv_gpio.d ./Drivers/mcu_stm32h7xx/drv_gpio.o ./Drivers/mcu_stm32h7xx/drv_gpio.su ./Drivers/mcu_stm32h7xx/drv_hal.d ./Drivers/mcu_stm32h7xx/drv_hal.o ./Drivers/mcu_stm32h7xx/drv_hal.su

.PHONY: clean-Drivers-2f-mcu_stm32h7xx

