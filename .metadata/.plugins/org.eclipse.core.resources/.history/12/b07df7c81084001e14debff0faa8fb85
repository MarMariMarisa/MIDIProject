/*
 * echo.c
 *
 *  Created on: Nov 9, 2023
 *      Author: Marisa
 */

#include "UART.h"
#include "printf.h"
void USART2_IRQHandler(void){
	uint8_t ch = USART_Read(USART2);
	printf("%c",ch);
}
