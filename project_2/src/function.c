#include"MKL25Z4.h"
#include"uart.h"
#include"circbuf.h"
#include"logger.h"
#include"memory.h"


buf_ptr *rx;
int8_t arr[1] = {1};
int8_t *src;
int8_t rec;

int main(void)
{       src = arr;
        mem_param *mem_pointer;
        mem_pointer->src = src;
        mem_pointer->dst = src + 4;
        mem_pointer->length = 1;
        tx = malloc(sizeof(buf_ptr));
	tx->Buffer = malloc(sizeof(int8_t) * 100);
	init_buff(tx, 100);
	rx = malloc(sizeof(buf_ptr));
	rx->Buffer = malloc(sizeof(int8_t) * 100);
	init_buff(rx, 100);
	uart_configure();
        src = arr;
	UART0_C2 |= UART0_C2_RIE_MASK;
        UART0_C2 |= UART0_C2_TIE_MASK;
        return 0;
}
void UART0_IRQHandler(void)
{
	__disable_irq();
	if (UART0_S1 & UART_S1_RDRF_MASK){
        rec = UART0_D;
        Buffer_add(rx,&rec);
        if(*(rx->Head) == 'a')
        {
          my_memmove(mem_pointer);
	}
        if (UART0_S1 & UART_S1_TDRE_MASK){
          log_data(src+4,1,tx);
	}
	__enable_irq();
}
