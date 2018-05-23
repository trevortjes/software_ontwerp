#include "wait.h"
#include "stm32f4xx_tim.h"


uint32_t G_CLK;
uint32_t D_mS; // Global variable (ms)


void waitInit()
{
		RCC_ClocksTypeDef Clocks;
		RCC_GetClocksFreq(&Clocks);
		G_CLK = Clocks.SYSCLK_Frequency;	// Read the systemclock
		D_mS = (G_CLK*1.25)/9000/2; // Number of instructions in one millisecond
}

uint8_t wait(uint16_t ms){
 volatile unsigned int i;

    while(ms>0)		// Run x times 1 millisecond
    {
        for(i=0;i<D_mS;i++);
        ms--;
    }
	return 0;
}
