/**
 ******************************************************************************
 *@file bmp.h
 *@brief Bevat de functies voor het tekenen van bitmaps
 *@author Trevor van Ginkel
 *@author Matthijs Uit den Boogaard
 ******************************************************************************
 */

#ifndef BMP_BMP_H_
#define BMP_BMP_H_

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "pixelBuffer.h"

/**
 @brief Zorgt ervoor dat een lokale variabele extern gebruikt kan worden
 @param p Pointer naar object van het type PixelBuffer
 @return Geeft een foutcode terug mits er een fout is
 */
uint8_t setBMPPixelBuffer(PixelBuffer* p);

/**
 @brief Tekent een bitmap afbeelding
 @param nr De index van de bitmap afbeelding
 @param x3 Het x-coordinaat waar de bitmap afbeelding getekend moet worden
 @param y3 Het y-coordinaat waar de bitmap afbeelding getekend moet worden
 @return functie geeft een foutcode terug mits er een fout is
 */
uint8_t writeBMPROM(uint8_t nr, uint16_t x3, uint16_t y3);

#endif /* BMP_BMP_H_ */
