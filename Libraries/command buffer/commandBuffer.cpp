/**
 * *************************************************************************************
 *@file commandBuffer.cpp
 *@brief De buffer met alle commands
 *@author Matthijs Uit den Bogaard
 *
 *Een buffer met alle commando's die binnengekomen zijn er in.
 */

#include "commandBuffer.h"
#include "uart.h"
#include <malloc.h>
#include <string.h>
#include "shapes.h"
#define nullptr 0

char *stringBuf;
char* commands[20];
void initRs232() {
//if rs232 not initialized then initialize
	if (initit != 1) {
		UART_init();
	}
}
void writeRs232(char* text) {
	UART_puts(text);
}

CommandBuffer::CommandBuffer() {
	// TODO Auto-generated constructor stub
	initRs232();
	first.nextCommand = nullptr;
	first.thisCommand = nullptr;
	exec = false;
}

CommandBuffer::CommandBuffer(char *s) {
	initRs232();
	Command c(s);
	first.nextCommand = nullptr;
	first.thisCommand = &c;
	exec = false;
}

CommandBuffer::~CommandBuffer() {
	free(this->first.thisCommand);
	struct commandLink *loop = this->first.nextCommand;
	while (loop != nullptr) {
		free(loop->thisCommand);
		struct commandLink *freed = loop;
		loop = loop->nextCommand;
		free(freed);
	}
}

void CommandBuffer::clearBuffer() {
	free(this->first.thisCommand);
	struct commandLink *loop = this->first.nextCommand;
	while (loop != nullptr) {
		free(loop->thisCommand);
		struct commandLink *freed = loop;
		loop = loop->nextCommand;
		free(freed);
	}
	this->first.thisCommand = 0;
	this->first.nextCommand = 0;
}
uint8_t CommandBuffer::executeBuffer() {
	struct commandLink *loop = &this->first;
	while (loop != nullptr) {

		if (loop->thisCommand->execute() == 255) {
			UART_puts("Command invalid: ");
			UART_puts(loop->thisCommand->getCommand());
		}
		loop = loop->nextCommand;
	}
	exec = true;
	pushBuffer();
	return 0;
}

uint8_t CommandBuffer::addCommand(char *s) {
	if(*s=='\0'){
		return 0;
	}
	Command *c = (Command *) malloc(sizeof(Command));
	c = new Command(s);
	if (first.thisCommand == nullptr) {
		first.thisCommand = c;
		return 0;
	}
	struct commandLink *cl = (struct commandLink *) malloc(
			sizeof(struct commandLink));
	cl->thisCommand = c;
	cl->nextCommand = 0;
	struct commandLink *loop = &this->first;
	int i = 1;
	while (loop->nextCommand != nullptr) {
		loop = loop->nextCommand;
		i++;
	}
	loop->nextCommand = cl;
	return 0;
}

uint8_t CommandBuffer::checkForCommands() {
	char array[120];
	UART_gets(array, 1);
	int i = 0;
	for (i = 0; array[i] != '\0'; i++)
		;
	char *s = (char*) malloc(sizeof(char) * i);
	int x;
	for (x = 0; x < i; x++) {
		s[x] = array[x];
	}
	s[x] = '\0';
	if (strcmp(s, "execute") == 0 || strcmp(s, "repeat") == 0
			|| strcmp(s, "herhaal") == 0) {
		this->executeBuffer();
		return 0;
	}
	if (exec == true) {
		this->clearBuffer();
	}
	this->addCommand(s);

	return 0;

}
