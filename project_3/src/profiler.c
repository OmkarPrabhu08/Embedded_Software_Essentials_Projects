#include "MKL25Z4.h"
#include "profiler.h"

int16_t overflow = 0;

 void timer_config (void)
{
SIM_SCGC6 |= SIM_SCGC6_TPM1_MASK; // Enable TPM1 Clock gate
SIM_SOPT2 |= SIM_SOPT2_MCGFLLCLK_MASK; // Enable fll clock
TPM1_MOD = 0xFFFF;
TPM1_SC |= (TPM_SC_TOF_MASK | TPM_SC_TOIE_MASK | TPM_SC_CMOD(1) | TPM_SC_PS(0));
NVIC_EnableIRQ(TPM1_IRQn);             //Enable tpm1 INTERRUPT IN nvic
__enable_irq(); // Enable global Interrupt
}

int16_t read_count(void)
{
	if(overflow == 0)
		return TPM1_CNT;
	else
		return ((overflow *65535) + TPM1_CNT);
}

