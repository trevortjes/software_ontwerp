/**
 ******************************************************************************
 *@file shapes.h
 *@brief Bevat de functies voor het tekenen van vormen
 *@author Trevor van Ginkel
 *@author Matthijs Uit den Boogaard
 ******************************************************************************
 */

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "pixelBuffer.h"

/**
 @brief Zorgt ervoor dat een lokale variabele extern gebruikt kan worden
 @param p Pointer naar object van het type PixelBuffer
 @return Geeft een foutcode terug mits er een fout is
 */
uint8_t setShapesPixelBuffer(PixelBuffer* p);

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
		uint8_t col = 250, uint8_t t = 0);

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
		uint8_t col, uint16_t fill);

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
		uint16_t y3, uint8_t col, uint16_t fill);

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
		uint8_t col, uint16_t fill, uint8_t fillCol);

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
		uint8_t col);
/**
 * @brief zorgt ervoor dat de front layer de pixelbuffer in de io layer kan pushen.
 * @return error
 */
uint8_t pushBuffer();
