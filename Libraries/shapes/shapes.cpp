/**
 ******************************************************************************
 *@file shapes.cpp
 *@brief Bevat de functies voor het tekenen van vormen
 *@author Trevor van Ginkel
 *@author Matthijs Uit den Boogaard
 ******************************************************************************
 */

#include "shapes.h"
#include <stdlib.h>
#include <math.h>

PixelBuffer* ppBuf;

/**
 @brief Zorgt ervoor dat een lokale variabele extern gebruikt kan worden
 @param p Pointer naar object van het type PixelBuffer
 @return Geeft een foutcode terug mits er een fout is
 */
uint8_t setShapesPixelBuffer(PixelBuffer* pb) {
	ppBuf = pb;
	return 0;
}
uint8_t pushBuffer() {
	ppBuf->push();
	return 0;
}

/**
 @brief Tekent een lijn tussen twee opgegeven coordinaten
 @param x1 Het x-coordinaat voor het eerste punt
 @param y1 Het y-coordinaat voor het eerste punt
 @param x2 Het x-coordinaat voor het tweede punt
 @param y2 Het y-coordinaat voor het tweede punt
 @param col De kleur van de lijn
 @param t De dikte van de lijn
 @return Geeft een foutcode terug mits er een fout is
 */
uint8_t drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,
		uint8_t col, uint8_t t) {
	int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;	//berekening voor het verschil in x richting
	int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;	//berekening voor het verschil in y richting
	int err = (dx > dy ? dx : -dy) / 2, e2;			//berekening voor de lijnerror
	if (t > 1) {									//Wanneer de lijndikte groter dan 1 is
		if (dx > dy) {
			for (int i = 1; i < t; i++) {
				drawLine(x1, y1 + i, x2, y2 + i, col);//tekent een lijn naast de oorspronkelijke lijn
			}
		} else {
			for (int i = 1; i < t; i++) {
				drawLine(x1 + i, y1, x2 + i, y2, col);//idem
			}
		}
	}
	while (1) {
		ppBuf->add(col, x1, y1);					//voegt de pixels toe aan de pixelbuffer
		if (x1 == x2 && y1 == y2)					//lijnerror correctie
			break;
		e2 = err;
		if (e2 > -dx) {
			err -= dy;
			x1 += sx;
		}
		if (e2 < dy) {
			err += dx;
			y1 += sy;
		}
	}

	return 0;
}

/**
 @brief Tekent een rechthoek tussen twee punten
 @param x3 Het x-coordinaat voor het punt linksonder
 @param y3 Het y-coordinaat voor het punt linksonder
 @param x2 Het x-coordinaat voor het punt rechtsboven
 @param y2 Het y-coordinaat voor het punt rechtsboven
 @param col De kleur van de rechthoek
 @param fill Of er wel of niet een fill getekend moet worden
 @return Geeft een foutcode terug mits er een fout is
 */
uint8_t drawRect(uint16_t x3, uint16_t y3, uint16_t x2, uint16_t y2,
		uint8_t col, uint16_t fill) {
	if (x3 == x2 || y3 == y2) {	//x3 mag niet gelijk zijn aan x2 en y3 niet aan y2
		return 2;				//foutcode 2
	}
	if (x3 > x2) {				//swappen van x-coordinaten
		uint16_t x = x3;
		x3 = x2;
		x2 = x;
	}
	if (y3 < y2) {				//swappen van y-coordinaten
		uint16_t y = y3;
		y3 = y2;
		y2 = y;
	}

	if (drawLine(x3, y3, x2, y3, col)) {	//tekenen van de 4 lijnen waaruit de rechthoek bestaat
		return 1;
	}
	if (drawLine(x3, y2, x3, y3, col)) {
		return 1;
	}
	if (drawLine(x2, y2, x2, y3, col)) {
		return 1;
	}
	if (drawLine(x2, y2, x3, y2, col)) {
		return 1;
	}
	if (fill) { //Als vulling gewenst is
		if (x2 != x3 && y2 != y3)
			drawRect(x3 + 1, y3 - 1, x2 - 1, y2 + 1, col, 1); //vult de rechthoek met steeds kleinere rechthoeken
	}
	return 0;
}

