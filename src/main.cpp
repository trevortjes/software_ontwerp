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
	//init
	UB_VGA_Screen_Init();
	CommandBuffer cmdBuf;
	PixelBuffer pBuf;
	setShapesPixelBuffer(&pBuf);
	setTextPixelBuffer(&pBuf);
	setBMPPixelBuffer(&pBuf);

	//test code
	cmdBuf.addCommand("clearscherm,rood");
	//cmdBuf.addCommand("lijn,1,1,100,100,4,rood");
	//cmdBuf.addCommand("lijn,100,1,100,1,4,groen");
	//cmdBuf.addCommand("ellips,200,200,30,40,blauw");
	//cmdBuf.addCommand("ellips,300,300,40,30,lichtrood");
	cmdBuf.executeBuffer();

	while (1) {

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
