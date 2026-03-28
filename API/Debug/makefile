################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Utilities/subdir.mk
-include ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/ucglib/subdir.mk
-include ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/serial/subdir.mk
-include ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/sensor/subdir.mk
-include ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/subdir.mk
-include ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/led/subdir.mk
-include ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/flash/subdir.mk
-include ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/buzzer/subdir.mk
-include ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/button/subdir.mk
-include ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Drivers/STM32F401RE_StdPeriph_Driver/src/subdir.mk
-include ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Drivers/CMSIS/Source/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
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


BUILD_ARTIFACT_NAME := Interruppt
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Interruppt.elf \

MAP_FILES += \
Interruppt.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Interruppt.list \


# All Target
all: main-build

# Main-build Target
main-build: Interruppt.elf secondary-outputs

# Tool invocations
Interruppt.elf Interruppt.map: $(OBJS) $(USER_OBJS) D:\Study_Loc\STM32\GPIO\API\STM32F401RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Interruppt.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\Study_Loc\STM32\GPIO\API\STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Interruppt.map" -Wl,--gc-sections -static -L"C:\Users\ADMIN\OneDrive\Máy tính\N23DCCI041-Tran Tien Loc\STUDY\Exam3k1\ThuVien_SDK_1.0.3_NUCLEO-F401RE-master\lib_stm" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Interruppt.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Interruppt.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Interruppt.elf Interruppt.list Interruppt.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
