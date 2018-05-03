/*
 * pixelBuffer.cpp
 *
 *  Created on: May 1, 2018
 *      Author: Matthijs Uit den Bogaard
 */

#include "pixelBuffer.h"



PixelBuffer::PixelBuffer() {
	// TODO Auto-generated constructor stub

}


PixelBuffer::uint_8 add(uint_8 col, uint_16 x, uint_16 y){
	color[size]=col;
	position[size][0]=x;
	position[size][1]=y;
	if(size++==255){
		push();
	}

}

PixelBuffer::uint_8 push(){
	for(uint_8 i; i<size; i++){
		UB_VGA_SetPixel(position[i][0], position[i][1], color[i]);
	}
	size=0;
}
