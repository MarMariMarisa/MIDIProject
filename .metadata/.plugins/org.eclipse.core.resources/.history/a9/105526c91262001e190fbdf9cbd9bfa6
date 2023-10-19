/*
 * systick.h
 *
 *  Created on: Jan 8, 2023
 *      Author: bruce
 */

#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_

//create struct to hold the systic registers
struct registers{
	int SYST_CSR[32];
	int SYST_RVR[32];
	int SYSY_CVR[32];
	int SYST_CALIB[32];
};


// This function is to Initialize SysTick registers
static void init_systick()
{
	// Use the SysTick global structure pointer to do the following in this
	// exact order with separate lines for each step:
	//
	// Disable SysTick by clearing the CTRL (CSR) register.
	// Set the LOAD (RVR) to 8 million to give us a 100 milliseconds timer.
	// Set the clock source bit in the CTRL (CSR) to the internal clock.
	// Set the enable bit in the CTRL (CSR) to start the timer.
}

// This fuction is to create delay using SysTick timer counter
static void delay_systick()
{
	// Using the SysTick global structure pointer do the following:
	// Create a for loop that loops 10 times
	// Inside that for loop check the COUNTFLAG bit in the CTRL (CSR)
	// register in a loop. When that bit is set exit this inner loop
	// to do another pass in the outer loop of 10.
}

#endif /* INC_SYSTICK_H_ */
