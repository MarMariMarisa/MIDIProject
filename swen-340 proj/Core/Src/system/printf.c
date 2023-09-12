/*
 * Created On: September 12, 2023
 * 	Author: Marisa
 *
 */

#include "printf.h"
#include "UART.H"
#include <stdio.h>

void my_printf(char* string, int number){
	char buffer[128];
	int num = sprintf (buffer,"%s %d\r\n", string, string[1]);
	USART_Write (USART2,(unsigned char*) buffer,num);

}
