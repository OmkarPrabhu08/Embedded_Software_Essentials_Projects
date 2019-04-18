#include "MKL25Z4.h"
#include<stdint.h>
#include<stdio.h>
#include"dma.h"

void dma_init(void)
{

	//enable DMA clocks
  SIM_SOPT2 |= SIM_SOPT2_MCGFLLCLK_MASK;
  SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;
  SIM_SCGC7 |= SIM_SCGC7_DMA_MASK;

  // Disable DMA Mux channel
  DMAMUX0_CHCFG0 = 0x00;

  // Clear Source size and Destination size fields.
  DMA_DCR0 &= ~(DMA_DCR_SSIZE_MASK | DMA_DCR_DSIZE_MASK);
  DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK | DMAMUX_CHCFG_SOURCE(60); //dmamux channel enable and source selection
}

