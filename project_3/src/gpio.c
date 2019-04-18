/*
 * gpio.c
 *
 *  Created on: Apr 10, 2017
 *      Author: Omkar & Aasheesh
 */
#include "gpio.h"



uint8_t GPIO_nrf_init()  {



	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK; // enable clock for port C

	PORTC_PCR4 = PORT_PCR_MUX(1);  // Configuring PORT C PIN 4 to GPIO using MUX and use as slave select
        PORTC_PCR3 = PORT_PCR_MUX(1);  // Configuring PORT C PIN 3 to GPIO using MUX and use as transmit enable

        GPIOC_PDDR |= (1 << 4);			        //Set direction of PortC Pin 4 to output
	GPIOC_PSOR |= (1 << 4);				//Sets output to 1

        GPIOC_PDDR |= (1 << 3);				//Set direction of PortC Pin 3 to output
	GPIOC_PSOR |= (1 << 3);				//Sets output to 1
	return 0;
}



