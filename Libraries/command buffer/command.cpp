/*
 * command.cpp
 *
 *  Created on: May 17, 2018
 *      Author: matboy1200
 */

#include "command.h"
#include "shapes.h"
#include "wait.h"
#include "text.h"
#include "bmp.h"
#include "collors.h"
#include "clearScreen.h"
#include <string.h>

uint16_t sti(char *s) {
	uint16_t result = 0;
	int i = 0;
	while (*(s + i) != ',' && *(s + i) != '\0') {
		result = result * 10 + (*(s + i) - '0');
		i++;
	}
	return result;
}

uint8_t color(char *s) {
	char *a=s;
	while(*a!='\0'){
		if(*a=='\f'){
			*a='\0';
		}
		a++;
	}

	if (strcmp(s, "zwart") == 0) {
		return BLACK;
	} else if (strcmp(s, "rood") == 0) {
		return RED;
	} else if (strcmp(s, "bruin") == 0) {
		return BROWN;
	} else if (strcmp(s, "groen") == 0) {
		return GREEN;
	} else if (strcmp(s, "blauw") == 0) {
		return BLUE;
	} else if (strcmp(s, "lichtrood") == 0) {
		return RED;
	} else if (strcmp(s, "wit") == 0) {
		return WHITE;
	} else if (strcmp(s, "grijs") == 0) {
		return GRAY;
	} else if (strcmp(s, "cyaan") == 0) {
		return CYAN;
	} else if (strcmp(s, "magenta") == 0) {
		return MAGENTA;
	} else if (strcmp(s, "geel") == 0) {
		return YELLOW;
	} else if (strcmp(s, "paars") == 0) {
		return PURPLE;
	} else if (strcmp(s, "roze") == 0) {
		return PINK;
	} else if (strcmp(s, "lichtblauw") == 0) {
		return LIGHT_BLUE;
	} else if (strcmp(s, "lichtgroen") == 0) {
		return LIGHT_GREEN;
	} else if (strcmp(s, "lichtrood") == 0) {
		return LIGHT_RED;
	} else if (strcmp(s, "lichtcyaan") == 0) {
		return LIGHT_CYAN;
	} else if (strcmp(s, "lichtmagenta") == 0) {
		return LIGHT_MAGENTA;
	}
	return 127;
}
Command::Command() {
	// TODO Auto-generated constructor stub
	commandString = 0;
}
Command::Command(char *s) {
	commandString = s; //er moet nog memmory gealloceerd worden voor deze string anders schrijft de dma de string weer over en heb ik 100 keer dezelfde string

}

Command::~Command() {
	// TODO Auto-generated destructor stub
}

uint8_t Command::execute() {
	switch (*this->commandString) {
	case 'c':
		return this->clear();
	case 'e':
		return this->ellipse();
	case 'l':
		return this->lijn();
	case 'r':
		return this->rechthoek();
	case 't':
		return this->tekst();
	case 'w':
		return this->wacht();
	case 'd':
		return this->driehoek();
	case 'b':
		return this->bitmap();
	default:
		return 255;

	}
}

uint8_t Command::clear() {
	char check[] = "clearscherm,";
	int i;
	for (int i = 0; i < 12; i++) {
		if (*(this->commandString + i) != check[i]) {
			return 255;
		}
	}
	char c[20];
	i = 0;
	while (*(this->commandString + i + 12) != '\0') {
		c[i] = *(this->commandString + i + 12);
		i++;
	}
	c[i] = '\0';
	uint8_t col = color(c);
	pushBuffer();
	return clearScherm(col);

}
uint8_t Command::lijn() {
	char check[] = "lijn,";
	int i;
	for (int i = 0; i < 5; i++) {
		if (*(this->commandString + i) != check[i]) {
			return 255;
		}
	}
	char c[20];
	i = 0;
	int k = 5;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t x1 = sti(c);
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t y1 = sti(c);
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t x2 = sti(c);
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	uint16_t y2 = sti(c);
	i++;
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	uint16_t d = sti(c);
	i++;
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != '\0') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	uint8_t col = color(c);
	if(x1>320||x1<0||y1>240||y1<0||x2>320||x2<0||y2>240||y2<0){
		return 255;
	}
	return drawLine(x1, y1, x2, y2, col, d);
}
uint8_t Command::ellipse() {
	char check[] = "ellips,";
	int i;
	for (int i = 0; i < 7; i++) {
		if (*(this->commandString + i) != check[i]) {
			return 255;
		}
	}
	char c[20];
	i = 0;
	int k = 7;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t x1 = sti(c);
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t y1 = sti(c);
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t x2 = sti(c);
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	uint16_t y2 = sti(c);

	i++;
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != '\0') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	uint8_t col = color(c);
	if(x2>320||x2<0||y2>240||y2<0){
			return 255;
		}
	return drawEllip(x1, y1, x2, y2, col, 0, 0);
}

