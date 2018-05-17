#include "wait.h"
#include "stm32f4xx_tim.h"


uint8_t wait(uint16_t ms){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	TIM_TimeBaseInitTypeDef TIM;
	TIM.TIM_Prescaler = 4000;
	TIM.TIM_CounterMode=TIM_CounterMode_Down;
	TIM.TIM_Period=ms;
	TIM.TIM_ClockDivision = TIM_CKD_DIV4;
	TIM.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM3, &TIM);
	TIM_Cmd(TIM3, ENABLE);
	int i=0;
	while (TIM_GetCounter(TIM3)>0){
		i++;
	}
	TIM_Cmd(TIM3, DISABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, DISABLE);
	return 0;
}
