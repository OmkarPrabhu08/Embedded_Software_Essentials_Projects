/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                         //
//                                                                                                         //
//  @file             data.h                                                                               //
//  @author           Omkar Prabhu                                                                         //
//                    Aasheesh Dandupally                                                                  //
//  @brief            Defination file for data.c                                                           // 
//                                                                                                         //
//                                                                                                         //
//                                                                                                         //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _DATA_H_
#define _DATA_H_

/**
 * This converts integers in data array to characters(ASCII) and store them in str array 
 *
 * @params str (to store result)
 *         data(source data)
 *         base(decides whether conversion is in hex, bin or dec)
 *         
 * @return str(result pointer) unless it's an error condition, returns 1 in error condition 
 */
int8_t * my_itoa(int8_t * str, int32_t data, int32_t base);

/**
 * This converts characters(ASCII) in str array to integers
 *
 * @params str (source of characters)
 *        
 *         
 * @return signbit multiplied by integer
 */
int32_t my_atoi(int8_t * str);

/**
 * This rearranges data from big endian fashion to little endian fashio in memory
 *
 * @params data(source data)
 *         length(length of data in bytes)
 *         
 * @return returns nothing unless it's an error condition returns 1 in error condition
 */
int8_t big_to_little32(uint32_t * data, uint32_t length);

/**
 * This rearranges data from little endian fashion to big endian fashio in memory
 *
 * @params data(source data)
 *         length(length of data in bytes)
 *         
 * @return returns nothing unless it's an error condition returns 1 in error condition
 */
int8_t little_to_big32(uint32_t * data, uint32_t length);

/**
 * Prints elements in addresses 
 *
 * @params start(address to print)
 *         length(length of data in bytes which is to print)
 *         
 * @return nothing 
 */
void print_memory(uint8_t * start, uint32_t length);

#endif /* data.h */
