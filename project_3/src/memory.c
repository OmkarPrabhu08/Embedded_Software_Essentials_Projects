#include<stdint.h>
#include"dma.h"
#include"memory.h"
#include"MKL25Z4.h"

int8_t my_memmove (uint8_t * src, uint8_t * dst, uint32_t length)
{
  enum memory_status status;
  int8_t index;

  if ( src <= 0 || dst <= 0 || length <= 0) {         //error for invalid length and if source addresses and destination addresses are overlapping
          status = INVALID_POINTER_EQUALS_NULL;
  }
  else if (dst > src && src + length  > dst) {  //error for invalid length and if source addresses and destination addresses are overlapping
          for(index = length-1; index >= 0; index--) {
          *(dst+index) = *(src+index);
          }
          status = SRC_IN_DST_OVERLAP;
  }
  else {
         for(index = 0; index < length; index++) {                   //copying sources to destinations
         *(dst + index) = *(src + index);
         }
         status = SUCCESS;
  }
  return status;
}

int8_t my_memmove_dma (uint8_t * src, uint8_t * dst, uint32_t length, uint8_t size)
{
  enum memory_status status;
  int8_t index;

  int32_t regval1,regval2,regval3;

  if ( src <= 0 || dst <= 0 || length <= 0) {         //error for invalid length and if source addresses and destination addresses are overlapping

          status = INVALID_POINTER_EQUALS_NULL;
  }
  else if (dst > src && src + length  > dst) {  //error for invalid length and if source addresses and destination addresses are overlapping
          for(index = length-1; index >= 0; index--) {
          *(dst+index) = *(src+index);
          }
          status = SRC_IN_DST_OVERLAP;
  }
  else {
	    if(size == BYTE_1_TRANSFER)
	    {
	      DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length); //number of bytes to trnsfer
	      DMA_DCR0 |= ( DMA_DCR_EINT_MASK | DMA_DCR_DINC_MASK | DMA_DCR_SINC_MASK | DMA_DCR_SSIZE(1) | DMA_DCR_DSIZE(1)); //1byte transfer size interrupt enable and source and destination increment after transfer
	  	  DMA_SAR0 = src;                   //source address
	  	  DMA_DAR0 = dst;                   //destination address 
	  	  DMA_DCR0 |= DMA_DCR_START_MASK;   //dma transfer start
	    }
	    else if(length % 2 == 0 && size == BYTE_2_TRANSFER)
	    {
	      DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length);   //number of bytes to trnsfer
	      DMA_DCR0 |= ( DMA_DCR_EINT_MASK | DMA_DCR_DINC_MASK | DMA_DCR_SINC_MASK | DMA_DCR_SSIZE(2) | DMA_DCR_DSIZE(2));//2byte transfer size interrupt enable and source and destination increment after transfer
	      DMA_SAR0 = src;                       //source address
	      DMA_DAR0 = dst;                       //destination address 
	      DMA_DCR0 |= DMA_DCR_START_MASK;         //dma transfer start
	    }
	    else if(length % 2 == 1 && size == BYTE_2_TRANSFER)
	    {
	      DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length - 1);
	      DMA_DCR0 |= ( DMA_DCR_EINT_MASK | DMA_DCR_DINC_MASK | DMA_DCR_SINC_MASK | DMA_DCR_SSIZE(2) | DMA_DCR_DSIZE(2));
	      DMA_SAR0 = src;
	      DMA_DAR0 = dst;
	      DMA_DCR0 |= DMA_DCR_START_MASK;
	      my_memmove((src + (length - 1)), (dst + (length - 1)), 1);
	    }
	    else if(length % 4 == 0 && size == BYTE_4_TRANSFER)
	    {
	      DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length);
	      DMA_DCR0 |= ( DMA_DCR_EINT_MASK | DMA_DCR_DINC_MASK | DMA_DCR_SINC_MASK | DMA_DCR_SSIZE(0) | DMA_DCR_DSIZE(0));//4byte transfer size interrupt enable and source and destination increment after transfer
	      DMA_SAR0 = src;              //source address
	      DMA_DAR0 = dst;               //destination address 
	      DMA_DCR0 |= DMA_DCR_START_MASK;     //dma transfer start
	    }
	    else if(length % 4 != 0 && size == BYTE_4_TRANSFER)
	    {
	      DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length - (length % 4));
	      DMA_DCR0 |= (DMA_DCR_EINT_MASK | DMA_DCR_DINC_MASK | DMA_DCR_SINC_MASK | DMA_DCR_SSIZE(0) | DMA_DCR_DSIZE(0));
	      DMA_SAR0 = src;
	      DMA_DAR0 = dst;
	      DMA_DCR0 |= DMA_DCR_START_MASK;
	      my_memmove((src + (length - (length % 4))), (dst + (length - (length % 4))), length % 4);
	    }
	    status = SUCCESS;
  }
  enav
  return status;
}

