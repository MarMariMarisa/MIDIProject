/*
 * sqr_wave.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Marisa
 */


//print 1 when the wave is high and 0 when the wave is low
//run for a 1 second frequency wave
//verify it works in your terminal


//frequency is in Hertz
#include "printf.h"
#include "systick.h"
#include "tone.h"
#include "stdio.h"
int count = 0;
void SysTick_Handler(){
	count++;
}

void run_wave(int frequency){
	uint32_t duration = hertz_to_duration(frequency);
	while(0 == 0){
		if(count%duration  < (duration >>1)){
			printf("%d",1);
		}else{
			printf("%d",0);
		}

	}
}