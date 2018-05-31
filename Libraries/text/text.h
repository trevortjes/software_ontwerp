/**
 * *************************************************************************************
 *@file text.h
 *@brief Geeft de tekst weer op het scherm
 *@author Matthijs Uit den Bogaard
 *
 *Maakt tekst zichtbaar op het scherm door een van de drie fonts te tekenen op het scherm.
 */

#ifndef TEXT_TEXT_H_
#define TEXT_TEXT_H_

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "pixelBuffer.h"

/**
 * @brief De hoogte van de tekst in pixels
 */
#define TEXTHEIGHT 16

/**
@brief Zorgt ervoor dat een lokale variabele extern gebruikt kan worden
@param p Pointer naar object van het type PixelBuffer
@return Geeft een foutcode terug mits er een fout is
 */
uint8_t setTextPixelBuffer(PixelBuffer* p);

/**
 * @brief tekent de text op het scherm
 * @param x De x positie van de linkerkant van de tekst
 * @param y De y positie van de bovekant van de teks
 * @param text pointer naar het eerste character van de weer te geven string
 * @param col de kleur van de tekst
 * @param d geeft aan wat voor type tekst het is (0=normaal 1=bold 2=italic)
 *
 * Functie berekent de positie van de karakters en roept de functie drawChar aan om het karakter te tekenen.
 */
uint8_t drawText(uint16_t x, uint16_t y, char* text, uint8_t col,uint8_t d);





#endif /* TEXT_TEXT_H_ */
