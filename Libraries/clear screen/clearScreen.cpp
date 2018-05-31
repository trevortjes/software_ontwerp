/**
 ******************************************************************************
 *@file clearScreen.cpp
 *@brief Bevat de functionaliteit om het scherm te wissen door
 *		 het scherm te vullen met ��n kleur
 *@author Trevor van Ginkel
 *@author Matthijs Uit den Boogaard
 ******************************************************************************
 */

#include "clearScreen.h"
#include "stm32_ub_vga_screen.h"

/**
 *@brief Vult het scherm met ��n kleur
 *@param color De kleur die het scherm moet krijgen
 *@return Foutcode mits er iets fout gaat
 */
uint8_t clearScherm(uint8_t color) {
	UB_VGA_FillScreen(color);		//Geeft de scherm een kleur
	return 0;
}
