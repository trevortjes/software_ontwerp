/*
 * pixelBuffer.cpp
 *
 *  Created on: May 1, 2018
 *      Author: Matthijs Uit den Bogaard
 */

#include "pixelBuffer.h"
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "stm32_ub_vga_screen.h"

PixelBuffer::PixelBuffer() {
	// TODO Auto-generated constructor stub
	size = 0;
}

uint8_t PixelBuffer::add(uint8_t col, uint16_t x, uint16_t y) {
	color[size] = col;
	position[size][0] = x;
	position[size][1] = y;
	if (size++ == 255) {
		if(this->push())
			return 1;
	}
	return 0;
}

uint8_t PixelBuffer::push() {
	for (uint16_t i=0; i < size; i++) {
		if(UB_VGA_SetPixel(position[i][0], position[i][1], color[i])){
		}else{
			return 1;
		}
	}
	size = 0;
	return 0;
}
