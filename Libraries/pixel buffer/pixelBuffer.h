/*
 * pixelBuffer.h
 *
 *  Created on: May 1, 2018
 *      Author: Matthijs Uit den Bogaard
 */
#ifndef PIXELBUFFER_H
#define PIXELBUFFER_H

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"





class PixelBuffer {
	private:
		uint8_t color[256];
		uint16_t position[256][2];
		uint16_t size;
		void clearBuffer();
	public:
		PixelBuffer();
		uint8_t add(uint8_t col, uint16_t x, uint16_t y);
		uint8_t push();

};



#endif //PIXELBUFFER_H
