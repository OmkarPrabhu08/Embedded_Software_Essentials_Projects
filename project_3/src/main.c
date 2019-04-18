#include "MKL25Z4.h"
#include "profiler.h"
#include "dma.h"
#include <string.h>

extern overflow;

void TPM1_IRQHandler(void)
{
__disable_irq();    //disable global interrupts
overflow++;
TPM1_SC |= TPM_SC_TOF_MASK; // Clear TOF flag by writing 1 to it
__enable_irq();     //enable global interrupts
}


uint16_t start_time, end_time, diff;

int main(void)
{
uint8_t arr1[10],arr2[10];
uint8_t status;
dma_init();                   //dma initialization
timer_config();               //timer initialization
start_time = read_count();   //start the count
status = my_memset_dma (arr1 , 25, 5000, BYTE_4_TRANSFER);
end_time = read_count();     //end the count
diff = end_time - start_time;  //difference in time
while(1);
return 0;
}