uint8_t Command::rechthoek() {
	char check[] = "rechthoek,";
	int i;
	for (int i = 0; i < 10; i++) {
		if (*(this->commandString + i) != check[i]) {
			return 255;
		}
	}
	char c[20];
	i = 0;
	int k = 10;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t x1 = sti(c);
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t y1 = sti(c);
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t x2 = sti(c);
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	uint16_t y2 = sti(c);

	i++;
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != '\0') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	uint8_t col = color(c);
	if(x1>320||x1<0||y1>240||y1<0||x2>320||x2<0||y2>240||y2<0){
			return 255;
		}
	return drawRect(x1, y1, x2, y2, col, 0);
}

uint8_t Command::driehoek() {
	char check[] = "driehoek,";
	int i;
	for (int i = 0; i < 9; i++) {
		if (*(this->commandString + i) != check[i]) {
			return 255;
		}
	}
	char c[20];
	i = 0;
	int k = 9;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t x1 = sti(c);
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t y1 = sti(c);
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t x2 = sti(c);
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	uint16_t y2 = sti(c);
	i++;
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t x3 = sti(c);
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	uint16_t y3 = sti(c);

	i++;
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != '\0') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	uint8_t col = color(c);
	if(x1>320||x1<0||y1>240||y1<0||x2>320||x2<0||y2>240||y2<0||x3>320||x3<0||y3>240||y3<0){
			return 255;
		}
	return drawTri(x1, y1, x2, y2, x3, y3, col, 0);
}

uint8_t Command::wacht() {
	char check[] = "wacht,";
	for (int i = 0; i < 6; i++) {
		if (*(this->commandString + i) != check[i]) {
			return 255;
		}
	}
	pushBuffer();
	return wait(sti(this->commandString + 6));
}

uint8_t Command::bitmap() {
	char check[] = "bitmap,";
	int i;
	for (int i = 0; i < 7; i++) {
		if (*(this->commandString + i) != check[i]) {
			return 255;
		}
	}
	char c[20];
	i = 0;
	int k = 7;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t nr = sti(c);
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t x1 = sti(c);
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != '\0') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t y1 = sti(c);
	if(x1>320||x1<0||y1>240||y1<0){
			return 255;
		}
	return writeBMPROM(nr, x1, y1);
}
uint8_t Command::tekst() {

	char check[] = "tekst,";
	int i;
	for (int i = 0; i < 6; i++) {
		if (*(this->commandString + i) != check[i]) {
			return 255;
		}
	}
	char c[250];
	i = 0;
	int k = 6;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t x1 = sti(c);
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	c[i] = '\0';
	i++;
	uint16_t y1 = sti(c);
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		c[i] = *(this->commandString + i + k);
		i++;
	}
	i++;
	c[i] = '\0';
	char s[20];
	k += i;
	i = 0;
	while (*(this->commandString + i + k) != ',') {
		s[i] = *(this->commandString + i + k);
		i++;
	}
	i++;
	uint16_t col = sti(s);
	k += i;

	uint16_t b = 0;
	if (strcmp((this->commandString + k), "norm") == 0) {
		b = 0;
	} else if (strcmp((this->commandString + k), "vet") == 0) {
		b = 1;
	} else if (strcmp((this->commandString + k), "cursief") == 0) {
		b = 2;
	}
	if(x1>320||x1<0||y1>240||y1<0){
			return 255;
		}
	return drawText(x1, y1, c, col, b);
}
