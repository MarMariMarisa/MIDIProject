/*
 * led_soft_test.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Marisa
 */
#include "LED.h"
#include "UART.h"
#include "led_soft_test.h"
#include "stm32l4xx.h"
#include "main.h"
#include "GPIO.h"


void software_led(){
	GPIO_Init();
	LED_On(PIN_NUMBER);
	while(1){
//		if(HAL_GPIO_ReadPin(GPIO_PIN_9) == 1){
//			LED_Toggle(6);

	}
}
