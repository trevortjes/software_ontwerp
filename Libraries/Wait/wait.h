/**
 ******************************************************************************
 *@file wait.h
 *@brief Bevat de wacht functionaliteit
 *@author Trevor van Ginkel
 *@author Matthijs Uit den Boogaard
 ******************************************************************************
 */

#ifndef WAIT_H_
#define WAIT_H_
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

/**
 *@brief Initialiseerd wacht
 */
void waitInit();

/**
 *@brief Bevat de wacht functionaliteit
 *@param ms Het aantal milliseconde dat er gewacht moet worden
 *@return foutcode mits er iets fout gaat
 */
uint8_t wait(uint16_t ms); //maximaal een minuut wait

#endif /* WAIT_H_ */
