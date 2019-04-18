#include<stdio.h>
#include<stdint.h>
#include"memory.h"

#ifdef FRDM_PRINT
#define printf(...)
#endif

int8_t my_memmove (uint8_t * src, uint8_t * dst, uint32_t length)
{
  uint16_t index;                                  
  if (src+length < dst || dst+length < src || length <= 0) {         //error for invalid length and if source addresses and destination addresses are overlapping
         printf("Error\n");                              
         return 1;
  } else {
         for(index = 0; index < length; index++) {                   //copying sources to destinations 
  
           *dst = *src;
           src++;
           dst++;
         }
    return 0;
  }
}

int8_t my_memset (uint8_t * src, uint32_t length, uint8_t value)
{
  uint16_t index;
  if (length <= 0) {                                                //error for invalid length and if source address is 0
         printf("Error\n");
         return 1;
  } else {
         for (index = 0; index < length; index++) {                 //copying value to destinations

           *src = value;    
           src++;  
         }
    return 0;
  }
}
int8_t my_memzero (uint8_t * src, uint32_t length) 
{
  uint16_t index;
  if (length <=0 || src == 0) {                                    //error for invalid length and if source address is 0
 
         printf("Error\n");
         return 1; 
  } else {
         for( index = 0; index < length; index++) {                //setting every location to zero  
           *src = 0;
           src++;
         }
    return 0;
  }
}

int8_t my_reverse (uint8_t * src, uint32_t length) {
  uint16_t index , swapping_variable;
  if (length != 0 || src == 0) {                                   //cheking if length is zero or if source is zero 
    if(length%2 == 0) {                                            //checking if the length is even
       for(index=0;index<length/2;index++) {                       // swapping using variable 
  
       swapping_variable = *(src+index);
       *(src+index) = *(src+length-index-1);
       *(src+length-index-1) = swapping_variable;
       }
    return 0;
    }
    else if (length%2 != 0) {                                     //checking if length is odd
         for(index = 0; index < (length-1)/2; index++) {          //swapping using variable
  
           swapping_variable = *(src+index);
           *(src+index) = *(src+length-index-1);
           *(src+length-index-1) = swapping_variable;
         } 
  return 0;
  }
  } else {
         printf("Error\n");                                      //error if length is 0 or source address is 0
    return 1;
  }
  return 0;
}


