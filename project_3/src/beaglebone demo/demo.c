#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

#define BILLION  1E9
	
int main()
{
  int i,status = 0;
  struct timespec start_time, end_time;
  double diff_time;
  int8_t arr1[10],arr2[10];	
  status = clock_gettime(CLOCK_REALTIME, &start_time);
  if(status != 0)
  printf("clock_gettime failed!");
  memset(arr1,25,10);
  status = clock_gettime(CLOCK_REALTIME, &end_time);
  if(status != 0)
  printf("clock_gettime failed!");
	
  diff_time = (( end_time.tv_sec - start_time.tv_sec ) + ( end_time.tv_nsec - start_time.tv_nsec )) / BILLION;
  printf("Time taken by the function is  %lf\n", diff_time );
	
  return status;
}
