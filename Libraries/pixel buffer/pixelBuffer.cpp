/**
 * *************************************************************************************
 *@file pixelBuffer.cpp
 *@brief Buffer met aan te passen pixelwaarden
 *@author Matthijs Uit den Bogaard
 *
 *Klasse die de aan te passen pixels opslaat in een buffer en dan wanneer alle commands uitgevoerd zijn of het wait commando is aangeroepen de pixels naar het scherm pusht
 */

#include "pixelBuffer.h"
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "stm32_ub_vga_screen.h"



PixelBuffer::PixelBuffer() {
	size = 0;
}

uint8_t PixelBuffer::add(uint8_t col, uint16_t x, uint16_t y) {
	x--;
	y--;
	if(x>320||y>240){
		return 2; 			//controleerd of de pixel binnen de boundaries van het scherm ligt en returned errorcode 2 als hij niet in het scherm ligt
	}
	color[size] = col;		//plaatst de kleur in het color array
	position[size][0] = x;	//plaatst de x positie in het positie array
	position[size][1] = y;  //plaatst de x positie in het positie array
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
