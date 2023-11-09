################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/tests/clock.c \
../Core/Src/tests/echo.c \
../Core/Src/tests/led_soft_test.c \
../Core/Src/tests/main.c \
../Core/Src/tests/reader.c \
../Core/Src/tests/systick.c 

OBJS += \
./Core/Src/tests/clock.o \
./Core/Src/tests/echo.o \
./Core/Src/tests/led_soft_test.o \
./Core/Src/tests/main.o \
./Core/Src/tests/reader.o \
./Core/Src/tests/systick.o 

C_DEPS += \
./Core/Src/tests/clock.d \
./Core/Src/tests/echo.d \
./Core/Src/tests/led_soft_test.d \
./Core/Src/tests/main.d \
./Core/Src/tests/reader.d \
./Core/Src/tests/systick.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/tests/%.o Core/Src/tests/%.su Core/Src/tests/%.cyclo: ../Core/Src/tests/%.c Core/Src/tests/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-tests

clean-Core-2f-Src-2f-tests:
	-$(RM) ./Core/Src/tests/clock.cyclo ./Core/Src/tests/clock.d ./Core/Src/tests/clock.o ./Core/Src/tests/clock.su ./Core/Src/tests/echo.cyclo ./Core/Src/tests/echo.d ./Core/Src/tests/echo.o ./Core/Src/tests/echo.su ./Core/Src/tests/led_soft_test.cyclo ./Core/Src/tests/led_soft_test.d ./Core/Src/tests/led_soft_test.o ./Core/Src/tests/led_soft_test.su ./Core/Src/tests/main.cyclo ./Core/Src/tests/main.d ./Core/Src/tests/main.o ./Core/Src/tests/main.su ./Core/Src/tests/reader.cyclo ./Core/Src/tests/reader.d ./Core/Src/tests/reader.o ./Core/Src/tests/reader.su ./Core/Src/tests/systick.cyclo ./Core/Src/tests/systick.d ./Core/Src/tests/systick.o ./Core/Src/tests/systick.su

.PHONY: clean-Core-2f-Src-2f-tests

