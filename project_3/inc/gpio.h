/*
 * gpio.h
 *
 *  Created on: April 10, 2017
 *      Author: Omkar & Aasheesh
 */

#include <stdlib.h>
#include <stdint.h>
#include "MKL25Z4.h"

#ifndef _GPIO_H_
#define _GPIO_H_

/*********************************************************************
* GPIO_nrf_init
*	description:This function initializes the GPIO pins for the KL25Z and
*	sets the values of the configuration registers in order to get the
*	following characteristics:
*		1. Sets GPIOs as Slave Select and Transmit Enable pins
*		2. Sets their direction as Output
*		3. Sets output to one
*
*	parameters:N/A
*	returns:N/A
*********************************************************************/
uint8_t GPIO_nrf_init();




#endif /* INCLUDES_GPIO_H_ */
