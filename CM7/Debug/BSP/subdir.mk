################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSP/bsp_dbg_console.c \
../BSP/syscalls.c \
../BSP/sysmem.c 

S_UPPER_SRCS += \
../BSP/tx_initialize_low_level.S 

OBJS += \
./BSP/bsp_dbg_console.o \
./BSP/syscalls.o \
./BSP/sysmem.o \
./BSP/tx_initialize_low_level.o 

S_UPPER_DEPS += \
./BSP/tx_initialize_low_level.d 

C_DEPS += \
./BSP/bsp_dbg_console.d \
./BSP/syscalls.d \
./BSP/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/%.o BSP/%.su: ../BSP/%.c BSP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H757xx -c -I../BSP/STM32H7XX -I../BSP/Config -I../../Middleware/threadx/ports/cortex_m7/gnu/inc -I../../Middleware/threadx/common/inc -I../../HAL/STM32H7xx_HAL_Driver/Inc -I../../HAL/STM32H7xx_HAL_Driver/Inc/Legacy -I../../HAL/CMSIS/Device/ST/STM32H7xx/Include -I../../HAL/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
BSP/%.o: ../BSP/%.S BSP/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-BSP

clean-BSP:
	-$(RM) ./BSP/bsp_dbg_console.d ./BSP/bsp_dbg_console.o ./BSP/bsp_dbg_console.su ./BSP/syscalls.d ./BSP/syscalls.o ./BSP/syscalls.su ./BSP/sysmem.d ./BSP/sysmem.o ./BSP/sysmem.su ./BSP/tx_initialize_low_level.d ./BSP/tx_initialize_low_level.o

.PHONY: clean-BSP

