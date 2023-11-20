/*
 * interruptHandlers.c
 *
 *  Created on: Nov 15, 2023
 *      Author: Marisa
 */

#include "project.h"
#include "UART.h"
#include "printf.h"
#include "stm32l4xx.h"
#include "stdint.h"
#include "systick.h"
#include "timer.h"
#include "led.h"
#include "main.h"
#include "GPIO.h"

// Global variables
uint32_t buttonPressCount = 0;
uint32_t ticks = 0;
uint32_t lastButtonPressTime;

// Interrupt handler for USART2
void USART2_IRQHandler(void){
    uint8_t ch = USART_Read(USART2);
    BUFFER[0] = ch;
    printf("%c",ch);
}

// SysTick interrupt handler
void SysTick_Handler(void) {
    ticks++;  // Increment the counter on each SysTick interrupt
}

// EXTI15_10 interrupt handler
void EXTI15_10_IRQHandler(void){
    // Toggle the isRemote variable and reset lightState
    isRemote = !isRemote;
    lightState = 0;
    LED_Off(EXTERN_LED);
    mode_print();

    // Handle EXTI interrupt for GPIO_PIN_13
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
}

// EXTI9_5 interrupt handler
void EXTI9_5_IRQHandler(void) {
    // Initialize SysTick timer
    init_systick();

    // Increment buttonPressCount
    buttonPressCount++;

    // Record the start time of the button press
    uint32_t startTime = ticks;

    // Calculate time since the last button press
    uint32_t timeSinceLastPress = startTime - lastButtonPressTime;

    // Update buttonPressCount based on time since last press
    if (timeSinceLastPress <= 1000) {
        buttonPressCount++;
    } else {
        buttonPressCount = 1;
    }

    // Update the last button press time
    lastButtonPressTime = startTime;

    // Wait for the button to be released
    while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9) == GPIO_PIN_SET) {
    }

    // Calculate elapsed time since the button press started
    uint32_t elapsed = ticks - startTime;

    // Delay for a short period
    for(int i = 0; i < 1000; i++) {
        delay_systick();
    }

    // Handle different cases based on isRemote and elapsed time
    if (isRemote == 0) {
        if (elapsed > 1000) {
            stop_song();
        } else {
            if (PLAY_PAUSE_TOG == 0) {
                play_song();
            } else {
                lightState = 2;
            }
        }
    }

    // Handle EXTI interrupt for S1_Pin
    HAL_GPIO_EXTI_IRQHandler(S1_Pin);
}
