/**
 * *************************************************************************************
 *@file pixelBuffer.h
 *@brief Buffer met aan te passen pixelwaarden
 *@author Matthijs Uit den Bogaard
 *
 *Klasse die de aan te passen pixels opslaat in een buffer en dan wanneer alle commands uitgevoerd zijn of het wait commando is aangeroepen de pixels naar het scherm pusht
 */
#ifndef PIXELBUFFER_H
#define PIXELBUFFER_H

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

class PixelBuffer {
private:
	/**
	 * @bief Array met de kleuren voor de pixels
	 */
	uint8_t color[256];
	/**
	 * @brief 2 demensionaal array met de coördinaten van de pixels
	 */
	uint16_t position[256][2];
	/**
	 * @brief de lengte van de buffer
	 */
	uint16_t size;
	void clearBuffer();
public:
	/**
	 * @brief default constructor van de pixelbuffer
	 */
	PixelBuffer();
	/**
	 * @brief functie add voegt een pixel toe aan de pixel buffer
	 * @param col De kleur van de pixel
	 * @param x De x positie van de pixel
	 * @param y de y positie van de pixel
	 * @return de errorcode als het goed gaat wordt 0 gereturnt
	 *
	 * De functie add voegt een pixel toe aan de pixelbuffer met de meegegeven kleur x en y positie.
	 */
	uint8_t add(uint8_t col, uint16_t x, uint16_t y);
	/**
	 * @brief functie push plaatst alle pixels uit de buffer op het scherm
	 * @return de errorcode als het goed gaat wordt 0 gereturnt
	 */
	uint8_t push();

};

#endif //PIXELBUFFER_H
