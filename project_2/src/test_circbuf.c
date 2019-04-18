#include <math.h>
#include <stdlib.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "cir_buff.h"

void Inv_Pointer(void **state)
{ buf_ptr *ptr = malloc( sizeof(buf_ptr) );
  int8_t length = 8;
  ptr->Buffer = (int8_t *)NULL;
  enum buff_status status  =   init_buff(ptr ,length); 
  assert_int_equal(status,FAIL);
}
void Nn_Initialized_Buffer(void **state)
{ int8_t length = 0;
  buf_ptr *ptr = malloc( sizeof(buf_ptr) );
  ptr->Buffer = malloc( sizeof (int8_t) * length );
  enum buff_status status =   init_buff(ptr ,length); 
  assert_int_equal(status,FAIL);
}
void Allcate_Free(void **state)
{ int8_t length = 8;
  buf_ptr *ptr = malloc( sizeof(buf_ptr) );
  ptr->Buffer = malloc( sizeof (int8_t) * length );
  enum buff_status status = init_buff(ptr ,length); 
  assert_int_equal(status,Allocate_Free);
}
void ADD_REMOVE(void **state)
{ int8_t length = 8;
  buf_ptr *ptr = malloc( sizeof(buf_ptr) );
  ptr->Buffer = malloc( sizeof (int8_t) * length );
  init_buff(ptr ,length); 
  int8_t source =10;
  int8_t *src;
  src = &source;
  Buffer_add(ptr,src);
  enum buff_status status = Buffer_remove(ptr,src);
  assert_int_equal(status,Remove);
}
void Buffer_Fll(void **state)
{ int8_t length = 8;
  buf_ptr *ptr = malloc( sizeof(buf_ptr) );
  ptr->Buffer = malloc( sizeof (int8_t) * length );
  init_buff(ptr ,length); 
  int8_t index =1;
  int8_t source =10;
  int8_t *src;
  src = &source;
  for(;index<= length;index++) {
  Buffer_add(ptr,src);
  }
  enum buff_status status = Full(ptr);
  assert_int_equal(status,Buffer_Full);
}
void Buffer_Empt(void **state)
{ int8_t length = 8;
  buf_ptr *ptr = malloc( sizeof(buf_ptr) );
  ptr->Buffer = malloc( sizeof (int8_t) * length );
  
  init_buff(ptr ,length); 
  int8_t index =1;
  int8_t source =10;
  int8_t *src;
  src = &source;
  for(;index<= length;index++) {
  Buffer_add(ptr,src);
  }
  for(index=1;index<= length;index++) {
  Buffer_remove(ptr,src);
  }
  enum buff_status status = Empty(ptr);
  assert_int_equal(status,Buffer_Empty);
}
void Buffer_WA(void **state)
{ int8_t length = 8;
  buf_ptr *ptr = malloc( sizeof(buf_ptr) );
  ptr->Buffer = malloc( sizeof (int8_t) * length );
  init_buff(ptr ,length); 
  int8_t index =1;
  int8_t source =10;
  int8_t *src;
  src = &source;
  for(;index<= length-1;index++) {
  Buffer_add(ptr,src);
  }
  enum buff_status status =   Buffer_add(ptr,src);
  assert_int_equal(status,Wrap_Add);
}
void Buffer_WR(void **state)
{ int8_t length = 8;
  buf_ptr *ptr = malloc( sizeof(buf_ptr) );
  ptr->Buffer = malloc( sizeof (int8_t) * length );
  init_buff(ptr ,length); 
  int8_t index =1;
  int8_t source =10;
  int8_t *src;
  src = &source;
  for(;index<= length;index++) {
  Buffer_add(ptr,src);
  }
  for(index=1;index<= length-1;index++) {
  Buffer_remove(ptr,src);
  }
  enum buff_status status =   Buffer_remove(ptr,src);
  assert_int_equal(status,Wrap_Remove);
}
void Over_Fi(void **state)
{ int8_t length = 8;
  buf_ptr *ptr = malloc( sizeof(buf_ptr) );
  ptr->Buffer = malloc( sizeof (int8_t) * length );
  init_buff(ptr ,length); 
  int8_t index =1;
  int8_t source =10;
  int8_t *src;
  src = &source;
  for(;index<= length;index++) {
  Buffer_add(ptr,src);
  }
  enum buff_status status =   Buffer_add(ptr,src);
  assert_int_equal(status,Over_Fill);
}
void Over_Em(void **state)
{ int8_t length = 8;
  buf_ptr *ptr = malloc( sizeof(buf_ptr) );
  ptr->Buffer = malloc( sizeof (int8_t) * length );
  init_buff(ptr ,length); 
  int8_t index =1;
  int8_t source =10;
  int8_t *src;
  src = &source;
  for(;index<= length;index++) {
  Buffer_add(ptr,src);
  }
  for(index=0;index<= length;index++) {
  Buffer_remove(ptr,src);
  }
  enum buff_status status =   Buffer_remove(ptr,src);
  assert_int_equal(status,Over_Empty);
}

int main(int argc, char **argv)
{
  const struct CMUnitTest tests[] = {
  cmocka_unit_test(Inv_Pointer),
  cmocka_unit_test(Nn_Initialized_Buffer),
  cmocka_unit_test(Allcate_Free),
  cmocka_unit_test(ADD_REMOVE),
  cmocka_unit_test(Buffer_Fll),
  cmocka_unit_test(Buffer_Empt),
  cmocka_unit_test(Buffer_WA),
  cmocka_unit_test(Buffer_WR),
  cmocka_unit_test(Over_Fi),
  cmocka_unit_test(Over_Em),
  };


  return cmocka_run_group_tests(tests, NULL, NULL);
}
