/*
 * systick.h
 *
 *  Created on: Jan 8, 2023
 *      Author: marisa
 */

#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_

#include "stm32l476xx.h"
#include "stdint.h"
#include "systick.h"

//create struct to hold the systic registers

struct SYST{
	uint32_t CSR;
	uint32_t RVR;
	uint32_t CVR;
	uint32_t CALIB;
};
struct SYST* SYST_TICK = (struct SYST*) 0xE000E010;
// This function is to Initialize SysTick registers
struct SYST* init_systick(){
		//clear csr register
		SYST_TICK->CSR &= ~(1 << 0);;
	    // Set timer to 10 ms
	    SYST_TICK->RVR = 799;
	    //Set to internal clock
	    SYST_TICK->CSR |= (1<<2); // Use pc source
	    //Enable timer
	    SYST_TICK->CSR |= (1<<0); // Enable
	    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
	    return SYST_TICK;
}

// This function is to create delay using SysTick timer counter
void delay_systick(){
		int x = 0;
		while(x == 0){
			if ((SYST_TICK->CSR >> 16) == 1) {
		         x = 1;
			}
		}
}


#endif /* INC_SYSTICK_H_ */
