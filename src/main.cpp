/*
 ******************************************************************************
 File:     main.cpp
 Info:     Generated by Atollic TrueSTUDIO(R) 9.0.0   2018-05-03

 The MIT License (MIT)
 Copyright (c) 2018 STMicroelectronics

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

 ******************************************************************************
 */

/* Includes */
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "stm32_ub_vga_screen.h"
#include "text.h"
#include "shapes.h"
#include "pixelBuffer.h"
#include "commandBuffer.h"
#include "wait.h"
#include "clearScreen.h"
#include "bmp.h"

/**
 **===========================================================================
 **
 **  Abstract: main program
 **
 **===========================================================================
 */
int main(void) {
	UB_VGA_Screen_Init();
	CommandBuffer cmdBuf;

	PixelBuffer pBuf;
	setShapesPixelBuffer(&pBuf);
	setTextPixelBuffer(&pBuf);
	setBMPPixelBuffer(&pBuf);
	UB_VGA_FillScreen(40);
	//wait(1000);

	drawRect(20, 80, 60, 40, 200, 1);
	drawLine(20, 80, 60, 40, 120);
	drawLine(20, 40, 60, 80, 120);

	drawLine(0, 0, 319, 0, 120);
	drawLine(0, 0, 0, 239, 120);
	drawLine(319, 0, 319, 239, 120);
	drawLine(0, 239, 319, 239, 120);

	drawTri(40, 160, 20, 180, 60, 180, 200, 1);
	//drawEllipFill(100,100,59,40,200);

	int loop = 0;
	for(loop; loop<5; loop++)
	{
		drawEllip(50*loop+40, 120, 20, 20, 120, 1, 200);

	}

	int bitm = 0;
	for(bitm; bitm <5; bitm++)
	{
		writeBMPROM( bitm,  20+40*bitm,  200);
	}



	char s[]="the quick brown fox jumps over the lazy dog\n123456789()!@#$%^&*-=+";
	drawText(20,5,s,1);


	pBuf.push();
	//clearScherm(155);

	while (1) {
		cmdBuf.checkForCommands();

	}
}

/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
extern "C" void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer,
		uint32_t Size) {
	/* TODO, implement your code here */
	return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
extern "C" uint16_t EVAL_AUDIO_GetSampleCallBack(void) {
	/* TODO, implement your code here */
	return -1;
}
