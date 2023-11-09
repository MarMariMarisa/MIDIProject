/*
 * echo.c
 *
 *  Created on: Nov 9, 2023
 *      Author: Marisa
 */

#include "UART.h"
#include "printf.h"
void USART2_IRQHandler(void){
	NVIC_EnableIRQ(USART_ISR_RXNE);
	char ch = 0;
	if((USART2->ISR & USART_ISR_RXNE) == USART_ISR_RXNE  ){
		ch = (char)USART_Read_Nonblocking(USART2);
		if(ch != '\0'){
			printf("%c",ch);
		}
	}
}
