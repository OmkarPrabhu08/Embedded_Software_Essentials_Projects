
 #include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include"circbuf.h"
#include"data1.h"
#include"logger.h"
#include "uart.h"
#include "MKL25Z4.h"


void log_data(int8_t *src ,int8_t length, buf_ptr *ptr)
{
int8_t index = 0;
for(index = 0; index < length ; index++)
{
Buffer_add(ptr,src);
src++;
}
}

void log_string(int8_t *src ,int8_t length ,buf_ptr *ptr)
{
int8_t index = 0;
for(index = 0; index < length ; index++)
{
Buffer_add(ptr,src);
src++;
}
}

void log_integer(int8_t *src, int32_t data , int32_t base ,buf_ptr *ptr)
{
int8_t index1;
int8_t index2;
int32_t temporary1;
int32_t temporary2;
 temporary1 = data;
    if (temporary1 < 0) {
         index1 = 1;
    } else {
         index1  = 0;
    }
    while (temporary1 != 0) {
      temporary2 = temporary1%base;
      temporary1 = temporary1/base;
      index1++;
    }
my_itoa (src,data,base);

for(index2=0; index2<index1 ; index2++)
{
Buffer_add(ptr,src);
src++;
}
}

void log_flush(int8_t *src , buf_ptr *ptr , int8_t length)
{

int8_t index = 0;
for(index=0; index<length ; index++)
{
Buffer_remove(ptr,src);
src++;
}
}

void create_log_item(log *ptr2 ,LOG ID , int8_t *src ,int8_t length)
{
ptr2->LogID = ID;
ptr2->Length = length;
ptr2->Payload = src;
}

void log_item( log *ptr2 , buf_ptr *ptr )
{int8_t ptr3 ;
int8_t *ptr1;
ptr1 =  &ptr3;

log_integer(ptr1,RTC_TSR,16,ptr);
}


void destroy_log ( log *ptr2)
{

 free( ptr2);


}






