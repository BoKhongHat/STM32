################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/ADMIN/OneDrive/Máy\ tính/N23DCCI041-Tran\ Tien\ Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/eventman.c \
C:/Users/ADMIN/OneDrive/Máy\ tính/N23DCCI041-Tran\ Tien\ Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/timer.c 

OBJS += \
./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/eventman.o \
./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/timer.o 

C_DEPS += \
./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/eventman.d \
./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/timer.d 


# Each subdirectory must supply rules for building sources it contributes
ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/eventman.o: C:/Users/ADMIN/OneDrive/Máy\ tính/N23DCCI041-Tran\ Tien\ Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/eventman.c ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Drivers/CMSIS/Include" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/button" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/buzzer" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/flash" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/led" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/sensor" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/serial" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/ucglib" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/timer.o: C:/Users/ADMIN/OneDrive/Máy\ tính/N23DCCI041-Tran\ Tien\ Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/timer.c ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Drivers/CMSIS/Include" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/button" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/buzzer" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/flash" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/led" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/sensor" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/serial" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/ucglib" -I"C:/Users/ADMIN/OneDrive/Máy tính/N23DCCI041-Tran Tien Loc/STUDY/Exam3k1/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThuVien_SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2d-master-2f-shared-2f-Middle-2f-rtos

clean-ThuVien_SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2d-master-2f-shared-2f-Middle-2f-rtos:
	-$(RM) ./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/eventman.cyclo ./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/eventman.d ./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/eventman.o ./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/eventman.su ./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/timer.cyclo ./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/timer.d ./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/timer.o ./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos/timer.su

.PHONY: clean-ThuVien_SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2d-master-2f-shared-2f-Middle-2f-rtos

