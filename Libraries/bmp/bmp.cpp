/*
 * bmp.cpp
 *
 *  Created on: 19 mei 2018
 *      Author: trevo
 */
#include "bmp.h"
#include "bitmaps.h"


PixelBuffer* ppBufBMP;

uint8_t setBMPPixelBuffer(PixelBuffer* pb)
{
	ppBufBMP = pb;
	return 0;
}

uint8_t writeBMPROM(uint8_t nr, uint16_t x3, uint16_t y3)
{
uint16_t i = 0;
uint8_t x, y;

	for(y=y3; y<32 + y3; y++)//y regel met offset y3
	{
		for(x=x3; x<32 + x3; x++) //x regel met offset x3
		{
			if (bitmaps[nr][i] != 0xFF)
			{
				ppBufBMP->add(bitmaps[nr][i],x,y);
			}

			i++;
		}
	}

return 0 ;
}


