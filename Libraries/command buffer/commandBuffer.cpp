/*
 * commandBuffer.cpp
 *
 *  Created on: 16 mei 2018
 *      Author: trevo
 */

#include "commandBuffer.h"
#include "uart.h"

char stringBuf[100];
char* command[];

CommandBuffer::CommandBuffer() {
	// TODO Auto-generated constructor stub
InitRs232();
}

CommandBuffer::CommandBuffer(char *s)
{
InitRs232();
}

CommandBuffer::~CommandBuffer() {
	// TODO Auto-generated destructor stub
}

void CommandBuffer::initRs232()
{
//if rs232 not initialized then initialize
	if(init != 1)
	{
		UART_init();
	}
}

char* CommandBuffer::readRs232()
{
	UART_gets(stringBuf, 0);

}

void CommandBuffer::writeRs232(const char* text)
{
	UART_puts(text);
}

uint_8 CommandBuffer::executeBuffer()
{

}
