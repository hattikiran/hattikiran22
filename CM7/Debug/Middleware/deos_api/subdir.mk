################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middleware/deos_api/mw_board.c \
../Middleware/deos_api/mw_dio.c \
../Middleware/deos_api/mw_osal.c 

OBJS += \
./Middleware/deos_api/mw_board.o \
./Middleware/deos_api/mw_dio.o \
./Middleware/deos_api/mw_osal.o 

C_DEPS += \
./Middleware/deos_api/mw_board.d \
./Middleware/deos_api/mw_dio.d \
./Middleware/deos_api/mw_osal.d 


# Each subdirectory must supply rules for building sources it contributes
Middleware/deos_api/%.o Middleware/deos_api/%.su: ../Middleware/deos_api/%.c Middleware/deos_api/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H757xx -c -I../BSP/STM32H7XX -I../BSP/Config -I../../Middleware/threadx/ports/cortex_m7/gnu/inc -I../../Middleware/threadx/common/inc -I../../HAL/STM32H7xx_HAL_Driver/Inc -I../../HAL/STM32H7xx_HAL_Driver/Inc/Legacy -I../../HAL/CMSIS/Device/ST/STM32H7xx/Include -I../../HAL/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middleware-2f-deos_api

clean-Middleware-2f-deos_api:
	-$(RM) ./Middleware/deos_api/mw_board.d ./Middleware/deos_api/mw_board.o ./Middleware/deos_api/mw_board.su ./Middleware/deos_api/mw_dio.d ./Middleware/deos_api/mw_dio.o ./Middleware/deos_api/mw_dio.su ./Middleware/deos_api/mw_osal.d ./Middleware/deos_api/mw_osal.o ./Middleware/deos_api/mw_osal.su

.PHONY: clean-Middleware-2f-deos_api

