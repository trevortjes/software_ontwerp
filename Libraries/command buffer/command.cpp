/*
 * command.cpp
 *
 *  Created on: May 17, 2018
 *      Author: matboy1200
 */

#include "command.h"

Command::Command() {
	// TODO Auto-generated constructor stub
	commandString=0;
}
Command::Command(char *s){
	commandString=s; //er moet nog memmory gealloceerd worden voor deze string anders schrijft de dma de string weer over en heb ik 100 keer dezelfde string

}

Command::~Command() {
	// TODO Auto-generated destructor stub
}

