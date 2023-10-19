/*
 * hw4.c
 *
 *  Created on: Oct 19, 2023
 *      Author: Marisa
 */


#include "UART.h"
#include "systick.h"
#include "printf.h"
#include"LED.h"

void run_hw4(){
	uint8_t ch = 0;
	while(1){
		ch = USART_Read_Nonblocking(USART2);
		USART_Write(USART2,&ch,1);
		init_systick();
		delay_systick();
		// Toggle LED
		LED_Toggle(5);
		ch = 0;
	}
}
