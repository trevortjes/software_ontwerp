/*
 * command.h
 *
 *  Created on: May 17, 2018
 *      Author: matboy1200
 */

#ifndef COMMAND_BUFFER_COMMAND_H_
#define COMMAND_BUFFER_COMMAND_H_

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

class Command {
private:
	Command();
	char* commandString;
	uint8_t clear();
	uint8_t lijn ();
	uint8_t ellipse();
	uint8_t rechthoek()

public:
	Command(char* s);
	~Command();
	char *getCommand(){return commandString;}
	uint8_t execute();
};

#endif /* COMMAND_BUFFER_COMMAND_H_ */
