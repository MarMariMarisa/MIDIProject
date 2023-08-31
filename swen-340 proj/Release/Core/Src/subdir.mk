################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/GPIO.c \
../Core/Src/LED.c \
../Core/Src/SysClock.c \
../Core/Src/UART.c \
../Core/Src/adc.c \
../Core/Src/adc_dac_demo.c \
../Core/Src/dac.c \
../Core/Src/demo.c \
../Core/Src/main.c \
../Core/Src/project.c \
../Core/Src/song.c \
../Core/Src/stm32l4xx_hal_msp.c \
../Core/Src/stm32l4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32l4xx.c \
../Core/Src/tone.c 

OBJS += \
./Core/Src/GPIO.o \
./Core/Src/LED.o \
./Core/Src/SysClock.o \
./Core/Src/UART.o \
./Core/Src/adc.o \
./Core/Src/adc_dac_demo.o \
./Core/Src/dac.o \
./Core/Src/demo.o \
./Core/Src/main.o \
./Core/Src/project.o \
./Core/Src/song.o \
./Core/Src/stm32l4xx_hal_msp.o \
./Core/Src/stm32l4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32l4xx.o \
./Core/Src/tone.o 

C_DEPS += \
./Core/Src/GPIO.d \
./Core/Src/LED.d \
./Core/Src/SysClock.d \
./Core/Src/UART.d \
./Core/Src/adc.d \
./Core/Src/adc_dac_demo.d \
./Core/Src/dac.d \
./Core/Src/demo.d \
./Core/Src/main.d \
./Core/Src/project.d \
./Core/Src/song.d \
./Core/Src/stm32l4xx_hal_msp.d \
./Core/Src/stm32l4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32l4xx.d \
./Core/Src/tone.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/GPIO.cyclo ./Core/Src/GPIO.d ./Core/Src/GPIO.o ./Core/Src/GPIO.su ./Core/Src/LED.cyclo ./Core/Src/LED.d ./Core/Src/LED.o ./Core/Src/LED.su ./Core/Src/SysClock.cyclo ./Core/Src/SysClock.d ./Core/Src/SysClock.o ./Core/Src/SysClock.su ./Core/Src/UART.cyclo ./Core/Src/UART.d ./Core/Src/UART.o ./Core/Src/UART.su ./Core/Src/adc.cyclo ./Core/Src/adc.d ./Core/Src/adc.o ./Core/Src/adc.su ./Core/Src/adc_dac_demo.cyclo ./Core/Src/adc_dac_demo.d ./Core/Src/adc_dac_demo.o ./Core/Src/adc_dac_demo.su ./Core/Src/dac.cyclo ./Core/Src/dac.d ./Core/Src/dac.o ./Core/Src/dac.su ./Core/Src/demo.cyclo ./Core/Src/demo.d ./Core/Src/demo.o ./Core/Src/demo.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/project.cyclo ./Core/Src/project.d ./Core/Src/project.o ./Core/Src/project.su ./Core/Src/song.cyclo ./Core/Src/song.d ./Core/Src/song.o ./Core/Src/song.su ./Core/Src/stm32l4xx_hal_msp.cyclo ./Core/Src/stm32l4xx_hal_msp.d ./Core/Src/stm32l4xx_hal_msp.o ./Core/Src/stm32l4xx_hal_msp.su ./Core/Src/stm32l4xx_it.cyclo ./Core/Src/stm32l4xx_it.d ./Core/Src/stm32l4xx_it.o ./Core/Src/stm32l4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32l4xx.cyclo ./Core/Src/system_stm32l4xx.d ./Core/Src/system_stm32l4xx.o ./Core/Src/system_stm32l4xx.su ./Core/Src/tone.cyclo ./Core/Src/tone.d ./Core/Src/tone.o ./Core/Src/tone.su

.PHONY: clean-Core-2f-Src

