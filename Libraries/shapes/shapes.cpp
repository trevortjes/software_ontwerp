/*
 * shapes.c
 *
 *  Created on: May 1, 2018
 *      Author: Matthijs Uit den Bogaard
 */
#include "shapes.h"
#include "pixelBuffer.h"
//GODVERDIKKIE, HET WERKT NIET? ALLEMAAL FOUTJES!h
PixelBuffer* ppBuf;

uint8_t setPixelBuffer(Pixel Buffer* pb){
	ppBuf=pb;
	return 0;
}

uint8_t drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t col=250){
	int dx = x2 - x1;
	int dy = y2 - y1;
	if (dx > dy) {
		int y;
		for (int x = x1; x <= x2; x++) {
			y = y1 + dy * (x - x1) / dx;
			ppBuf->add(col, x, y);
		}
	} else {
		int x;
		for (int y = y1; y <= y2; y++) {
			x = x1 + dx * (y - y1) / dy;
			ppBuf->add(col,x, y);
		}
	}
	return 0;
}

uint8_t fill(uint8_t shape, uint16_t x1=0, uint16_t y1=0, uint16_t x2=0, uint16_t y2=0, uint16_t x3=0, uint16_t y3=0, uint8_t col=250){

	return 0;
}

uint8_t drawRect(uint16_t x3, uint16_t y3, uint16_t x2, uint16_t y2, uint8_t col, uint16_t fill){
	if(drawLine(x3,y3,x2,y3,col)){
		return 1;
	}
	if(drawLine(x3,y3,x3,y2,col)){
		return 1;
	}
	if(drawLine(x2,y2,x2,y3,col)){
		return 1;
	}
	if(drawLine(x2,y2,x3,y2,col)){
		return 1;
	}
	if(fill){
		//fill hier
	}
	return 0;
}

uint8_t drawTri(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint8_t col, uint8_t fill){
	if(drawLine(x1,y1,x2,y2,col)){
		return 1;
	}
	if(drawLine(x1,y1,x3,y3,col)){
		return 1;
	}
	if(drawLine(x3,y3,x2,y2,col)){
		return 1;
	}
	if(fill){
			//fill hier
	}
	return 0;
}

