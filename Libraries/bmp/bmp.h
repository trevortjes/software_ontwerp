/*
 * bmp.h
 *
 *  Created on: 19 mei 2018
 *      Author: trevo
 */

#ifndef BMP_BMP_H_
#define BMP_BMP_H_

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "pixelBuffer.h"

uint8_t setBMPPixelBuffer(PixelBuffer* p);
uint8_t writeBMPROM(uint8_t nr, uint16_t x3, uint16_t y3);
uint8_t writeBMPRs232(uint8_t *p, uint16_t width, uint16_t height, uint8_t nr, uint16_t x3, uint16_t y3);
uint8_t writeBMPRs232Anim(uint8_t *p, uint16_t pwidth, uint16_t width, uint16_t height, uint8_t nr, uint16_t x3, uint16_t y3);



#endif /* BMP_BMP_H_ */
