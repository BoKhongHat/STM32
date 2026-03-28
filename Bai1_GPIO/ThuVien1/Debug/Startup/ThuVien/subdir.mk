################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Startup/ThuVien/stm32re.c 

OBJS += \
./Startup/ThuVien/stm32re.o 

C_DEPS += \
./Startup/ThuVien/stm32re.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/ThuVien/%.o Startup/ThuVien/%.su Startup/ThuVien/%.cyclo: ../Startup/ThuVien/%.c Startup/ThuVien/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Startup-2f-ThuVien

clean-Startup-2f-ThuVien:
	-$(RM) ./Startup/ThuVien/stm32re.cyclo ./Startup/ThuVien/stm32re.d ./Startup/ThuVien/stm32re.o ./Startup/ThuVien/stm32re.su

.PHONY: clean-Startup-2f-ThuVien

