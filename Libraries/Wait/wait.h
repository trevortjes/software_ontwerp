/*
 * wait.h
 *
 *  Created on: May 17, 2018
 *      Author: matboy1200
 */

#ifndef WAIT_H_
#define WAIT_H_
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void waitInit();
uint8_t wait(uint16_t ms); //maximaal een minuut wait

void DELAY_init(void);







#endif /* WAIT_H_ */
