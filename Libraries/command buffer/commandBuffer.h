/*
 * commandBuffer.h
 *
 *  Created on: 16 mei 2018
 *      Author: Trevor van Ginkel
 */
/*
#ifndef COMMAND_BUFFER_COMMANDBUFFER_H_
#define COMMAND_BUFFER_COMMANDBUFFER_H_

class CommandBuffer {
private:
		char* command[];
		void clearBuffer();

public:
	char* readRs232();
	void initRs232();
	void writeRs232(const char* text);
	uint_8 executeBuffer();
	CommandBuffer();
	CommandBuffer(char *s);
	~CommandBuffer();
};

#endif /* COMMAND_BUFFER_COMMANDBUFFER_H_ */
