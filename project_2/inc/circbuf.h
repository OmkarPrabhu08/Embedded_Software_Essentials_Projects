#ifndef __CIRBUFF_H__
#define __CIRBUFF_H__

#include <stdint.h>
#include <stdlib.h>



enum buff_status{
SUCCESS,
FAIL,
Allocate_Free,
Invalid_Pointer,
Non_Initialized_Buffer,
Add,
Remove,
Buffer_Full,
Buffer_Not_Full,
Buffer_Empty,
Buffer_Not_Empty,
Wrap_Add,
Wrap_Remove,
Over_Fill, 
Over_Empty
};

typedef struct buff_parameters {
int8_t *Buffer; 
int8_t *Head; 
int8_t *Tail; 
int8_t Length;
int8_t Count; 
int8_t Peak; 
}buf_ptr;
int8_t init_buff(buf_ptr *ptr , int8_t length);
int8_t Buffer_add(buf_ptr *ptr,int8_t *src);
int8_t Buffer_remove(buf_ptr *ptr,int8_t *dst);
int8_t Full(buf_ptr *ptr);
int8_t Empty(buf_ptr *ptr);
int8_t Peak(buf_ptr *ptr , int8_t index);
int8_t Destroy(buf_ptr *ptr);

#endif
