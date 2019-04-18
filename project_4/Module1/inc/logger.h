#ifndef _LOGGER_H_
#define _LOGGER_H_
#include <stdint.h>
#include "circbuf.h"


#define FRDM

/*enums which reflects
LOG IDs (status */

typedef enum {
LOGGER_INITIALZED,
GPIO_INITIALZED ,
SYSTEM_INITIALIZED,
SYSTEM_HALTED ,
INFO ,
WARNING,
ERROR ,
DATA_RECEIVED ,
DATA_ANALYSIS_STARTED,
DATA_ALPHA_COUNT,
DATA_NUMERIC_COUNT,
DATA_PUNCTUATION_COUNT,
DATA_MISC_COUNT,
DATA_ANALYSIS_COMPLETED
}LOG;
/*
structure which will store information about LOG
*/
typedef struct log_parameters {
LOG LogID;
int8_t Length;
int8_t *Payload;
}log;
/**
 * This creates log of given length and adds data on it and finally prints data for host and BBB and uart for FRDM
 *
 * @params src source of data to log
 *          length length of bytes to log
 *          ptr destination
 *
 * @return nothing
 */
void log_data(int8_t *src ,int8_t length, buf_ptr *ptr);
/**
 * This creates log of given length and adds data on it and finally prints data for host and BBB and uart for FRDM
 *
 * @params src source of data to log
 *          length length of bytes to log
 *          ptr destination
 *
 * @return nothing
 */
void log_string(int8_t *src ,int8_t length ,buf_ptr *ptr);
/**
 * This creates log of given length and adds an integer convert into to character  on it and finally prints data for host and BBB and uart for FRDM
 *
 * @params src source of data to log
 *          length length of bytes to log
 *          ptr destination
            base
 *
 * @return nothing
 */
void log_integer(int8_t *src, int32_t data , int32_t base ,buf_ptr *ptr);
/**
 * This will remove data from log until it's empty
 *
 * @params src source of data to log
 *          length length of bytes to log
 *          ptr destination
 *
 * @return nothing
 */
void log_flush(int8_t *src , buf_ptr *ptr , int8_t length);
/**
 * This will create log item based on LOG ID
 *
 * @params src source of data to log
 *          length length of bytes to log
 *          ptr destination
 *
 * @return nothing
 */
void create_log_item(log *ptr2 , LOG ID , int8_t *src ,int8_t length);
/**
 * This will add data to log
 *
 * @params log *ptr
 *
 *
 *
 * @return nothing
 */
void log_item( log *ptr2 , buf_ptr *ptr );
/**
 * This will free memory
 *
 * @params log ptr
 *
 *
 * @return nothing
 */
void destroy_log ( log *ptr2);
#endif
