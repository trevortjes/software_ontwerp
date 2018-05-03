/*
 * shapes.c
 *
 *  Created on: May 1, 2018
 *      Author: Matthijs Uit den Bogaard
 */
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

uint_8 setPixelBuffer(PixelBuffer* pb);
uint_8 drawLine(uint_16 x1, uint_16 y1, uint_16 x2, unint_16 y2, uint_8 col);
uint_8 fill(uint_8 shape, uint_16 x1, uint_16 y1, uint_16 x2, uint_16 y2, uint_16 x3, uint_16 y3, uint_8 col);
uint_8 drawRect(uint_16 x3, uint_16 y3, unint_16x2, uint_16 y2, uint_8 col, uint_8 fill);
uint_8 drawTri(uint_16 x1, uint_16 y1, uint_16 x2, uint_16 y2, uint_16 x3, uint_16 y3, uint_8 col, uint_8 fill);
uint_8 drawEllip(uint_16 x, uint_16 y, uint_16 xrad, uint_16 yrad, uint_8 col, uint_8 fill);
