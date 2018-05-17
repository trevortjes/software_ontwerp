#include "wait.h"
#include "stm32f4xx_tim.h"


void waitInit()
{
		/*
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
		TIM_TimeBaseInitTypeDef TIM;
		//TIM.TIM_Prescaler = 4000;

		TIM.TIM_Prescaler = 279;//nieuw
		TIM.TIM_Period = 299;//nieuw

		//TIM.TIM_ClockDivision = TIM_CKD_DIV4;
		TIM.TIM_ClockDivision = TIM_CKD_DIV1;
		//TIM.TIM_CounterMode=TIM_CounterMode_Down;
		TIM.TIM_CounterMode=TIM_CounterMode_Up;//nieuw
		//TIM.TIM_Period=ms;
		TIM.TIM_RepetitionCounter = 0;
		TIM_TimeBaseInit(TIM3, &TIM);
		TIM_Cmd(TIM3, ENABLE);
		*/

	TIM_TimeBaseInitTypeDef SetupTimer;
	/* Enable timer 2, using the Reset and Clock Control register */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	// Get the clock frequencies
	RCC_ClocksTypeDef RCC_Clocks;
	RCC_GetClocksFreq(&RCC_Clocks);

	SetupTimer.TIM_Prescaler = 279; // Prescale to 1Mhz
	SetupTimer.TIM_CounterMode = TIM_CounterMode_Up;
	SetupTimer.TIM_Period = 299; // 60 microsecond period
	SetupTimer.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM4, &SetupTimer);
	TIM_Cmd(TIM4, ENABLE); // start counting by enabling CEN in CR1 */
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE); // enable so we can track each period
}

uint8_t wait(uint16_t ms){
uint16_t count = 0;
	while(count<ms)
	{
	 if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
	  {
	  	TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	  	count += 1;
	  }
	}
	/*
	int i=0;
	while (TIM_GetCounter(TIM3)<ms){
		i++;
	}
	//TIM_Cmd(TIM3, DISABLE);
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, DISABLE);
	 */
	return 0;
}
