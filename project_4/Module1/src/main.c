#include"MKL25Z4.h"
#include"uart.h"
#include"circbuf.h"
#include"logger.h"
#include"rtc.h"
#include"led_control.h"
#define SIM_SOPT2_MCGFLLCLK_MASK 0x1000000u

buf_ptr *tx,*rx;
int8_t rec;
int8_t *src;
int8_t index=0;
int8_t count;
int8_t count1 = 4;
int8_t final_value;
int8_t i =0;
int8_t j =0;
int8_t k =0;
int8_t l =0;
int8_t m =0;
int8_t count =0;

CI_Msg *Command = &final_value;



void sysreset(CI_Msg *Command)
{
	NVIC_SystemReset();
}

int main(void)
{
	tx = malloc(sizeof(buf_ptr));
    tx->Buffer = malloc(sizeof(int8_t) * 100);
    init_buff(tx, 100);
    rx = malloc(sizeof(buf_ptr));
    rx->Buffer = malloc(sizeof(int8_t) * 100);
    init_buff(rx, 100);
    uart_configure();
    rtc_init();
    UART0_C2 |= UART0_C2_RIE_MASK; //Enable receiver interrupt
    typedef void (*func)(CI_Msg *Command);
    func fpointers[] = {red_on, red_off, blue_on ,blue_off , green_on , green_off ,green_brightness,blue_brightness,red_brightness,sysreset};
    while(1)
    {
    if(count > 0)
     {        m = 0;
    	      Buffer_remove(rx,(int8_t*)&Command->command);
              Buffer_remove(rx,&Command->length);
              k = Command->length;
              for(;k>0;k--)
              {
              Buffer_remove(rx,Command->data);
              Command->data++;
              l++;
              }
              Command->data = Command->data - l;
              l = 0;
              Buffer_remove(rx,&Command->checksum);
              k = Command->length;
              for(;k>0;k--)
              {
               m = m+*Command->data;
               Command->data++;
               l++;
              }
              Command->data = Command->data - l;
              l = 0;
              m = Command->command + Command->length + m;

              if(Command->checksum == m && Command->command != 10)
              {
              fpointers[Command->command](Command);

              if(Command->command >= 12)
              {
            	  int8_t arr4[] = " INVALID COMMAND ";
            	  src = arr4;
            	  log_string(src ,17 ,tx);
              }
              }
              else if (Command->command == 10)
			  {
              int8_t arr4[] = " TIME ";
              src = arr4;
              log_string(src ,6 ,tx);
           	  int8_t arr5[10];
              src = arr5;
              log_integer(src,RTC_TSR,16,tx);

			  }
              else
              {
            	  int8_t arr4[] = " INVALID CHECK ";
            	  src = arr4;
            	  log_string(src ,15 ,tx);
              }
      UART0_C2 |= UART0_C2_TIE_MASK;
      count =count -1;


    }
    }

}

void UART0_IRQHandler(void)
{
    __disable_irq();
    if (UART0_S1 & UART_S1_RDRF_MASK){
        rec = UART0_D;
        if(rec == 'e'){
            count++;
        }
        else{
        Buffer_add(rx,&rec);
        }
    }
    else if((UART0_S1 & UART_S1_TDRE_MASK))
    {

    	if(tx->Count!=0)
    	{
    	Buffer_remove(tx,&rec);
    	uart_send_byte(rec);
    	}
    	else
    	{
    	UART0_C2 &= ~UART0_C2_TIE_MASK;
    	}
    }

    __enable_irq();
}
