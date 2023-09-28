// main.c with demo
// Updated and refactored Larry Kiser copyright 2021


// include project specific header files
#include "SysClock.h"
#include "LED.h"
#include "UART.h"
#include "demo.h"

#include "printf.h"
#include "hello_world.h"
#include "project.h"
#include "reader.h"
	
int main(void){

	// initialization code
	System_Clock_Init(); // set System Clock = 80 MHz
	LED_Init(5);
	UART2_Init();
	

	// plication run function
	//print_f_sample();
	//run_demo()
	while(1==1){
		run();
	}

}

