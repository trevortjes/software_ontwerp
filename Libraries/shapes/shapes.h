/*
 * shapes.c
 *
 *  Created on: May 1, 2018
 *      Author: Matthijs Uit den Bogaard
 */
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "pixelBuffer.h"

uint8_t setPixelBuffer(PixelBuffer* pb);
uint8_t drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t col);
uint8_t fill(uint8_t shape, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t col);
uint8_t drawRect(uint16_t x3, uint16_t y3, uint16_t x2, uint16_t y2, uint8_t col, uint16_t fill);
uint8_t drawTri(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t col, uint16_t fill);
uint8_t drawEllip(uint16_t x, uint16_t y, uint16_t xrad, uint16_t yrad, uint8_t col, uint16_t fill);
