/*
 * command.cpp
 *
 *  Created on: May 17, 2018
 *      Author: matboy1200
 */

#include "command.h"
#include "shapes.h"
#include "collors.h"
#include "clearScreen.h"
#include <string.h>


uint8_t color(char *s)
{

	 char black[]="zwart";
	 char red[]="rood";
	 char green[]="groen";
	 char blue[]="blauw";
	 char lred[]="lichtrood";

	 if(strcmp(s, black)==0){
		 return BLACK;
	 }else if(strcmp(s, red)==0){
		 return RED;
	 }else if(strcmp(s, green)==0){
		 return GREEN;
	 }else if(strcmp(s, blue)==0){
		 return BLUE;
	 }else if(strcmp(s, lred)==0){
		 return RED;
	 }

	 return BLACK;
}
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

uint8_t Command::execute(){
	switch(*this->commandString){
	case 'c':
		return this->clear();
	case 'e':
		return this->ellipse();
	case 'l':
		return this->lijn();
	default:
		return 255;

	}
}

uint8_t Command::clear(){
	char check[]="clearscherm,";
	int i;
	for(int i=0;i<12;i++){
		if(*(this->commandString+i)!=check[i]){
			return 255;
		}
	}
	char c[20];
	i=0;
	while(*(this->commandString+i+12)!='\0'){
		c[i]=*(this->commandString+i+12);
		i++;
	}
	c[i]='\0';
	uint8_t col=color(c);
	return clearScherm(col);


}
uint8_t Command::lijn (){

}
uint8_t Command::ellipse(){

}


