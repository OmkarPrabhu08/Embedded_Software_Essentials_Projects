#include<stdio.h>
#include<stdint.h>
#include"data.h"
#include"memory.h"
#include"project_1.h"

#ifdef FRDM_PRINT
#define printf(...)
#endif

void test_data1 (uint32_t * arr)
{
  uint32_t length = 32; 
  print_memory ((uint8_t *)arr , length);                //printing initial array using pointers
  printf("\n");                                         
  big_to_little32 (arr , length);                        //calling big_to_little function 
  print_memory ((uint8_t *)arr , length);                //printing array after swapping using big_to_little
  printf("\n");                                          
  little_to_big32 (arr , length);                        //calling little_to_big function
  print_memory ((uint8_t *)arr , length);                //printing array after swapping using little_to_big
}

void test_data2 (int8_t *data)                               
{
  int8_t index;                                                    
  int8_t itoaresarr[100];                                //array to store result of itoa
  int8_t *itoares;                                       
  int8_t *atoires;                                             
  int8_t atoiresarr[32];                                 //array to store result of atoi
  int32_t base=10;
  int8_t index2;                      
  int8_t temporary; 
  int8_t temporary2;
  int8_t accumulator = 0;
  itoares = &itoaresarr[0];
  atoires = &atoiresarr[0];
  for (index = 0; index < 32; index++) {                                          
    my_itoa (itoares, (int32_t)*(data+index) , base);  //calling itoa function and storing results in itoares array  
    temporary2 = *(data+index);                         //saving data in variable so it won't be affected 
    if (temporary2 < 0) {                                //checking if data is negative if yes increasing index as we need one more byte to save - sign 
         index2 = 1;                                        
    } else {
         index2  = 0;
    }
    while (temporary2 != 0 && temporary >= 0) {         //counting digits of source element which is  in array and storing it in index 2
      temporary = temporary2%base;
      temporary2 = temporary2/base;
      index2++;
    }
    print_memory ( (uint8_t *)itoares, index2);                      
    itoares = itoares+index2+1;                         //incrementing pointer by number of digits
    accumulator = accumulator+index2+1;                 // accumulator used to store size of array
 }
 itoares = itoares-accumulator;                         //pulling back pointer to initial position 
 printf("\n");
 for (index = 0; index < 32; index++) {                  
   index2 = 0;
   while (*itoares != '\0') {                           //counting number of digits in element
   index2++;
   itoares++;
   }
   itoares = itoares-index2;                            //pulling back pointer to initial position
   *atoires = my_atoi (itoares);                        //storing result
   itoares = itoares+index2+1;                          
   atoires++;
 }
 atoires = atoires-32;                                   //pulling back pointer to initial position to print 
 print_memory ((uint8_t *)atoires , 32);
}

void test_memory (int8_t *data)
{
  my_reverse ((uint8_t *)data , 12);               
  my_memset ((uint8_t *)data+16 , 4,0xEE);
  my_memmove ((uint8_t *)data+26 , (uint8_t *)data+20, 6);
  my_memzero ((uint8_t *)data+11 , 4);
  my_memmove ((uint8_t *)data , (uint8_t *)data+8 , 8);
  print_memory ((uint8_t *)data , 32);
}

void project_1_report(void) 
{
 uint32_t arr1[8] = {0x01234567,0x89ABCDEF,0x01234567,0x89ABCDEF,0x01234567,0x89ABCDEF,0x01234567,0x89ABCDEF};
 int8_t arr2[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
 printf("Output of test_data1 is : \n");
 test_data1 (arr1);
 printf("\n");
 printf("Output of test_data2 is : \n");
 test_data2 (arr2);
 printf("\n");
 printf("Output of test_memory is : \n");
 test_memory (arr2);
}


