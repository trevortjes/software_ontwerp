/*
 * clearScreen.cpp
 *
 *  Created on: 17 mei 2018
 *      Author: trevo
 */
#include "clearScreen.h"
#include "stm32_ub_vga_screen.h"

uint8_t clearScherm(uint8_t color)
{
	UB_VGA_FillScreen(color);
	return 0;
}
