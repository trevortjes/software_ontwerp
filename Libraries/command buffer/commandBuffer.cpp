/*
 * commandBuffer.cpp
 *
 *  Created on: 16 mei 2018
 *      Author: trevo
 */

#include "commandBuffer.h"
#include "uart.h"

char *stringBuf="hoi";
char* commands[20];

void CommandBuffer::initRs232()
{
//if rs232 not initialized then initialize
	if(initit != 1)
	{
		UART_init();
	}
}

CommandBuffer::CommandBuffer()
{
	// TODO Auto-generated constructor stub
	initRs232();
}

CommandBuffer::CommandBuffer(char *s)
{
	initRs232();
}

CommandBuffer::~CommandBuffer()
{
	// TODO Auto-generated destructor stub
}

char* CommandBuffer::readRs232()
{
	UART_gets(stringBuf, 0);
	return stringBuf;
}

void CommandBuffer::writeRs232(char* text)
{
	UART_puts(text);
}

void CommandBuffer::Echo()
{
	UART_gets(stringBuf, 1);
	UART_puts(readRs232());
}

uint8_t CommandBuffer::executeBuffer()
{
	return 0;
}
