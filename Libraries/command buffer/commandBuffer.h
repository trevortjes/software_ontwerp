/*
 * commandBuffer.h
 *
 *  Created on: 16 mei 2018
 *      Author: Trevor van Ginkel
 */

#ifndef COMMAND_BUFFER_COMMANDBUFFER_H_
#define COMMAND_BUFFER_COMMANDBUFFER_H_

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "command.h"
class CommandBuffer {
private:
		Command *commands;
		void clearBuffer();

public:
	CommandBuffer();
	CommandBuffer(char *s);
	~CommandBuffer();
	char* readRs232();
	void initRs232();
	void writeRs232(char* text);
	void Echo();
	uint8_t executeBuffer();

};

#endif /* COMMAND_BUFFER_COMMANDBUFFER_H_ */
