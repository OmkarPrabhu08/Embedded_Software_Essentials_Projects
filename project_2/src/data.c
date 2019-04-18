#include<stdio.h>
#include<stdint.h>
#include"../inc/data.h"

#ifdef FRDM_PRINT
#define printf(...)
#endif


int8_t big_to_little32 (data_param *data_pointer)
{enum data_status status;
 int8_t swap;
 int8_t index;
 if(data_pointer->length <= 0 || data_pointer->src == 0) {
    status = INVALID_POINTER_EQUALS_NULL;                                    
 }
 else {
 for(index = 0;index < data_pointer->length ;) {                            //swapping 1st and 4th byte and 2nd and 3rd byte using swap variable 
 
    swap = *(data_pointer->src+index);
    *(data_pointer->src+index) = *(data_pointer->src+index+3);
    *(data_pointer->src+index+3) = swap;
    swap = *(data_pointer->src+index+1);
    *(data_pointer->src+index+1) = *(data_pointer->src+index+2);
    *(data_pointer->src+index+2) = swap;
    index = index + 4; 
                                         //increasing index by 4 to swap next 4 bytes 
 }
  status = VALID_CONVERSION;   
 }
 return status ;
} 
int8_t little_to_big32 (data_param *data_pointer)
{enum data_status status;
 int8_t swap;
 int8_t index;
 if(data_pointer->length <= 0 || data_pointer->src == 0) {
    status = INVALID_POINTER_EQUALS_NULL;                                    
 }
 else {
 for(index = 0;index < data_pointer->length ;) {                            //swapping 1st and 4th byte and 2nd and 3rd byte using swap variable 
 
    swap = *(data_pointer->src+index);
    *(data_pointer->src+index) = *(data_pointer->src+index+3);
    *(data_pointer->src+index+3) = swap;
    swap = *(data_pointer->src+index+1);
    *(data_pointer->src+index+1) = *(data_pointer->src+index+2);
    *(data_pointer->src+index+2) = swap;
    index = index + 4; 
                                        //increasing index by 4 to swap next 4 bytes 
 }
  status = VALID_CONVERSION;   
 }
 return status ;
} 
