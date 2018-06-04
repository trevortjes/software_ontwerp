/**
 * *************************************************************************************
 *@file command.h
 *@brief Een object dat 1 commando bevat
 *@author Matthijs Uit den Bogaard
 *
 *Klasse die een command bevat en de functionaliteit om alle commando's uit te voeren
 */
#ifndef COMMAND_BUFFER_COMMAND_H_
#define COMMAND_BUFFER_COMMAND_H_

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

class Command {
private:
	/**
	 * @brief default constructor die
	 */
	Command();
	/**
	 * @brief het commando
	 */
	char* commandString;
	/**
	 * @brief Voert het commando clear uit
	 * return Errorcode
	 */
	uint8_t clear(); //done
	/**
	 * @brief Voert het commando lijn uit
	 * return Errorcode
	 */
	uint8_t lijn(); //done
	/**
	 * @brief Voert het commando ellipse uit
	 * return Errorcode
	 */
	uint8_t ellipse(); //done
	/**
	 * @brief Voert het commando rechthoek uit
	 * return Errorcode
	 */
	uint8_t rechthoek(); //done
	/**
	 * @brief Voert het commando driehoek uit
	 * return Errorcode
	 */
	uint8_t driehoek(); //done
	/**
	 * @brief Voert het commando tekst uit
	 */
	uint8_t tekst();
	/**
	 * @brief Voert het commando bitmap uit
	 * return Errorcode
	 */
	uint8_t bitmap();
	/**
	 * @brief Voert het commando wacht uit
	 * return Errorcode
	 */
	uint8_t wacht(); //done

public:
	Command(char* s);
	/**
	 * @brief destructor die het command Freeed uit het gegeheugen
	 */
	~Command();
	/**
	 * @brief geeft het commando terug.
	 * return Commandstring
	 */
	char *getCommand() {
		return commandString;
	}
	/**
	 * @brief Voert het commando uit
	 * return errorcode
	 */
	uint8_t execute();
};

#endif /* COMMAND_BUFFER_COMMAND_H_ */
