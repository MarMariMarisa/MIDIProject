/*
 * clock.c
 *
 *  Created on: Nov 7, 2023
 *      Author: Marisa
 */

int count = 0;

void SysTick_Handler(){
	count++;
}
//configure systick to use interupts
//count to one second
//updates seconds
//prints seconds

void clock(){
	init_syst();
	int seconds = 0;
	while(count < 10){
		printf("%d\r\n",seconds);
		SysTick_Handler();
	}
}
