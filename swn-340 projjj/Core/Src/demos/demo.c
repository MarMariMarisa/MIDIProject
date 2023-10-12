/*
 * demo.c
 *
 *  Created on: Feb 14, 2021
 *      Author: larry kiser
 *  Updated on: Sept 6, 2021
 *      Author: Mitesh Parikh
 */

#include <stdio.h>
#include <string.h>

// Custom Include files
#include "LED.h"
#include "UART.h"
#include "demo.h"
#include "stm32l4xx.h"
#include "systick.h"

#define LED_PIN 5



// This function is to print counter on UART port and toggle LED
static void demo_of_UART_print(int counter){
	int n ;
	uint8_t buffer[BUFFER_SIZE];

	n = sprintf((char *)buffer, "counter = %d\r\n", counter);
	USART_Write(USART2, buffer, n);

	init_systick();
	delay_systick();
	// Toggle LED
	LED_Toggle(LED_PIN);
}
void run_demo(){
	
	int counter = 0;
	
	// Run a loop to print counter value on UART port
	while (1)
	{
		//demo_of_printf_scanf();
		demo_of_UART_print(counter);
		counter++;
	}
}

