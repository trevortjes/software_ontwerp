/**
 * @file LinkedList.h
 *
 *@brief Maakt een linked list van commands
 *@author Matthijs Uit den Bogaard
 *
 * bevat een structure met een link naar het command en de volgende structure
 */

#ifndef COMMAND_BUFFER_LINKEDLIST_H_
#define COMMAND_BUFFER_LINKEDLIST_H_

#include "command.h"


struct commandLink{
	Command *thisCommand;
	struct commandLink *nextCommand;
};



#endif /* COMMAND_BUFFER_LINKEDLIST_H_ */
