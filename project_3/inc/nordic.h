/*
 * nordic.h
 *
 *  Created on: April 10, 2017
 *      Author: Omkar & Aasheesh
 */

#include <stdlib.h>
#include <stdint.h>
#include "MKL25Z4.h"

#ifndef _NORDIC_H_
#define _NORDIC_H_

#define  nrf_chip_enable() GPIOC_PCOR |= (1 << 4);   // macro to enable chip
#define  nrf_chip_disable() GPIOC_PSOR |= (1 << 4);  // macro to disable chip
#define  nrf_transmit_enable() GPIOC_PCOR |= (1 << 3); // macro to enable transmission
#define  nrf_transmit_disable() GPIOC_PSOR |= (1 << 3); // macro to disable transmission

#define NRF_CONFIG_REG (0x00)
#define NRF_RF_CHANNEL_REG (0x05)
#define NRF_RF_SETUP_REG (0x06)
#define NRF_STATUS_REG (0x07)
#define NRF_FIFO_STATUS_REG (0x17)
#define NRF_TXADDR_REG (0x10)

#define READ (0x00)
#define WRITE (0x20)

#define NRF_POWER_UP_MASK (0x02)
#define NRF_CHANNEL_FREQ_MASK (0x03)
#define NRF_SET_LAN_GAIN_MASK (0x01)
#define FLUSH_TX (0xE1)
#define FLUSH_RX (0xE2)

/**
 * This reads given nrf specific register 
 *         
 * @returns a varaible called a
 */
uint8_t nrf_read_register (uint8_t reg);

/**
 * This writes given nrf specific register with value
 *         
 * @return N/A 
 */
void nrf_write_register(uint8_t reg, uint8_t value);

/**
 * This reads status register of nrf module
 *         
 * @returns a varaible called a
 */
uint8_t nrf_read_status();

/**
 * This writes config registers of nrf module 
 *         
 * @return N/A
 */
void nrf_write_config(uint8_t config);

/**
 * This reads config registers of nrf module 
 *         
 * @return value of config register
 */
uint8_t nrf_read_config() ;

/**
 * This reads rf setup register
 *         
 * @returns read rf register value
 */
uint8_t nrf_read_rf_setup();

/**
 * This writes rf setup register
 *         
 * @returns N/A
 */
void nrf_write_rf_setup(uint8_t config);

/**
 * This reads rf channel register
 *         
 * @returns rf channel register value
 */
uint8_t nrf_read_rf_ch();

/**
 * This writes to rf channel register
 *         
 * @returns N/A
 */
void nrf_write_rf_ch(uint8_t channel);

/**
 * This writes 5 bytes to tx register
 *         
 * @returns N/A
 */
void nrf_write_TX_ADDR(uint8_t * tx_addr);

/**
 * This reads 5 bytes from tx register
 *         
 * @returns N/A
 */
void nrf_read_TX_ADDR(uint8_t* tx_addr);

/**
 * This reads fifo status register
 *         
 * @returns fifo status
 */
uint8_t nrf_read_fifo_status();

/**
 * This sends flush command to tx fifo
 *         
 * @returns N/A
 */
void nrf_flush_tx_fifo();

/**
 * This sends flush command to rx fifo
 *         
 * @returns N/A
 */
void nrf_flush_rx_fifo();

#endif /* INCLUDES_NORDIC_H_ */
