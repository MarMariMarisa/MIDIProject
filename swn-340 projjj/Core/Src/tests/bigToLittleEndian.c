/*
 * bigToLittleEndian.c
 *
 *  Created on: Nov 27, 2023
 *      Author: Marisa
 */


#include "stdint.h"



uint16_t convert_to_uint16 (uint8_t* p_value){
    return (p_value[0] << 24) + (p_value[1] << 16) + (p_value[2] << 8) + p_value[3];
}
uint32_t convert_to_uint32 (uint8_t* p_value){
	uint32_t to_return = 0;
	uint8_t* p_byte = (uint8_t*)&to_return;
	*p_byte++ = *p_value++;
	*p_byte++ = *p_value++;
	*p_byte++ = *p_value++;
	*p_byte = *p_value;
	return to_return;
}
