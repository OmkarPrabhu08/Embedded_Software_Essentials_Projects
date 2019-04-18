/*
 * uart.h
 *
 *  Created on: Mar 6, 2017
 *      Author: daash
 */

#ifndef INCLUDES_UART_H_
#define INCLUDES_UART_H_

#define SIM_SOPT2_MCGFLLCLK_MASK 0x4000000u

#define UART0_INT_ENABLE_MASK 0x00001000u

#define INTERRUPT

#define OSR_VAL 15

#define SBR_VAL 0x17
void uart_configure(void);
void uart_send_byte(int8_t data);
void uart_send_byte_n(uint8_t *data, uint32_t length);
int8_t uart_recieve_byte (void);

#endif /* INCLUDES_UART_H_ */
