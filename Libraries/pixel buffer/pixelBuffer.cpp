/*
 * pixelBuffer.cpp
 *
 *  Created on: May 1, 2018
 *      Author: Matthijs Uit den Bogaard
 */

#include "pixelBuffer.h"
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"


PixelBuffer::PixelBuffer() {
	// TODO Auto-generated constructor stub

}


PixelBuffer::uint8_t add(uint8_t col, uint16_t x, uint16_t y){
	color[size]=col;
	position[size][0]=x;
	position[size][1]=y;
	if(size++==255){
		push();
	}

}

PixelBuffer::uint8_t push(){
	for(uint8_t i; i<size; i++){
		UB_VGA_SetPixel(position[i][0], position[i][1], color[i]);
	}
	size=0;
}
