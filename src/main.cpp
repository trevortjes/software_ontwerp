/**
 ******************************************************************************
 *@file main.cpp
 *@brief Main file die de workflow van het programma laat zien.
 *@author Trevor van Ginkel
 *@author Matthijs Uit den Boogaard
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
 * @brief In deze functie wordt alles geinitialiseerd.
 *
 *  Main is verantwoordelijk voor het initialiseren van de VGA verbinding en
 * timer voor de wacht functie. Hierbij worden ook de objecten gemaakt voor de commandbuffer
 * en pixelbuffer. Als startscherm wordt het scherm wit gemaakt en de tekst "wachten op input!"
 * getoond. Hierna worden de pixels die dat opmaken naar het scherm gepusht. In de while loop
 * wordt er gewacht op input van de UART.
 */
int main(void) {
	UB_VGA_Screen_Init();
	waitInit();
	CommandBuffer cmdBuf;
	PixelBuffer pBuf;
	setShapesPixelBuffer(&pBuf);
	setTextPixelBuffer(&pBuf);
	setBMPPixelBuffer(&pBuf);
	clearScherm(0xFF);
	drawText(1, 1, "Wachten op input!", 0, 0);
	pBuf.push();
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
