/*
 * text.h
 *
 *  Created on: May 13, 2018
 *      Author: matboy1200
 */

#ifndef TEXT_TEXT_H_
#define TEXT_TEXT_H_

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "pixelBuffer.h"

#define TEXTHEIGHT 12

uint8_t setTextPixelBuffer(PixelBuffer* p);
uint8_t drawText(uint16_t x, uint16_t y, char* text, uint8_t s);





#endif /* TEXT_TEXT_H_ */
