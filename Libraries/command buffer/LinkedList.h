/*
 * LinkedList.h
 *
 *  Created on: May 20, 2018
 *      Author: matboy1200
 */

#ifndef COMMAND_BUFFER_LINKEDLIST_H_
#define COMMAND_BUFFER_LINKEDLIST_H_

#include "command.h"

struct commandLink{
	Command *thisCommand;
	struct commandLink *nextCommand;
};



#endif /* COMMAND_BUFFER_LINKEDLIST_H_ */
