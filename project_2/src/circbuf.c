#include <stdint.h>
#include <stdlib.h>
#include "cir_buff.h"



int8_t init_buff(buf_ptr *ptr , int8_t length)
{ enum buff_status status;
 if (ptr->Buffer == NULL || length <= 0) {
    status = FAIL;
 }
 else {
 ptr->Head = ptr->Buffer; 
 ptr->Tail = ptr->Buffer; 
 ptr->Count = 0;
 ptr->Peak = 0;
 ptr->Length = length;
 status = Allocate_Free;
 }
 return status;
}

 
int8_t Full(buf_ptr *ptr)
{ enum buff_status status;
 if (ptr->Count == ptr->Length) {
  status = Buffer_Full;
 }
 else {
  status = Buffer_Not_Full;
 }
 return status;
}
 
int8_t Empty(buf_ptr *ptr)
{ enum buff_status status;
 if (ptr->Count == 0) {
  status = Buffer_Empty;
 }
 else {
  status = Buffer_Not_Empty;
 }
 return status;
}

int8_t Buffer_add(buf_ptr *ptr,int8_t *src)
{ enum buff_status status;

 if (ptr->Count == ptr->Length)
 {
    status = Over_Fill;
 }
 else if(ptr->Head == ptr->Buffer + ptr->Length -1)
 {

   *ptr->Head = *src;
   ptr->Head = ptr->Buffer;
   ptr->Count++;
   status = Wrap_Add;
 }
 else 
 {

   *ptr->Head = *src;
   ptr->Head++;
   ptr->Count++;
   status = Add;
 }
 return status;
}

int8_t Buffer_remove(buf_ptr *ptr,int8_t *dst)
{ enum buff_status status;
 if (ptr->Count == 0)
 {
    status = Over_Empty;
 }
 else if(ptr->Tail == ptr->Buffer + ptr->Length -1)
 {    *dst = *ptr->Tail;
   ptr->Tail = ptr->Buffer;
   ptr->Count--;
   status = Wrap_Remove;
 }
 else 
 {

   *dst = *ptr->Tail;
   ptr->Tail++;
   ptr->Count--;
   status = Remove;
   
 }
 return status;
}

int8_t Destroy(buf_ptr *ptr)
{
 free( ptr->Buffer );
 return SUCCESS;
}

int8_t Peak(buf_ptr *ptr ,int8_t index)
{ enum buff_status status;
 if(index <= 0 || index >= ptr->Length)
{
   status = FAIL;
} 
 else 
{
  ptr->Peak = *( ptr->Buffer + index );
  status = SUCCESS;
}
return status;
}





   
 

 
 



 


