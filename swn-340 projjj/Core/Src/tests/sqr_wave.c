#include <stdint.h>
#include "printf.h"
#include "tone.h"
#include "systick.h"
#include "adc.h"
#include "dac.h"
#include "tone.h"
#include "stdio.h"

static int count = 0;

void SysTick_Handler () {
    count++;
}

void Error_Handler(){
//
}
uint32_t hertz_to_duration (float hertz) {
	uint32_t tick_speed = 1000000; // This is a hack, you'll fix it later
	if (hertz == 0)
		return 0;
	float duration = 1 / hertz;
	return (uint32_t) (duration * tick_speed);
}
//frequency is in hertz
void run_wave(int frequency){
	uint32_t duration = hertz_to_duration(frequency);
	init_systick();
	DAC_Init ();
	DAC_Start ();

	while(1==1){
		if(count % duration < duration >> 1){
	        DAC_Set_Value (4000);
	        printf("1");
	   }
	   else {
	          DAC_Set_Value(0);
	          printf("0");
	   }
	}
}
