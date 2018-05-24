/*
 * text.cpp
 *
 *  Created on: May 13, 2018
 *      Author: matboy1200
 */
#include "text.h"
#include "Ariel.hpp"
#include "ArielI.hpp"
#include "ArielB.hpp"
#include "collors.h"

PixelBuffer* ppBuft;




uint8_t setTextPixelBuffer(PixelBuffer* pb) {
	ppBuft = pb;
	return 0;
}

uint8_t drawChar(uint16_t x, uint16_t y, char c, uint16_t *xd,uint8_t col,uint8_t d){
	int width;
	int start;
	const uint8_t *fontp;
	if(d==0){
		width = FONT_SIZE[c-32][0];
		start = FONT_SIZE[c-32][1];
		fontp=FONT+start;
	}else if(d==1){
		width = FONT_SIZE_B[c-32][0];
		start = FONT_SIZE_B[c-32][1];
		fontp=FONT_B+start;
	}else{
		width = FONT_SIZE_I[c-32][0];
		start = FONT_SIZE_I[c-32][1];
		fontp=FONT_I+start;
	}

	for(uint8_t row=0;row<16; row++){
		uint8_t font;
		if(width>8){
			font=*(fontp+row*2);
		}else{
			font=*(fontp+row);
		}


		for(uint8_t pix=0;pix<=width;pix++){
			if(pix>8){
				if(*(fontp+row*2-1) & (1<<(8-(pix-8)))){
					ppBuft->add(col, x+pix, y+row);
				}
			}
			if(font& (1<<(8-pix))){
				ppBuft->add(col, x+pix, y+row);
			}
		}
	}
	*xd+=(width+1);
	return 0;
}


uint8_t drawText(uint16_t x, uint16_t y, char* text,uint8_t col=0,uint8_t d=0){
	int i=0;
	uint16_t  xd=x;
	uint16_t yd=y;
	while(*(text+i)!='\0'){
		if(*(text+i)>=32){
			drawChar(xd, yd, *(text+i), &xd, col,d);
		}else if(*(text+i)=='\n'){
			xd=x;
			yd=yd+TEXTHEIGHT+1;
		}
		i++;
	}
	return 0;
}


