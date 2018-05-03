/*
 * pixelBuffer.h
 *
 *  Created on: May 1, 2018
 *      Author: Matthijs Uit den Bogaard
 */


#ifndef PROGRAMMA_LIBRARIES_PIXEL_BUFFER_PIXELBUFFER_H_
#define PROGRAMMA_LIBRARIES_PIXEL_BUFFER_PIXELBUFFER_H_



class PixelBuffer {
	private:
		uint8_t color[255]={};
		uint16_t position[255][2]={};
		uint8_t size=0;
		void clearBuffer();
	public:
		PixelBuffer();
		uint8_t add(uint8_t col, uint16_t x, uint16_t y);
		uint8_t push();

};



#endif /* PROGRAMMA_LIBRARIES_PIXEL_BUFFER_PIXELBUFFER_H_ */
