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
/**
 * This moves certain bytes of data from source to destination address 
 *
 * @params src(source address)
 *         dst(destination address)
 *         length(length of bytes to move)
 *         
 * @return nothing unless it's an error condition, returns 1 in error condition  
 */
int8_t my_memmove(uint8_t * src, uint8_t * dst, uint32_t length);

/**
 * sets source address to given value 
 *
 * @params src(source address)
 *         value(value to set)
 *         length(length of bytes to set)
 *
 * @return nothing unless it's an error condition, returns 1 in error condition  
 */
int8_t my_memset(uint8_t * src, uint32_t length, uint8_t value);

/**
 * sets source address to zero 
 *
 * @params src(source address)
 *         length(length of bytes to set to zero)
 *
 * @return nothing unless it's an error condition, returns 1 in error condition  
 */
int8_t my_memzero(uint8_t * src, uint32_t length);

/**
 * This reverses bytes in source address 
 *
 * @params src(source address)
 *         length(length of bytes to reverse
 *         
 * @return nothing  unless it's an error condition, returns 1 in error condition 
 */
int8_t my_reverse(uint8_t * src, uint32_t length);


#endif /* memory.h */
