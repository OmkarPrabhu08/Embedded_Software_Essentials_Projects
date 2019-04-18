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

#ifndef _DATA_H_
#define _DATA_H_
#include <stdint.h>
enum data_status {
  INVALID_POINTER_EQUALS_NULL,
  VALID_CONVERSION
};

struct data_parameters {
  int8_t *src;
  int8_t *dst;
  int8_t length;
  int8_t value;
};

typedef struct data_parameters data_param;
data_param *data_pointer;

/**
 * This rearranges data from little endian fashion to big endian fashio in memory
 *
 * @params mem_pointer structure which has 
           data(source data)
 *         length(length of data in bytes)
 *         
 * @return INVALID_POINTER_EQUALS_NULL if pointers are negative or zero or if length is negative 
 *         VALID_CONVERSION if conversion is successful
 */        
int8_t big_to_little32 (data_param *data_pointer);
/**
 * This rearranges data from little endian fashion to big endian fashio in memory
 *
 * @params mem_pointer structure which has 
 *         data(source data)
 *         length(length of data in bytes)
 *         
 * @return INVALID_POINTER_EQUALS_NULL if pointers are negative or zero or if length is negative 
 *         VALID_CONVERSION if conversion is successful
 */
int8_t little_to_big32 (data_param *data_pointer);

#endif /* data.h */

