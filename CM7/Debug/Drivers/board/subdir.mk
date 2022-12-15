################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/board/drv_board.c \
../Drivers/board/drv_dio.c 

OBJS += \
./Drivers/board/drv_board.o \
./Drivers/board/drv_dio.o 

C_DEPS += \
./Drivers/board/drv_board.d \
./Drivers/board/drv_dio.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/board/%.o Drivers/board/%.su: ../Drivers/board/%.c Drivers/board/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H757xx -c -I../BSP/STM32H7XX -I../BSP/Config -I../../Middleware/threadx/ports/cortex_m7/gnu/inc -I../../Middleware/threadx/common/inc -I../../HAL/STM32H7xx_HAL_Driver/Inc -I../../HAL/STM32H7xx_HAL_Driver/Inc/Legacy -I../../HAL/CMSIS/Device/ST/STM32H7xx/Include -I../../HAL/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-board

clean-Drivers-2f-board:
	-$(RM) ./Drivers/board/drv_board.d ./Drivers/board/drv_board.o ./Drivers/board/drv_board.su ./Drivers/board/drv_dio.d ./Drivers/board/drv_dio.o ./Drivers/board/drv_dio.su

.PHONY: clean-Drivers-2f-board

