#ifndef __NUCLEO476_LED_H
#define __NUCLEO476_LED_H

#include "stm32l476xx.h"

void LED_Init(uint8_t);

void LED_Off(uint8_t);
void LED_On(uint8_t);
void LED_Toggle(uint8_t);

#endif /* __NUCLEO476_LED_H */
