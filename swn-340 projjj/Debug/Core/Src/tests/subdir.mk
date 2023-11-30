################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tests/bigToLittleEndian.c \
../Core/Src/tests/hw8.c \
../Core/Src/tests/led_soft_test.c \
../Core/Src/tests/main.c \
../Core/Src/tests/reader.c \
../Core/Src/tests/sqr_wave.c \
../Core/Src/tests/structs.c 

OBJS += \
./Core/Src/tests/bigToLittleEndian.o \
./Core/Src/tests/hw8.o \
./Core/Src/tests/led_soft_test.o \
./Core/Src/tests/main.o \
./Core/Src/tests/reader.o \
./Core/Src/tests/sqr_wave.o \
./Core/Src/tests/structs.o 

C_DEPS += \
./Core/Src/tests/bigToLittleEndian.d \
./Core/Src/tests/hw8.d \
./Core/Src/tests/led_soft_test.d \
./Core/Src/tests/main.d \
./Core/Src/tests/reader.d \
./Core/Src/tests/sqr_wave.d \
./Core/Src/tests/structs.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tests/%.o Core/Src/tests/%.su Core/Src/tests/%.cyclo: ../Core/Src/tests/%.c Core/Src/tests/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tests

clean-Core-2f-Src-2f-tests:
	-$(RM) ./Core/Src/tests/bigToLittleEndian.cyclo ./Core/Src/tests/bigToLittleEndian.d ./Core/Src/tests/bigToLittleEndian.o ./Core/Src/tests/bigToLittleEndian.su ./Core/Src/tests/hw8.cyclo ./Core/Src/tests/hw8.d ./Core/Src/tests/hw8.o ./Core/Src/tests/hw8.su ./Core/Src/tests/led_soft_test.cyclo ./Core/Src/tests/led_soft_test.d ./Core/Src/tests/led_soft_test.o ./Core/Src/tests/led_soft_test.su ./Core/Src/tests/main.cyclo ./Core/Src/tests/main.d ./Core/Src/tests/main.o ./Core/Src/tests/main.su ./Core/Src/tests/reader.cyclo ./Core/Src/tests/reader.d ./Core/Src/tests/reader.o ./Core/Src/tests/reader.su ./Core/Src/tests/sqr_wave.cyclo ./Core/Src/tests/sqr_wave.d ./Core/Src/tests/sqr_wave.o ./Core/Src/tests/sqr_wave.su ./Core/Src/tests/structs.cyclo ./Core/Src/tests/structs.d ./Core/Src/tests/structs.o ./Core/Src/tests/structs.su

.PHONY: clean-Core-2f-Src-2f-tests

