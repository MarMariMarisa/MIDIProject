/*
 * clock.c
 *
 *  Created on: Nov 7, 2023
 *      Author: Marisa
 */

#include "printf.h"
#include "systick.h"
#include "clock.h"
int count = 0;

void SysTic_Handler(){
	count++;
}
//configure systick to use interupts
//count to one second
//updates seconds
//prints seconds

void clock(){
	init_systick();
	int seconds = 0;
	printf("\r\n%s","I AM HERER");
	while(1){

		printf("\r\n%s","I AM");
		if(count == 10){
			seconds++;
			int hours = seconds /3600;
			int minutes = seconds / 60 % 60;
			printf("\r\n%s","I AM HERER");
			printf("%02d:%02d:%02d\r",hours,minutes,seconds%60);
			count = 0;
		}
		SysTic_Handler();
	}
}
