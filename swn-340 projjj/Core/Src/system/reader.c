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
#include "project.h"
static char BUER[128];


char* read_line(){
	//read one characterA
	//print that character on it's own line
	int index = 0;
	char ch = 0;
	while(ch != '\r'){
		if(isRemote == 0){
			break;
		}
		ch = (char)USART_Read_Nonblocking(USART2);
		if(ch != '\0'){
			printf("%c",ch);
			BUER[index] = ch;
			index++;
		}
	}
	BUER[index - 1] = 0;
	return BUER;

}
void run(){
	//read one characterA
	//print that character on it's own line
	char* line = read_line();
	printf("%s\r\n",line);

}


