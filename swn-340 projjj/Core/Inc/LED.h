/*
 * LED.h
 *
 *  Created on: Sep 28, 2023
 *      Author: Marisa
 */

#ifndef __NUCLEO476_LED_H
#define __NUCLEO476_LED_H

#include "stm32l476xx.h"
void LED_Off(uint8_t pin);
void LED_Init(uint8_t pin);
void LED_On(uint8_t pin);
void LED_Toggle(uint8_t pin);

#endif /* CORE_INC_LED_H_ */
