// main.c with demoinit_systick()
// Updated and refactored Larry Kiser copyright 2021


// include project specific header files
#include "SysClock.h"
#include "LED.h"
#include "UART.h"

#include "printf.h"
#include "systick.h"
#include "project.h"
#include "LED.h"
#include "systick.h"
#include "UART.h"
#include "string.h"
#include "stdio.h"
#include "reader.h"
#include "song.h"
#include "stdlib.h"
#include "math.h"
#include "ctype.h"
#include "led_soft_test.h"

#define PIN_NUMBER 6
int main(void){

	// initialization code
	System_Clock_Init(); // set System Clock = 80 MHz
	UART2_Init();
	LED_Init(PIN_NUMBER);

	software_led();

//	init_player();

}

