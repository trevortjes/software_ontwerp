/**
 ******************************************************************************
 *@file bmp.h
 *@brief Bevat de functies voor het tekenen van bitmaps
 *@author Trevor van Ginkel
 *@author Matthijs Uit den Boogaard
 ******************************************************************************
 */

#include "bmp.h"
#include "bitmaps.h"
#define WIDTH 32		//Breedte van een bitmap
#define HEIGHT 32		//Hoogte van een bitmap

PixelBuffer* ppBufBMP;


uint8_t setBMPPixelBuffer(PixelBuffer* pb)
{
	ppBufBMP = pb;
	return 0;
}

uint8_t writeBMPROM(uint8_t nr, uint16_t x3, uint16_t y3)
{
	uint16_t i = 0;	//pixel teller op 0
	uint8_t x, y;   //Het x- en y-coordinaat

	for (y = y3; y < HEIGHT + y3; y++) //Loop alle verticale regels af
	{
		for (x = x3; x < WIDTH + x3; x++) //Loop per regel de horizontale pixels af
		{
			if (bitmaps[nr][i] != 0xFF)	//Voor transparantie wordt er niet gekeken naar de kleur 0xFF
			{
				ppBufBMP->add(bitmaps[nr][i], x, y);//Zet het x- en y-coordinaat van de desbetreffende bitmap in de pixelbuffer
			}
			i++; //Ophogeven van de teller naar de volgende pixel
		}
	}
	return 0;
}
