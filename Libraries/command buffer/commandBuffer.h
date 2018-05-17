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

class CommandBuffer {
private:
		char command[20];
		void clearBuffer();

public:
	char* readRs232();
	void initRs232();
	void writeRs232(char* text);
	void Echo();
	uint8_t executeBuffer();
	CommandBuffer();
	CommandBuffer(char *s);
	~CommandBuffer();
};

#endif /* COMMAND_BUFFER_COMMANDBUFFER_H_ */
