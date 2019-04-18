/*
 * spi.c
 *
 *  Created on: Apr 10, 2017
 *      Author: Omkar & Aasheesh
 */
#include "spi.h"


void SPI_init(void) {



	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK; // enable clock for port C

	SIM_SCGC4 |= SIM_SCGC4_SPI0_MASK;  // enable clock for SPI0


	PORTC_PCR5 = PORT_PCR_MUX(2);  // Configuring PORT C PIN 5 to SCK using MUX

	PORTC_PCR6 = PORT_PCR_MUX(2);  // Configuring PORT C PIN 6 to MOSI using MUX

	PORTC_PCR7 = PORT_PCR_MUX(2);  // Configuring PORT C PIN 7 to MISO using MUX


	SPI0_C1 = SPI_CONTROL_1;         //Set SPI in master mode and disabled interrupts and obtained required clock settings

	SPI0_BR = SPI_BAUD_RATE_MAX;         //Set SPI Baud Rate to Bus Clock / 2

}


uint8_t SPI_read_byte(uint8_t byte) {

        while(!(SPI0_S & SPI_S_SPRF_MASK));   //check whether SPRF bit is set if yes then receive buffer can be read otherwise wait
        byte = SPI0_D;	                      //reads byte from receiver buffer
        return byte;

}

void SPI_write_byte(uint8_t byte) {
	while(!(SPI0_S & SPI_S_SPTEF_MASK));
	SPI0_S &= 0xDF;
        SPI0_D = byte;                       //writes byte to transmission buffer

}


void SPI_send_packet(uint8_t* p, size_t length) {

       uint8_t i;
       for(i = 0; i < length; i ++)
       {
   	   while(!(SPI0_S & SPI_S_SPTEF_MASK));
        SPI0_D = *p;                      //writes byte to transmission buffer
        while(!(SPI0_S & SPI_S_SPRF_MASK));   //check whether SPRF bit is set if yes then receive buffer can be read otherwise wait
                *p= SPI0_D;	                      //reads byte from receiver buffer

       p++;
       }

}

SPI_flush() {
	while(!(SPI0_S & SPI_S_SPTEF_MASK));
}