/**
 @brief Tekent een driehoek tussen drie punten
 @param x1 Het x-coordinaat voor het eerste punt
 @param y1 Het y-coordinaat voor het eerste punt
 @param x2 Het x-coordinaat voor het tweede punt
 @param y2 Het y-coordinaat voor het tweede punt
 @param x3 Het x-coordinaat voor het derde punt
 @param y3 Het y-coordinaat voor het derde punt
 @param col De kleur van de driehoek
 @param fill Of er wel of niet een fill getekend moet worden
 @return Geeft een foutcode terug mits er een fout is
 */
uint8_t drawTri(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3,
		uint16_t y3, uint8_t col, uint16_t fill) {
	if (drawLine(x2, y2, x1, y1, col)) {	//Tekent de drie lijnen waar de driehoek uit bestaat
		return 1;
	}
	if (drawLine(x3, y3, x1, y1, col)) {
		return 1;
	}
	if (drawLine(x3, y3, x2, y2, col)) {
		return 1;
	}

	return 0;
}

/**
 @brief Tekent een ellipse op een punt met een straal met een optionele fill
 @param x Het x-coordinaat voor het midden van de ellips
 @param y Het y-coordinaat voor het midden van de ellips
 @param xrad De radius in x-richting
 @param yrad De radius in y-richting
 @param col De kleur van de ellips
 @param fill Of er wel of niet een fill getekend moet worden
 @param fillcol De kleur van de fill van de ellips
 @return Geeft een foutcode terug mits er een fout is
 */
uint8_t drawEllip(uint16_t x, uint16_t y, uint16_t xrad, uint16_t yrad,
		uint8_t col, uint16_t fill, uint8_t fillCol) {
	uint16_t xp, yp;
	float p;

	if (fill == true) {
		drawEllipFill(x, y, xrad, yrad, fillCol);//roept andere functie aan die
												 //verantwoordelijk is voor gevulde ellipsen
	}

	//Eerste region
	p = yrad * yrad - xrad * xrad * yrad + xrad * xrad / 4;
	xp = 0;
	yp = yrad;
	while (2.0 * yrad * yrad * xp <= 2.0 * xrad * xrad * yp) {
		if (p < 0) {
			xp++;
			p = p + 2 * yrad * yrad * xp + yrad * yrad;
		} else {
			xp++;
			yp--;
			p = p + 2 * yrad * yrad * xp - 2 * xrad * xrad * yp - yrad * yrad;
		}
		ppBuf->add(col, x + xp, y + yp);	//voegt de berekende pixels toe aan de pixelbuffer
		ppBuf->add(col, x + xp, y - yp);
		ppBuf->add(col, x - xp, y + yp);
		ppBuf->add(col, x - xp, y - yp);
		ppBuf->add(col, x, y + yrad);	   //compensatie voor missende pixel
		ppBuf->add(col, x, y - yrad);	   //idem
	}

	//Tweede region
	p = yrad * yrad * (xp + 0.5) * (xp + 0.5)
			+ xrad * xrad * (yp - 1) * (yp - 1) - xrad * xrad * yrad * yrad; //HIER
	while (yp > 0) {
		if (p <= 0) {
			xp++;
			yp--;
			p = p + 2 * yrad * yrad * xp - 2 * xrad * xrad * yp + xrad * xrad;
		} else {
			yp--;
			p = p - 2 * xrad * xrad * yp + xrad * xrad;
		}
		ppBuf->add(col, (x) + xp, y + yp);	//voegt de berekende pixels toe aan de pixelbuffer
		ppBuf->add(col, (x) + xp, y - yp);
		ppBuf->add(col, (x) - xp, y + yp);
		ppBuf->add(col, (x) - xp, y - yp);
	}
	return 0;
}

/**
 @brief Tekent een ellips met een fill (als deel van drawEllip)
 @param x Het x-coordinaat voor het midden van de ellips
 @param y Het y-coordinaat voor het midden van de ellips
 @param xrad De radius in x-richting
 @param yrad De radius in y-richting
 @param col De kleur van de ellips
 @return Geeft een foutcode terug mits er een fout is
 */
uint8_t drawEllipFill(uint16_t x, uint16_t y, uint16_t xrad, uint16_t yrad,
		uint8_t col) //met alleen fill
		{
	for (int yp = -yrad; yp <= yrad; yp++) { //algoritme voor het tekenen van een gevulde cirkel
		for (int xp = -xrad; xp <= xrad; xp++) {
			double dx = (double) xp / (double) xrad;
			double dy = (double) yp / (double) yrad;
			if (dx * dx + dy * dy <= 1)
				ppBuf->add(col, xp + x, yp + y); //voegt de berekende pixel toe aan de pixelbuffer
		}
	}
	return 0;
}

