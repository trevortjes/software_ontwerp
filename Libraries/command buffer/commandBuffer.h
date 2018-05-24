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
#include "LinkedList.h"
#include "command.h"
class CommandBuffer {
private:
		struct commandLink first;
		void clearBuffer();
		bool exec;

public:
	CommandBuffer();
	CommandBuffer(char *s);
	~CommandBuffer();
	uint8_t addCommand(char *s);
	uint8_t checkForCommands();
	uint8_t sendError(uint8_t e);
	uint8_t executeBuffer();

};

#endif /* COMMAND_BUFFER_COMMANDBUFFER_H_ */
