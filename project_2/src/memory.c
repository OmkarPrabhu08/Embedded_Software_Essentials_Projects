#include<stdio.h>
#include<stdint.h>
#include"memory.h"

#ifdef FRDM_PRINT
#define printf(...)
#endif

int8_t my_memmove (mem_param *mem_pointer)
{ enum memory_status status;
  int8_t index;

  if ( mem_pointer->src <= 0 || mem_pointer->dst <= 0 || mem_pointer->length <= 0) {         //error for invalid length and if source addresses and destination addresses are overlapping
          
          status = INVALID_POINTER_EQUALS_NULL;
  
  }                                
  else if (mem_pointer->dst > mem_pointer->src && mem_pointer->src + mem_pointer->length  > mem_pointer->dst) {  //error for invalid length and if source addresses and destination addresses are overlapping
          for(index = mem_pointer->length-1; index >= 0; index--) {
          
          *(mem_pointer->dst+index) = *(mem_pointer->src+index);
          
          }   
          status = SRC_IN_DST_OVERLAP;

  }
  else {
         for(index = 0; index < mem_pointer->length; index++) {                   //copying sources to destinations 
         
         *(mem_pointer->dst + index) = *(mem_pointer->src + index);
                 
         }
         status = SUCCESS;

  }
  return status;
}

int8_t my_memset (mem_param *mem_pointer)
{ enum memory_status status;
  int8_t index;
  

  if (mem_pointer->src == 0 || mem_pointer->length <= 0) {         //error for invalid length and if source addresses and destination addresses are overlapping

          status = INVALID_POINTER_EQUALS_NULL;

  

  } else {
         for (index = 0; index < mem_pointer->length; index++) {                 //copying value to destinations

           *(mem_pointer->src + index) = mem_pointer->value;
            
         }
         status = CHECK_SET;
  }
  return status;
}

int8_t my_memzero (mem_param *mem_pointer) 
{ enum memory_status status;
  int8_t index;
  if (mem_pointer->src == 0 || mem_pointer->length <= 0) {         //error for invalid length and if source addresses and destination addresses are overlapping

          status = INVALID_POINTER_EQUALS_NULL;

  

  } else {
         for (index = 0; index < mem_pointer->length; index++) {                 //copying value to destinations

           *(mem_pointer->src + index) = 0;              
                    
         }
         status = CHECK_SET;
  }
  return status;
}

int8_t my_reverse (mem_param *mem_pointer)
{ enum memory_status status;
  int8_t index;
  int8_t swapping_variable;
  
  
  if ( mem_pointer->src <= 0 || mem_pointer->length <= 0) {         //error for invalid length and if source addresses and destination addresses are overlapping
          
          status = INVALID_POINTER_EQUALS_NULL;
  
  }   
  else if(mem_pointer->length%2 == 0) {                                            //checking if the length is even
       for(index = 0;index < mem_pointer->length/2; index++) {                       // swapping using variable 
  
          swapping_variable = *(mem_pointer->src+index);
          *(mem_pointer->src+index) = *(mem_pointer->src+mem_pointer->length-index-1);
          *(mem_pointer->src+mem_pointer->length-index-1) = swapping_variable;
          status = CHECK_EVEN_REV;
  
       }
    
   }
  else if (mem_pointer->length%2 != 0) {                                     //checking if length is odd
       for(index = 0; index < (mem_pointer->length-1)/2; index++) {          //swapping using variable
  
           swapping_variable = *(mem_pointer->src+index);
           *(mem_pointer->src+index) = *(mem_pointer->src+mem_pointer->length-index-1);
           *(mem_pointer->src+mem_pointer->length-index-1) = swapping_variable;
           status = CHECK_ODD_REV;
         
       } 
   }
  
  return status;
  
}
int8_t big_to_little32 (mem_param *mem_pointer)
{enum memory_status status;
 int8_t swap;
 int8_t index;
 if(mem_pointer->length <= 0 || mem_pointer->src == 0) {
    status = INVALID_POINTER_EQUALS_NULL;                                    
 }
 else {
 for(index = 0;index < mem_pointer->length ;) {                            //swapping 1st and 4th byte and 2nd and 3rd byte using swap variable 
 
    swap = *(mem_pointer->src+index);
    *(mem_pointer->src+index) = *(mem_pointer->src+index+3);
    *(mem_pointer->src+index+3) = swap;
    swap = *(mem_pointer->src+index+1);
    *(mem_pointer->src+index+1) = *(mem_pointer->src+index+2);
    *(mem_pointer->src+index+2) = swap;
    index = index + 4; 
    status = VALID_CONVERSION;                                        //increasing index by 4 to swap next 4 bytes 
 }
 }
 return status ;
} 
int8_t little_to_big32 (mem_param *mem_pointer)
{enum memory_status status;
 int8_t swap;
 int8_t index;
 if(mem_pointer->length <= 0 || mem_pointer->src == 0) {
    status = INVALID_POINTER_EQUALS_NULL;                                    
 }
 else {
 for(index = 0;index < mem_pointer->length;) {                            //swapping 1st and 4th byte and 2nd and 3rd byte using swap variable 
 
    swap = *(mem_pointer->src+index);
    *(mem_pointer->src+index) = *(mem_pointer->src+index+3);
    *(mem_pointer->src+index+3) = swap;
    swap = *(mem_pointer->src+index+1);
    *(mem_pointer->src+index+1) = *(mem_pointer->src+index+2);
    *(mem_pointer->src+index+2) = swap;
    index = index + 4;  
    status = VALID_CONVERSION;                                      //increasing index by 4 to swap next 4 bytes 
}
 }
return status;
} 

