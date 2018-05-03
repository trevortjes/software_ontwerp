/*
 * pixelBuffer.h
 *
 *  Created on: May 1, 2018
 *      Author: Matthijs Uit den Bogaard
 */

#ifndef PROGRAMMA_LIBRARIES_PIXEL_BUFFER_PIXELBUFFER_H_
#define PROGRAMMA_LIBRARIES_PIXEL_BUFFER_PIXELBUFFER_H_
#include "stdint.h"


class PixelBuffer {
	private:
		uint_8 color[255]={};
		uint_16 position[255][2]={};
		uint_8 size=0;
		void clearBuffer();
	public:
		PixelBuffer();
		uint_8 add(uint_8 col, uint_16 x, uint_16 y);
		uint_8 push();

};



#endif /* PROGRAMMA_LIBRARIES_PIXEL_BUFFER_PIXELBUFFER_H_ */
