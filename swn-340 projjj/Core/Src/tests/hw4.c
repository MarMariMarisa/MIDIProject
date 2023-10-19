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
	init_systick();
	while(1){
		char ch = USART_Read_Nonblocking(USART2);
		if(ch != 0){
			printf("%c",ch);
		}
		delay_systick();
		// Toggle LED
		LED_Toggle(5);
	}
}
