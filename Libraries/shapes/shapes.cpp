/*
 * shapes.c
 *
 *  Created on: May 1, 2018
 *      Author: Matthijs Uit den Bogaard
 */
#include "shapes.h"
//GODVERDIKKIE, HET WERKT NIET? ALLEMAAL FOUTJES!
pixelBuffer* ppBuf;

uint8_t setPixelBuffer(PixelBuffer* pb){
	ppBuf=pb;
}

uint8_t drawLine(uint_16 x1, uint_16 y1, uint_16 x2, unint_16 y2, uint8_t col=250){
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

uint8_t fill(uint8_t shape, uint_16 x1=0, uint_16 y1=0, uint_16 x2=0, uint_16 y2=0, uint_16 x3=0, uint_16 y3=0, uint8_t col=250){

	return 0;
}

uint8_t drawRect(uint_16 x3, uint_16 y3, unint_16x2, uint_16 y2, uint8_t col, uint8_t fill){
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

uint8_t drawTri(uint_16 x1, uint_16 y1, uint_16 x2, uint_16 y2, uint_16 x3, uint_16 y3, uint8_t col, uint8_t fill){
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

