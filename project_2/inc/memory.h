/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                         //
//                                                                                                         //
//  @file             memory.h                                                                             //
//  @author           Omkar Prabhu                                                                         //
//                    Aasheesh Dandupally                                                                  //
//  @brief            Defination file for memory.c                                                         // 
//                                                                                                         //
//                                                                                                         //
//                                                                                                         //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _MEMORY_H_
#define _MEMORY_H_
#include <stdint.h>
enum memory_status {
  INVALID_POINTER_EQUALS_NULL,
  SUCCESS,
  NO_OVERLAP,
  SRC_IN_DST_OVERLAP,
  DST_IN_SRC_OVERLAP,
  CHECK_SET,
  CHECK_ODD_REV,
  CHECK_EVEN_REV,
  CHECK_CHAR_REV,
  VALID_CONVERSION
};

struct memory_parameters {
  int8_t *src;
  int8_t *dst;
  int8_t length;
  int8_t value;
};

typedef struct memory_parameters mem_param;
mem_param *mem_pointer;
/**
 * This moves certain bytes of data from source to destination address 
 *
 * @params mem_pointer structure which has 
           src(source address)
 *         dst(destination address)
 *         length(length of bytes to move)
 *         
 * @return INVALID_POINTER_EQUALS_NULL if pointers are negative or zero or if length is negative 
 *         SRC_IN_DST_OVERLAP if source overlaps destination  
 *         SUCCESS if destination overlaps source or there is no overlap  
 */
int8_t my_memmove(mem_param *mem_pointer);

/**
 * sets source address to given value 
 *
 * @params mem_pointer structure which has 
           src(source address)
 *         value(value to set)
 *         length(length of bytes to set)
 *
 * @return INVALID_POINTER_EQUALS_NULL if pointers are negative or zero or if length is negative 
 *         CHECK_SET if source is set to desired value 
 */
int8_t my_memset(mem_param *mem_pointer);

/**
 * sets source address to zero 
 *
 * @params mem_pointer structure which has 
           src(source address)
 *         length(length of bytes to set to zero)
 *
 * @return INVALID_POINTER_EQUALS_NULL if pointers are negative or zero or if length is negative 
 *         CHECK_SET if source is set to 0  
 *         
 */
int8_t my_memzero(mem_param *mem_pointer);

/**
 * This reverses bytes in source address 
 *
 * @params mem_pointer structure which has 
           src(source address)
 *         length(length of bytes to reverse
 *         
 * @return INVALID_POINTER_EQUALS_NULL if pointers are negative or zero or if length is negative 
 *         CHECK_EVEN_REV if reverse is successful for even length 
 *         CHECK_ODD_REV  if reverse is successful for odd length 
 */
int8_t my_reverse(mem_param *mem_pointer);


#endif /* memory.h */

