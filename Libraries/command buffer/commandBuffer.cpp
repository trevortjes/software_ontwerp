/*
 * commandBuffer.cpp
 *
 *  Created on: 16 mei 2018
 *      Author: trevo
 */

#include "commandBuffer.h"
#include "uart.h"

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

char* CommandBuffer::readRs232()
{

}

void CommandBuffer::initRs232()
{
//if rs232 not initialized then initialize
}

void CommandBuffer::writeRs232(const char* text)
{

}
uint_8 CommandBuffer::executeBuffer()
{

}
