/*
 * spi.h
 *
 *  Created on: April 10, 2017
 *      Author: Omkar & Aasheesh
 */

#include <stdlib.h>
#include <stdint.h>
#include "MKL25Z4.h"

#ifndef _SPI_H_
#define _SPI_H_

#define RESET		0		//Macro to reset register
#define SPI_CONTROL_1   0x50            //value for control register 1
#define SPI_BAUD_RATE_MAX   0x00        //Baud rate divisior set to 2
#define NOP                 0xFF        //NOP Command for nordic



/*********************************************************************
*SPI_init
*	description:This function initializes the SPI0 for the KL25Z and
*	sets the values of the configuration registers in order to get the
*	following characteristics:
*		1. Baud Rate: Bus Clock / 2
*		2. MSB First
*		3. Disables Interrupts
*		4. Sets up the SPI0 pins
*
*	parameters:N/A
*	returns:N/A
*********************************************************************/

void SPI_init(void);

/*********************************************************************
*SPI_flush
*	description:Blocks until the transmit buffer is completely empty
*       parameters:N/A
*	returns:N/A
*********************************************************************/

void SPI_flush();

/*********************************************************************
*SPI_read_byte
*	description:This function reads from the data register of the SPI
*	so that the it can be used by the program.
*	parameters:
*		uint8_t byte: variable that store read command as well as
*		will store the value of the received byte
*
*	returns:unsigned byte
*********************************************************************/

uint8_t SPI_read_byte(uint8_t byte);

/*********************************************************************
*SPI_write_byte
*	description:This function writes to the data register of the SPI0
*	so that the it can be shifted out and sent to the destination
*	parameters:
*		uint8_t byte: The single byte of data that is to be transmitted
*		across the SPI
*
*	returns:N/A
*********************************************************************/

void SPI_write_byte(uint8_t byte);

/*********************************************************************
*SPI_send_packet
*	description:This function writes n bytes to the data register of
*	the SPI0 so that the it can be shifted out and sent to the
*	destination
*	parameters:
*		uint8_t *data_ptr: The pointer to length bytes of data that is
*		to be transmitted across the UART
*
*		size_t length: The length in bytes
*
*	returns:N/A
*********************************************************************/
void SPI_send_packet(uint8_t* p, size_t length);


#endif