int8_t my_memset (uint8_t * dst, uint32_t length, uint8_t value)
{
  enum memory_status status;
  int8_t index;


  if (dst == 0 || length <= 0) {         //error for invalid length and if source addresses and destination addresses are overlapping
          status = INVALID_POINTER_EQUALS_NULL;
  } else {
         for (index = 0; index < length; index++) {                 //copying value to destinations
           *(dst + index) = value;
         }
         status = SUCCESS;
  }
  return status;
}

int8_t my_memset_dma (uint8_t * dst, uint8_t value, uint32_t length, uint8_t size)
{
  enum memory_status status;

  int32_t regval1,regval2,regval3;

  DMA_DCR0 = 0x00000000;                  //reset control register

  int8_t arr[4] = {value,value,value,value};

  if (length <= 0) {                                                //error for invalid length and if source address is 0
        status = INVALID_LENGTH;
  }
  else {
	  if(size == BYTE_1_TRANSFER)
	  	    {
	  	      DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length);
	  	      DMA_DCR0 |= ( DMA_DCR_EINT_MASK | DMA_DCR_DINC_MASK | DMA_DCR_SSIZE(1) | DMA_DCR_DSIZE(1));
	  	  	  DMA_SAR0 = arr;
	  	  	  DMA_DAR0 = dst;
	  	  	  DMA_DCR0 |= DMA_DCR_START_MASK;
	  	    }
	  	    else if(length % 2 == 0 && size == BYTE_2_TRANSFER)
	  	    {
	  	      DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length);
	  	      DMA_DCR0 |= ( DMA_DCR_EINT_MASK | DMA_DCR_DINC_MASK | DMA_DCR_SSIZE(2) | DMA_DCR_DSIZE(2));
	  	      DMA_SAR0 = arr;
	  	      DMA_DAR0 = dst;
	  	      DMA_DCR0 |= DMA_DCR_START_MASK;
	  	    }
	  	    else if(length % 2 == 1 && size == BYTE_2_TRANSFER)
	  	    {
	  	      DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length - 1);
	  	      DMA_DCR0 |= (DMA_DCR_EINT_MASK | DMA_DCR_DINC_MASK | DMA_DCR_SSIZE(2) | DMA_DCR_DSIZE(2));
	  	      DMA_SAR0 = arr;
	  	      DMA_DAR0 = dst;
	  	      DMA_DCR0 |= DMA_DCR_START_MASK;
	  	      my_memset((dst + (length - 1)), 1, value);
	  	    }
	  	    else if(length % 4 == 0 && size == BYTE_4_TRANSFER)
	  	    {
	  	      DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length);
	  	      DMA_DCR0 |= ( DMA_DCR_EINT_MASK |DMA_DCR_DINC_MASK | DMA_DCR_SSIZE(0) | DMA_DCR_DSIZE(0));
	  	      DMA_SAR0 = arr;
	  	      DMA_DAR0 = dst;
	  	      DMA_DCR0 |= DMA_DCR_START_MASK;
	  	    }
	  	    else if(length % 4 != 0 && size == BYTE_4_TRANSFER)
	  	    {
	  	      DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length - (length % 4));
	  	      DMA_DCR0 |= (DMA_DCR_EINT_MASK | DMA_DCR_DINC_MASK | DMA_DCR_SSIZE(0) | DMA_DCR_DSIZE(0));
	  	      DMA_SAR0 = arr;
	  	      DMA_DAR0 = dst;
	  	      DMA_DCR0 |= DMA_DCR_START_MASK;
	  	      my_memset((dst + (length - (length % 4))), length % 4, value);
	  	    }
  }
  __enable_irq();
   return status;
}
