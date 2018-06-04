/**
 * *************************************************************************************
 *@file commandBuffer.h
 *@brief De buffer met alle commands
 *@author Matthijs Uit den Bogaard
 *
 *Een buffer met alle commando's die binnengekomen zijn er in.
 */

#ifndef COMMAND_BUFFER_COMMANDBUFFER_H_
#define COMMAND_BUFFER_COMMANDBUFFER_H_

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "LinkedList.h"
#include "command.h"
class CommandBuffer {
private:
	/**
	 * @brief Het eerste commando met een link naar de volgend commando
	 */
	struct commandLink first;
	/**
	 * @brief houd bij of de buffer is uitgevoerd of niet
	 */
	bool exec;
	/**
	 * @brief verwijderd alle commando's uit de buffer
	 */
	void clearBuffer();

public:
	/**
	 * @brief default constructor die een volledig lege buffer maakt
	 */
	CommandBuffer();
	/**
	* @brief Constructor die een buffer maakt met het eerste command al ingevoerd
	*/
	CommandBuffer(char *s);
	/**
	 * @brief default destructor die alle commando's verwijderd en daarna de commandbuffer
	 * @param s het eerste commando
	 */
	~CommandBuffer();
	/**
	 * @brief voegt een commando toe aan de buffer
	 * @param s het toe te voegen commando
	 * @return de errorcode
	 */
	uint8_t addCommand(char *s);
	/**
	 * @brief Controleerd de UART en voor commando's en als die er zijn worden deze toegevoegde
	 */
	uint8_t checkForCommands();
	/**
	 * @brief stuurt het error bericht naar de gebruiker
	 * @param e de errocode
	 * @return error
	 *
	 * zet de errorcode om naar een bruikbaar bericht voor de gebruiker en stuurt dit bericht op
	 */
	uint8_t sendError(uint8_t e);
	/**
	 * @brief voert alle commando's in de buffer 1 voor 1 uit
	 * @return error
	 */
	uint8_t executeBuffer();


};

#endif /* COMMAND_BUFFER_COMMANDBUFFER_H_ */
