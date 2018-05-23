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

	char black[] = "zwart";
	char red[] = "rood";
	char green[] = "groen";
	char blue[] = "blauw";
	char lred[] = "lichtrood";

	if (strcmp(s, black) == 0) {
		return BLACK;
	} else if (strcmp(s, red) == 0) {
		return RED;
	} else if (strcmp(s, green) == 0) {
		return GREEN;
	} else if (strcmp(s, blue) == 0) {
		return BLUE;
	} else if (strcmp(s, lred) == 0) {
		return RED;
	}else if (strcmp(s, "wit") == 0) {
		return WHITE;
	}

	return BLACK;
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
	return drawLine(x1, y1, x2, y2, col);
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
	return drawTri(x1, y1, x2, y2, x3, y3, col, 0);
}

uint8_t Command::wacht() {
	char check[] = "wacht,";
	for (int i = 0; i < 6; i++) {
		if (*(this->commandString + i) != check[i]) {
			return 255;
		}
	}
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
	return writeBMPROM(nr, x1, y1);
}
uint8_t Command::tekst() {

	return 0;
}
