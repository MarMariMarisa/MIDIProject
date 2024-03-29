// main.c with demoinit_systick()
// Updated and refactored Larry Kiser copyright 2021


// include project specific header files
#include "SysClock.h"
#include "LED.h"
#include "UART.h"
#include "printf.h"
#include "systick.h"
#include "project.h"
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "clock.h"
#include "GPIO.h"
#include "interruptHandlers.h"
#include "stm32l4xx_hal.h"
#include "timer.h"
#include "sqr_wave.h"
#include "hw8.h"

int EXTERN_LED = 6;

int main(void){
	// initialization code
	System_Clock_Init(); // set System Clock = 80 MHz
	UART2_Init ();
	LED_Init(EXTERN_LED);
	init_syst();
	GPIO_Init();
//
//	run_wave(2000);
	mode_print();
	init_player();

}

