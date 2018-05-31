/**
 ******************************************************************************
 *@file wait.cpp
 *@brief Bevat de wacht functionaliteit
 *@author Trevor van Ginkel
 *@author Matthijs Uit den Boogaard
 ******************************************************************************
 */

#include "wait.h"
#include "stm32f4xx_tim.h"

uint32_t G_CLK;
uint32_t D_mS; // Global variable (ms)

/**
 *@brief Initialiseerd wacht
 */
void waitInit() {
	RCC_ClocksTypeDef Clocks;
	RCC_GetClocksFreq(&Clocks);
	G_CLK = Clocks.SYSCLK_Frequency;	// Lees de systeemklok
	D_mS = (G_CLK * 1.25) / 9000 / 2; // Aantal instructies in één milliseconde
}

/**
 *@brief Bevat de wacht functionaliteit
 *@param ms Het aantal milliseconde dat er gewacht moet worden
 *@return foutcode mits er iets fout gaat
 */
uint8_t wait(uint16_t ms) {
	volatile unsigned int i;

	while (ms > 0)		// Herhaal ms aantal keer
	{
		for (i = 0; i < D_mS; i++)
			;
		ms--;
	}
	return 0;
}
