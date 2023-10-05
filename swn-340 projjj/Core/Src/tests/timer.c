/*
 * timer.c
 *
 *  Created on: Oct 3, 2023
 *      Author: Marisa
 */

#include "systick.h"

void init_systick(){
	//Create a SYST and initalize it with an RVR of 100,000
	//turn it on
	SYST syst;
	syst->RVR = 99999;//(99999+1) / 8000000 sec timer
	syst->CSR = syst->CSR | (1 << 0); //set bit 0 to turn on

}
