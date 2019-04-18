#include <math.h>
#include <stdlib.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "memory.h"

void test_pointer_equal_NULL1(void **state)
{ mem_param *pointer = malloc(sizeof(pointer));
  pointer->src = (int8_t *)NULL;
  pointer->dst = (int8_t *)NULL;
  pointer->length = 10;
  enum memory_status status = my_memmove(pointer);
  assert_int_equal(status,INVALID_POINTER_EQUALS_NULL);
}
void test_src_in_dst_overlap(void **state)
{ mem_param *pointer = malloc(sizeof(pointer));
  int8_t arr[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
  pointer->src = arr;
  pointer->dst = arr+9;
  pointer->length = 10;
  enum memory_status status = my_memmove(pointer);
  assert_int_equal(status,SRC_IN_DST_OVERLAP);
}
void test_dst_in_src_overlap(void **state)
{ mem_param *pointer = malloc(sizeof(pointer));
  int8_t arr[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
  pointer->src = arr+9;
  pointer->dst = arr;
  pointer->length = 10;
  enum memory_status status = my_memmove(pointer);
  assert_int_equal(status,SUCCESS);
}
void test_no_overlap(void **state)
{ mem_param *pointer = malloc(sizeof(pointer));
  int8_t arr[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
  pointer->src = arr;
  pointer->dst = arr+11;
  pointer->length = 10;
  enum memory_status status = my_memmove(pointer);
  assert_int_equal(status,SUCCESS);
}
void test_pointer_equal_NULL2(void **state)
{ mem_param *pointer = malloc(sizeof(pointer));
  pointer->src = (int8_t *)NULL;
  pointer->dst = (int8_t *)NULL;
  pointer->length = 0;
  enum memory_status status = my_memset(pointer);
  assert_int_equal(status,INVALID_POINTER_EQUALS_NULL);
}
void test_CHECK_SET1(void **state)
{ mem_param *pointer = malloc(sizeof(pointer));
  int8_t arr[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
  pointer->src = arr;
  pointer->value = 11;
  pointer->length = 10;
  enum memory_status status = my_memset(pointer);
  assert_int_equal(status,CHECK_SET);
}
void test_pointer_equal_NULL3(void **state)
{ mem_param *pointer = malloc(sizeof(pointer));
  pointer->src = (int8_t *)NULL;
  pointer->dst = (int8_t *)NULL;
  pointer->length = 0;
  enum memory_status status = my_memzero(pointer);
  assert_int_equal(status,INVALID_POINTER_EQUALS_NULL);
}
void test_CHECK_SET2(void **state)
{ mem_param *pointer = malloc(sizeof(pointer));
  int8_t arr[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
  pointer->src = arr;
  pointer->value = 11;
  pointer->length = 10;
  enum memory_status status = my_memset(pointer);
  assert_int_equal(status,CHECK_SET);
}
void test_pointer_equal_NULL4(void **state)
{ mem_param *pointer = malloc(sizeof(pointer));
  pointer->src = (int8_t *)NULL;
  pointer->length = 0;
  enum memory_status status = my_reverse(pointer);
  assert_int_equal(status,INVALID_POINTER_EQUALS_NULL);
}
void CHECK_EVEN(void **state)
{ mem_param *pointer = malloc(sizeof(pointer));
  int8_t arr[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
  pointer->src = arr;
  pointer->length = 10;
  enum memory_status status = my_reverse(pointer);
  assert_int_equal(status,CHECK_EVEN_REV);
}
void CHECK_ODD(void **state)
{ mem_param *pointer = malloc(sizeof(pointer));
  int8_t arr[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
  pointer->src = arr;
  pointer->length = 9;
  enum memory_status status = my_reverse(pointer);
  assert_int_equal(status,CHECK_ODD_REV);
}
void CHECK_CHAR(void **state)
{ mem_param *pointer = malloc(sizeof(pointer));
  int8_t arr[3]={'a','b','c'};
  pointer->src = arr;
  pointer->length = 3;
  enum memory_status status = my_reverse(pointer);
  assert_int_equal(status,CHECK_ODD_REV);
}


int main(int argc, char **argv)
{
  const struct CMUnitTest tests[] = {
  cmocka_unit_test(test_pointer_equal_NULL1),
  cmocka_unit_test(test_src_in_dst_overlap),
  cmocka_unit_test(test_dst_in_src_overlap),
  cmocka_unit_test(test_no_overlap),
  cmocka_unit_test(test_pointer_equal_NULL2),
  cmocka_unit_test(test_CHECK_SET1),
  cmocka_unit_test(test_pointer_equal_NULL3),
  cmocka_unit_test(test_CHECK_SET2),
  cmocka_unit_test(test_pointer_equal_NULL4),
  cmocka_unit_test(CHECK_EVEN),
  cmocka_unit_test(CHECK_ODD),
 cmocka_unit_test(CHECK_CHAR),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
