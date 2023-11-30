/*
 * hw8.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Marisa
 */

#include "stdio.h"
#include "stdint.h"
#include "printf.h"
#include "hw8.h"

uint32_t parseDelay(uint8_t* delay) {
    uint32_t result = 0;
    uint8_t currentByte;

    do {
        currentByte = *delay++;
        result = (result << 7) | (currentByte & 0x7F);
    } while (currentByte & 0x80);

    return result;
}

void runTest() {
    uint8_t delay1[] = {0x3B, 0x80, 0x27, 0x00};
    uint8_t delay2[] = {0x83, 0x18, 0x91, 0x54, 0x64};
    uint8_t delay3[] = {0xC5, 0x92, 0x74, 0xE3, 0x74, 0x12};
    uint8_t delay4[] = {0x90, 0x82, 0x93, 0x64, 0xD3, 0x89};

    printf("Delay 1: %lu\r\n", parseDelay(delay1)); // Should print 59
    printf("Delay 2: %lu\r\n", parseDelay(delay2)); // Should print 408
    printf("Delay 3: %lu\r\n", parseDelay(delay3)); // Should print 1132916
    printf("Delay 4: %lu\r\n", parseDelay(delay4)); // Should print 33589372

}
