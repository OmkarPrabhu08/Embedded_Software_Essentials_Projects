/*
 * nordic.c
 *
 *  Created on: Apr 10, 2017
 *      Author: Omkar & Aasheesh
 */
#include "nordic.h"
#include "spi.h"
#include "gpio.h"




uint8_t nrf_read_register (uint8_t reg) {
nrf_chip_enable();
uint8_t a;
uint8_t b;
SPI_write_byte(READ | reg);
b = SPI_read_byte(a);
SPI_write_byte(NOP);
b = SPI_read_byte(a);
nrf_chip_disable();
return b;
}

void nrf_write_register(uint8_t reg, uint8_t value) {
uint8_t a;
uint8_t b;
nrf_chip_enable();
SPI_write_byte(WRITE | reg);
b = SPI_read_byte(a);
SPI_write_byte(value);
b = SPI_read_byte(a);
nrf_chip_disable();
}

uint8_t nrf_read_status() {
uint8_t a;
uint8_t reg = NRF_STATUS_REG;
a = nrf_read_register(reg);
return a;
}

void nrf_write_config(uint8_t config) {
uint8_t reg = NRF_CONFIG_REG;
nrf_write_register(reg , config);
}

uint8_t nrf_read_config() {
uint8_t a;
uint8_t reg = NRF_CONFIG_REG;
nrf_read_register(reg);
a = nrf_read_register(reg);
return a;
}

uint8_t nrf_read_rf_setup() {
uint8_t a;
uint8_t reg = NRF_RF_SETUP_REG;
nrf_read_register(reg);
a = nrf_read_register(reg);
return a;
}

void nrf_write_rf_setup(uint8_t config) {
uint8_t reg = NRF_RF_SETUP_REG;
nrf_write_register(reg , config);
}

uint8_t nrf_read_rf_ch() {
uint8_t a;
uint8_t reg = NRF_RF_CHANNEL_REG;
nrf_read_register(reg);
a = nrf_read_register(reg);
return a;
}

void nrf_write_rf_ch(uint8_t channel) {
uint8_t reg = NRF_RF_CHANNEL_REG;
nrf_write_register(reg , channel);
}

void nrf_write_TX_ADDR(uint8_t* tx_addr){
	uint8_t a;
	uint8_t b;
	uint8_t c;
	uint8_t reg = NRF_TXADDR_REG;
	nrf_chip_enable();
	SPI_write_byte(WRITE | reg);
	a = SPI_read_byte(c);
	c = *tx_addr;
	SPI_write_byte(c);
	a = SPI_read_byte(b);
	tx_addr++;
	c = *tx_addr;
    SPI_write_byte(c);
	a = SPI_read_byte(b);
	tx_addr++;
	c = *tx_addr;
	SPI_write_byte(c);
	a = SPI_read_byte(b);
	tx_addr++;
	c = *tx_addr;
	SPI_write_byte(c);
	a = SPI_read_byte(b);
	tx_addr++;
	c = *tx_addr;
	SPI_write_byte(c);
	a = SPI_read_byte(b);
	tx_addr++;
	nrf_chip_disable();
}

void nrf_read_TX_ADDR(uint8_t* tx_addr){
	uint8_t a;
	uint8_t b;
	uint8_t c = 0;
	uint8_t reg = NRF_TXADDR_REG;
	nrf_chip_enable();
	SPI_write_byte(READ | reg);
	a = SPI_read_byte(c);
	SPI_write_byte(NOP);
	*tx_addr = SPI_read_byte(c);
	tx_addr++;
    SPI_write_byte(NOP);
    *tx_addr= SPI_read_byte(c);
	tx_addr++;
	SPI_write_byte(NOP);
	*tx_addr= SPI_read_byte(c);
	tx_addr++;
	SPI_write_byte(NOP);
    *tx_addr= SPI_read_byte(c);
	tx_addr++;
	SPI_write_byte(NOP);
	*tx_addr= SPI_read_byte(c);
	tx_addr++;
	nrf_chip_disable();

}

uint8_t nrf_read_fifo_status() {
uint8_t a;
uint8_t reg = NRF_FIFO_STATUS_REG;
nrf_read_register(reg);
a = nrf_read_register(reg);
return a;

}

void nrf_flush_tx_fifo()  {
uint8_t reg = FLUSH_TX;
while(!(SPI0_S & SPI_S_SPTEF_MASK));
SPI0_D = reg;

}

void nrf_flush_rx_fifo() {
uint8_t reg = FLUSH_RX;
while(!(SPI0_S & SPI_S_SPTEF_MASK));
SPI0_D = reg;

}
