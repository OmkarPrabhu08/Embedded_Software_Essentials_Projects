#include"MKL25Z4.h"
#include"uart.h"
#include"circbuf.h"
#include"logger.h"

buf_ptr *tx,*rx;
int8_t arr[3] = {0x33,0x33,0x33};
int8_t *src;
int8_t rec;

int main(void)
{
	tx = malloc(sizeof(buf_ptr));
	tx->Buffer = malloc(sizeof(int8_t) * 100);
	init_buff(tx, 100);
	rx = malloc(sizeof(buf_ptr));
	rx->Buffer = malloc(sizeof(int8_t) * 100);
	init_buff(rx, 100);
	uart_configure();
    src = arr;
	UART0_C2 |= UART0_C2_RIE_MASK; //Enable receiver interrupt
	UART0_C2 |= UART0_C2_TIE_MASK; //Enable transmit interrupt
    return 0;
}

void UART0_IRQHandler(void)
{
	__disable_irq();
	if (UART0_S1 & UART_S1_RDRF_MASK){
        rec = UART0_D;
        Buffer_add(rx,&rec);
	}
	if (UART0_S1 & UART_S1_TDRE_MASK){
		log_data(src,3,tx);
	}
	__enable_irq();
}
