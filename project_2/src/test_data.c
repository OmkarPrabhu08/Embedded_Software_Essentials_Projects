#include <math.h>
#include <stdlib.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../inc/data.h"
void IP1(void **state)
{ data_param *pointer = malloc(sizeof(pointer));
  pointer->length = 32;
  pointer->src = NULL;
  enum data_status status = big_to_little32(pointer);
  assert_int_equal(status,INVALID_POINTER_EQUALS_NULL);
}
void BIG_TO_LITTLE(void **state)
{ data_param *pointer = malloc(sizeof(pointer));
  int8_t arr[32] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x010,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x30,0x31,0x32};
  pointer->src = arr;
  pointer->length = 32;
  enum data_status status = big_to_little32(pointer);
  assert_int_equal(status,  VALID_CONVERSION);
}
void IP2(void **state)
{ data_param *pointer = malloc(sizeof(pointer));
  pointer->length = 32;
  pointer->src = NULL;
  enum data_status status = little_to_big32(pointer);
  assert_int_equal(status,INVALID_POINTER_EQUALS_NULL);
}

void LITTLE_TO_BIG(void **state)
{ data_param *pointer = malloc(sizeof(pointer));
  int8_t arr[32] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x30,0x31,0x32};
  pointer->src = arr;
  pointer->length = 32;
  enum data_status status = little_to_big32(pointer);
  assert_int_equal(status,  VALID_CONVERSION);
}

int main(int argc, char **argv)
{
  const struct CMUnitTest tests[] = {
  cmocka_unit_test(IP1),
  cmocka_unit_test(BIG_TO_LITTLE),
  cmocka_unit_test(IP2),
  cmocka_unit_test(LITTLE_TO_BIG),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
