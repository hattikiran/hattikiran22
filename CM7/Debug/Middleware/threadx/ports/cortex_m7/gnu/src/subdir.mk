################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_misra.S \
C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_context_restore.S \
C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_context_save.S \
C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_control.S \
C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_disable.S \
C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_restore.S \
C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_schedule.S \
C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_stack_build.S \
C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_system_return.S \
C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_timer_interrupt.S 

OBJS += \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_misra.o \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_context_restore.o \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_context_save.o \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_control.o \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_disable.o \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_restore.o \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_schedule.o \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_stack_build.o \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_system_return.o \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_timer_interrupt.o 

S_UPPER_DEPS += \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_misra.d \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_context_restore.d \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_context_save.d \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_control.d \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_disable.d \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_restore.d \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_schedule.d \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_stack_build.d \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_system_return.d \
./Middleware/threadx/ports/cortex_m7/gnu/src/tx_timer_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
Middleware/threadx/ports/cortex_m7/gnu/src/tx_misra.o: C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_misra.S Middleware/threadx/ports/cortex_m7/gnu/src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_context_restore.o: C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_context_restore.S Middleware/threadx/ports/cortex_m7/gnu/src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_context_save.o: C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_context_save.S Middleware/threadx/ports/cortex_m7/gnu/src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_control.o: C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_control.S Middleware/threadx/ports/cortex_m7/gnu/src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_disable.o: C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_disable.S Middleware/threadx/ports/cortex_m7/gnu/src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_restore.o: C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_restore.S Middleware/threadx/ports/cortex_m7/gnu/src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_schedule.o: C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_schedule.S Middleware/threadx/ports/cortex_m7/gnu/src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_stack_build.o: C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_stack_build.S Middleware/threadx/ports/cortex_m7/gnu/src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_system_return.o: C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_system_return.S Middleware/threadx/ports/cortex_m7/gnu/src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Middleware/threadx/ports/cortex_m7/gnu/src/tx_timer_interrupt.o: C:/Users/khatti/STM32CubeIDE/workspace_1.8.0/DEOS_V2.00.02/Middleware/threadx/ports/cortex_m7/gnu/src/tx_timer_interrupt.S Middleware/threadx/ports/cortex_m7/gnu/src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Middleware-2f-threadx-2f-ports-2f-cortex_m7-2f-gnu-2f-src

clean-Middleware-2f-threadx-2f-ports-2f-cortex_m7-2f-gnu-2f-src:
	-$(RM) ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_misra.d ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_misra.o ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_context_restore.d ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_context_restore.o ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_context_save.d ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_context_save.o ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_control.d ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_control.o ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_disable.d ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_disable.o ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_restore.d ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_interrupt_restore.o ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_schedule.d ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_schedule.o ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_stack_build.d ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_stack_build.o ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_system_return.d ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_thread_system_return.o ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_timer_interrupt.d ./Middleware/threadx/ports/cortex_m7/gnu/src/tx_timer_interrupt.o

.PHONY: clean-Middleware-2f-threadx-2f-ports-2f-cortex_m7-2f-gnu-2f-src

