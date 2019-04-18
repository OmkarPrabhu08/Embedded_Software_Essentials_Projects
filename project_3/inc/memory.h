#ifndef INCLUDES_MEMORY_H_
#define INCLUDES_MEMORY_H_

/**
 * This moves certain bytes of data from source to destination address 
 *         
 * @return INVALID_POINTER_EQUALS_NULL if pointers are negative or zero or if length is negative 
 *         SRC_IN_DST_OVERLAP if source overlaps destination  
 *         SUCCESS if destination overlaps source or there is no overlap  
 */
int8_t my_memmove (uint8_t * src, uint8_t * dst, uint32_t length);

/**
 * sets source address to given value 
 *       
 * @return INVALID_POINTER_EQUALS_NULL if pointers are negative or zero or if length is negative 
 *         CHECK_SET if source is set to desired value 
 */
int8_t my_memset (uint8_t * dst, uint32_t length, uint8_t value);

/**
 * This moves certain bytes of data from source to destination address using dma
 *         
 * @return INVALID_POINTER_EQUALS_NULL if pointers are negative or zero or if length is negative 
 *         SRC_IN_DST_OVERLAP if source overlaps destination  
 *         SUCCESS if destination overlaps source or there is no overlap  
 */
int8_t my_memmove_dma (uint8_t * src, uint8_t * dst, uint32_t length, uint8_t size);

/**
 * sets source address to given value using dma
 *       
 * @return INVALID_POINTER_EQUALS_NULL if pointers are negative or zero or if length is negative 
 *         CHECK_SET if source is set to desired value 
 */
int8_t my_memset_dma (uint8_t * dst, uint8_t value, uint32_t length, uint8_t size);

#endif /* INCLUDES_MEMORY_H_ */
