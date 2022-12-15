################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../BSP/STM32H7XX/startup_stm32h757xihx.s 

C_SRCS += \
../BSP/STM32H7XX/stm32h7xx_hal_msp.c \
../BSP/STM32H7XX/stm32h7xx_it.c \
../BSP/STM32H7XX/system_stm32h7xx_dualcore_boot_cm4_cm7.c 

OBJS += \
./BSP/STM32H7XX/startup_stm32h757xihx.o \
./BSP/STM32H7XX/stm32h7xx_hal_msp.o \
./BSP/STM32H7XX/stm32h7xx_it.o \
./BSP/STM32H7XX/system_stm32h7xx_dualcore_boot_cm4_cm7.o 

S_DEPS += \
./BSP/STM32H7XX/startup_stm32h757xihx.d 

C_DEPS += \
./BSP/STM32H7XX/stm32h7xx_hal_msp.d \
./BSP/STM32H7XX/stm32h7xx_it.d \
./BSP/STM32H7XX/system_stm32h7xx_dualcore_boot_cm4_cm7.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/STM32H7XX/%.o: ../BSP/STM32H7XX/%.s BSP/STM32H7XX/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
BSP/STM32H7XX/%.o BSP/STM32H7XX/%.su: ../BSP/STM32H7XX/%.c BSP/STM32H7XX/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H757xx -c -I../BSP/STM32H7XX -I../BSP/Config -I../../Middleware/threadx/ports/cortex_m7/gnu/inc -I../../Middleware/threadx/common/inc -I../../HAL/STM32H7xx_HAL_Driver/Inc -I../../HAL/STM32H7xx_HAL_Driver/Inc/Legacy -I../../HAL/CMSIS/Device/ST/STM32H7xx/Include -I../../HAL/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSP-2f-STM32H7XX

clean-BSP-2f-STM32H7XX:
	-$(RM) ./BSP/STM32H7XX/startup_stm32h757xihx.d ./BSP/STM32H7XX/startup_stm32h757xihx.o ./BSP/STM32H7XX/stm32h7xx_hal_msp.d ./BSP/STM32H7XX/stm32h7xx_hal_msp.o ./BSP/STM32H7XX/stm32h7xx_hal_msp.su ./BSP/STM32H7XX/stm32h7xx_it.d ./BSP/STM32H7XX/stm32h7xx_it.o ./BSP/STM32H7XX/stm32h7xx_it.su ./BSP/STM32H7XX/system_stm32h7xx_dualcore_boot_cm4_cm7.d ./BSP/STM32H7XX/system_stm32h7xx_dualcore_boot_cm4_cm7.o ./BSP/STM32H7XX/system_stm32h7xx_dualcore_boot_cm4_cm7.su

.PHONY: clean-BSP-2f-STM32H7XX

