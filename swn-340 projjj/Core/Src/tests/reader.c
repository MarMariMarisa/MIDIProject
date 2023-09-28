/*
 * reader.c
 *
 *  Created on: Sep 26, 2023
 *      Author: Marisa
 */

#include "reader.h"
#include "UART.h"
#include "printf.h"
#include "LED.h"

static int num1 = -1;
static char BUFFER[128];
static int num2 = 5000000;

char* read_line(){
	//read one characterA
	//print that character on it's own line
	int index = 0;
	char ch = 0;
	while(ch != '\r'){
		ch = (char)USART_Read(USART2);
		BUFFER[index] = ch;
		index++;
	}
	BUFFER[index - 1] = 0;
	return BUFFER;

}
void run(){
	//read one characterA
	//print that character on it's own line
	char* line = read_line();
	printf("%s\n",line);
	printf("%d %d",num1,num2);

}


