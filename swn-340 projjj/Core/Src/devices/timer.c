#include "systick.h"
#include "printf.h"
#include "stm32l476xx.h"
#include "stdint.h"

struct systick {
    uint32_t CSR;
    uint32_t RVR;
    uint32_t CVR;
    uint32_t CALIB;
};
void init_syst (){
    // Create an instance of systick
    // Set timer to 10 ms
    SYST_TICK->RVR = 799999; //1 ms timer
    // Turn on timer -
    SYST_TICK->CSR |= (1<<2); // Use pc source
    SYST_TICK->CSR |= (1<<0); // Enable
}

uint32_t millis() {
    // Return the elapsed time in milliseconds
    return SysTick->VAL / (SystemCoreClock / 1000);
}
//
//void clock() {
//    init_syst ();
//    // Display num seconds since started, once a second
//    int count = 0;
//    int seconds = 0;
//    while (1){
//        if ((SYST_TICK->CSR >> 16) == 1) {
//            count++;
//            if (count == 10){
//                seconds++;
//                count = 0;
//                printf ("%d\n", seconds);
//            }
//        }
//    }
//}