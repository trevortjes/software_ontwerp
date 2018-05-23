/*
 * shapes.c
 *
 *  Created on: May 1, 2018
 *      Author: Matthijs Uit den Bogaardt
 */
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "pixelBuffer.h"

uint8_t setShapesPixelBuffer(PixelBuffer* p);
uint8_t drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t col );
uint8_t drawRect(uint16_t x3, uint16_t y3, uint16_t x2, uint16_t y2, uint8_t col, uint16_t fill);
uint8_t drawTri(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint8_t col, uint16_t fill);
uint8_t drawEllip(uint16_t x, uint16_t y, uint16_t xrad, uint16_t yrad, uint8_t col, uint16_t fill, uint8_t fillCol);
uint8_t drawEllipFill(uint16_t x, uint16_t y, uint16_t xrad, uint16_t yrad, uint8_t col);

uint8_t pushBuffer();
