#include<stdio.h>
#include<stdint.h>
#include"data1.h"

#ifdef FRDM_PRINT
#define printf(...)
#endif

void print_memory (uint8_t * start, uint32_t length)
{
 uint8_t index;
 if(start <= 0 || length <= 0) {                                //Error if length or starting address is invalid
        printf("Error\n");
 } else {
        for(index = 0; index < length; index++) {

          printf("%x ",*start);                                  //printing out the hex values of the memory places
          start++;
        }
   }
}

int8_t * my_itoa (int8_t * str, int32_t data, int32_t base)
{
 int8_t index1 = 0;
 int32_t temporary;
 int32_t index2;
 int8_t value;

 if (str < 0 || base <= 0) {                                   //Error if length or base is invalid
      printf("Error");
 }
 else if(data<0) {                                             //checking if data is less negative

      data = -data;
      temporary = data;                                        //storing data in temporary variable so that data won't be modified and can be used for further operations
      while(temporary != 0) {                                  //counting digits and storing them in index1

        index2 = temporary%base;
        temporary = temporary/base;
        index1++;
      }
      index2 = 0;                                             //re-initializing index2 to 0 as it will be used for counting further
      while(data != 0) {                                      //seperating digits in a number as each digit represents character in string

        str = str+index1;                                     //incrementing pointer by number of digits which we stored in index1 earlier as last digit is calculated first
        *str = data%base+'0';                                 //digits will be stored upside down and hence no need of reversing string later
        data = data/base;                                     //Adding '0' to convert integer to ASCII
        str = str-index1;                                     //again decrementing pointer to store first character that is '-' at initial position
        index1--;                                             //Decrementing index1 and thus decrementing addition in pointer so that pointer will come down in each iteration
        index2++;                                             //Incrementing index2 so that last character that is '\0' would be stored at end position
      }
      *str = '-';                                             //Putting '-' at initial position
      str = str+index2+1;                                     //Shifting pointer to end position of the number so that '\0' will be stored at the end
      *str = '\0';
      str = str-index2-1;                                     //Return pointer to initial position
 }
 else {
      temporary = data;                                       //storing data in temporary variable so that data won't be modified and can be used for further operations
      while(temporary != 0) {                                 //counting digits and storing them in index1

        index2 = temporary%base;
        temporary = temporary/base;
        index1++;
      }
      index2 = 0;                                             //re-initializing index2 to 0 as it will be used for counting further
      while(data != 0) {                                      //seperating digits in a number as each digit represents character in string

         str = str+index1-1;
         value =  data%base;                                   //incrementing pointer by number of digits which we stored in index1 earlier as last digit is calculated first
         if(value<=9)
         {
         *str = data%base+'0';
         }                                                    //digits will be stored upside down and hence no need of reversing string later
         else
         {
         *str = data%base -10 +'A';
         }
         data = data/base;                                    //Adding '0' to convert integer to ASCII
         str = str-index1+1;                                  //again decrementing pointer to intial position
         index1--;                                            //Decrementing index1 and thus decrementing addition in pointer so that pointer will come down in each iteration
         index2++;                                            //Incrementing index2 so that last character that is '\0' would be stored at end position
      }
      str = str+index2;                                       //Shifting pointer to end position of the number so that '\0' will be stored at the end
      *str = '\0';
      str = str-index2;                                       //Return pointer to initial position
 }
 return str;
}

int8_t big_to_little32 (uint32_t * data, uint32_t length)
{
 uint8_t *temporary;
 temporary = (uint8_t*) data;
 uint8_t swap;
 uint8_t index;
 if(length <= 0 || data == 0) {
    printf("Error");                                         //Error for invalid length or data
    return 1;
 }
 for(index = 0;index < length;) {                            //swapping 1st and 4th byte and 2nd and 3rd byte using swap variable

    swap = *(temporary+index);
    *(temporary+index) = *(temporary+index+3);
    *(temporary+index+3) = swap;
    swap = *(temporary+index+1);
    *(temporary+index+1) = *(temporary+index+2);
    *(temporary+index+2) = swap;
    index = index+4;                                         //increasing index by 4 to swap next 4 bytes
 }
 return 0;
}

int8_t little_to_big32 (uint32_t * data, uint32_t length)
{
 uint8_t *temporary;
 temporary = (uint8_t*) data;
 uint8_t swap;
 uint8_t index;
 if(length <= 0 || data == 0) {
    printf("Error");                                        //Error for invalid length or data
    return 1;
 }
 for(index = 0;index < length;) {                           //swapping 1st and 4th byte and 2nd and 3rd byte using swap variable

    swap = *(temporary+index);
    *(temporary+index) = *(temporary+index+3);
    *(temporary+index+3) = swap;
    swap = *(temporary+index+1);
    *(temporary+index+1) = *(temporary+index+2);
    *(temporary+index+2) = swap;
    index = index+4;                                       //increasing index by 4 to swap next 4 bytes
 }
 return 0;
}



int32_t my_atoi (int8_t * str)
{
 int32_t final_value = 0;                                 //final_value variable will be used as accumulator
 int32_t sign = 1;
 if(*str == '-') {                                        //checks if any number is negative if yes multiplies it with sign to make it negative as sign=-1 in the end

   sign = -1;
   str++;                                                 //As pointer is now on '-' sign increase it to get next number
 }

 while(*str != '\0') {                                    //checks for terminating character to get idea about number of digits in one number
   final_value = final_value*10+*str-'0';                 //Combining all the digits to get actual number in accumulator subtracting '0' to get integer from ASCII
   str++;
 }
 return sign*final_value;                                 //Returning integer
}

