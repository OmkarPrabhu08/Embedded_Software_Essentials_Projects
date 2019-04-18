#ifndef INCLUDES_DMA_H_
#define INCLUDES_DMA_H_

#define SIM_SOPT2_MCGFLLCLK_MASK 0x4000000u
#define BYTE_1_TRANSFER 1
#define BYTE_2_TRANSFER 2
#define BYTE_4_TRANSFER 0


enum memory_status {
  SUCCESS,
  INVALID_POINTER_EQUALS_NULL,
  SRC_IN_DST_OVERLAP,
  INVALID_LENGTH
};

/*********************************************************************
*read_count
*	description:This function initializes dma
*	
*
*	parameters:N/A
*	returns: N/A
*********************************************************************/
void dma_init(void);

#endif /* INCLUDES_DMA_H_ */
