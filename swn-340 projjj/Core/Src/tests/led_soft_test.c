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
	while(1){
		if(GPIOA->IDR & (1 << 9)){
			LED_On(EXTERN_LED);
		}else{
			LED_Off(EXTERN_LED);
		}
}
}
