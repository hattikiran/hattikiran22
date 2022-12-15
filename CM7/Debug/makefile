################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middleware/threadx/ports/cortex_m7/gnu/src/subdir.mk
-include Middleware/threadx/common/src/subdir.mk
-include Middleware/deos_api/subdir.mk
-include HAL/STM32H7xx_HAL_Driver/subdir.mk
-include Drivers/mcu_stm32h7xx/subdir.mk
-include Drivers/board/subdir.mk
-include BSP/STM32H7XX/subdir.mk
-include BSP/subdir.mk
-include Application/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := DEOS_V2.00.02_CM7
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
DEOS_V2.00.02_CM7.elf \

MAP_FILES += \
DEOS_V2.00.02_CM7.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
DEOS_V2.00.02_CM7.list \


# All Target
all:
	+@$(MAKE) --no-print-directory pre-build && $(MAKE) --no-print-directory main-build

# Main-build Target
main-build: DEOS_V2.00.02_CM7.elf secondary-outputs

# Tool invocations
DEOS_V2.00.02_CM7.elf DEOS_V2.00.02_CM7.map: $(OBJS) $(USER_OBJS) C:\Users\khatti\STM32CubeIDE\workspace_1.8.0\DEOS_V2.00.02\CM7\STM32H757XIHX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "DEOS_V2.00.02_CM7.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\Users\khatti\STM32CubeIDE\workspace_1.8.0\DEOS_V2.00.02\CM7\STM32H757XIHX_FLASH.ld" --specs=nosys.specs -Wl,-Map="DEOS_V2.00.02_CM7.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

DEOS_V2.00.02_CM7.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "DEOS_V2.00.02_CM7.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) DEOS_V2.00.02_CM7.elf DEOS_V2.00.02_CM7.list DEOS_V2.00.02_CM7.map default.size.stdout
	-@echo ' '

pre-build:
	cmd /c "..\..\Project\backup.bat C:\Users\khatti\STM32CubeIDE\workspace_1.8.0\DEOS_V2.00.02\CM7\Debug";
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified pre-build

-include ../makefile.targets
