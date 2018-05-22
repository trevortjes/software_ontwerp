/*
 * commandBuffer.cpp
 *
 *  Created on: 16 mei 2018
 *      Author: trevo
 */

#include "commandBuffer.h"
#include "uart.h"
#include <malloc.h>
#define nullptr 0


char *stringBuf;
char* commands[20];
void initRs232()
{
//if rs232 not initialized then initialize
	if(initit != 1)
	{
		UART_init();
	}
}
void writeRs232(char* text)
{
	UART_puts(text);
}

CommandBuffer::CommandBuffer()
{
	// TODO Auto-generated constructor stub
	initRs232();
	first.nextCommand=nullptr;
	first.thisCommand=nullptr;
}

CommandBuffer::CommandBuffer(char *s)
{
	initRs232();
	Command c(s);
	first.nextCommand=nullptr;
	first.thisCommand=&c;
}

CommandBuffer::~CommandBuffer()
{
	free(this->first.thisCommand);
	struct commandLink *loop= this->first.nextCommand;
	while(loop!=nullptr){
		//writeRs232("test");
		free(loop->thisCommand);
		struct commandLink *freed=loop;
		loop=loop->nextCommand;
		free(freed);
	}
}

void CommandBuffer::clearBuffer(){
	free(this->first.thisCommand);
	struct commandLink *loop= this->first.nextCommand;
		while(loop!=nullptr){
			//writeRs232("test");
			free(loop->thisCommand);
			struct commandLink *freed=loop;
			loop=loop->nextCommand;
			free(freed);
		}
		this->first.thisCommand=0;
		this->first.nextCommand=0;
}
uint8_t CommandBuffer::executeBuffer()
{
	struct commandLink *loop= &this->first;
	while(loop!=nullptr){

		loop->thisCommand->execute();
		loop=loop->nextCommand;
	}
	return 0;
}

uint8_t CommandBuffer::addCommand(char *s){
	Command *c=(Command *)malloc(sizeof(Command));
	c=new Command(s);
	if(first.thisCommand==nullptr){
		first.thisCommand = c;
		return 0;
	}
	struct commandLink *cl=(struct commandLink *)malloc(sizeof(struct commandLink));
	cl->thisCommand = c;
	cl->nextCommand = 0;
	struct commandLink *loop= &this->first;
	int i=1;
	while(loop->nextCommand!=nullptr){
		loop=loop->nextCommand;
		i++;
	}
	loop->nextCommand=cl;
	return 0;
}

uint8_t CommandBuffer::checkForCommands(){
	char array[120];
	UART_gets(array,0);
	int i=0;
	for(i=0;array[i]!='\0';i++);
	char *s= (char*)malloc(sizeof(char)*i);
	for(int x=0;x<i;x++){
		s[x]=array[x];
	}
	this->addCommand(s);
	this->executeBuffer();
	return 0;

}
/*




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

	UART_puts(this->readRs232());
}


*/
