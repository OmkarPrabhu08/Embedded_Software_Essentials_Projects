#include"MKL25Z4.h"
#include"uart.h"

void uart_configure(void){
#ifdef INTERRUPT
	__enable_irq();//enable global interrupts
	NVIC->ISER[0] |= UART0_INT_ENABLE_MASK;//enable uart0 interrupt in nvic
#endif
	SIM_SOPT2 |= SIM_SOPT2_MCGFLLCLK_MASK;//enable fll clock
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;//enable clock gate
	UART0_C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);//disable transmit and receive for config
	UART0_BDH &= 0x00;
	UART0_BDL |= SBR_VAL;
	UART0_C4 |= OSR_VAL;
	UART0_C2 |= (UART0_C2_TE_MASK | UART0_C2_RE_MASK );//enable transmit and receive
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;//enable porta clock
	PORTA_PCR1 = PORT_PCR_MUX(2);//pinmux
	PORTA_PCR2 = PORT_PCR_MUX(2);//pinmux
}

void uart_send_byte(int8_t data){


	UART0_D = data;
}

void uart_send_byte_n(uint8_t *data, uint32_t length){
	uint8_t i;
	for(i=0;i<length;i++){
#ifndef INTERRUPT
	while(!(UART0_S1_REG(UART0_BASE_PTR) & UART0_S1_TDRE_MASK));
#endif
	UART0_D_REG(UART0_BASE_PTR) = *data;
	data++;
	}
}

int8_t uart_recieve_byte (void){

    return UART0_D_REG(UART0_BASE_PTR);
}
