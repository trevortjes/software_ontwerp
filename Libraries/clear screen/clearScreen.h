/**
 ******************************************************************************
 *@file clearScreen.h
 *@brief Bevat de functionaliteit om het scherm te wissen door
 *		 het scherm te vullen met een kleur
 *@author Trevor van Ginkel
 *@author Matthijs Uit den Boogaard
 ******************************************************************************
 */
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

#ifndef CLEAR_SCREEN_CLEARSCREEN_H_
#define CLEAR_SCREEN_CLEARSCREEN_H_

/**
 *@brief Vult het scherm met een kleur
 *@param color De kleur die het scherm moet worden
 *@return foutcode mits er iets fout gaat
 */
uint8_t clearScherm(uint8_t color);

#endif /* CLEAR_SCREEN_CLEARSCREEN_H_ */
