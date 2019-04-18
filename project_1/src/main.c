#include<stdio.h>
#include<stdint.h>
#include"project_1.h"

#ifdef FRDM_PRINT
#define printf(...)
#endif

int main()
{
#ifdef PROJECT1
project_1_report();
#endif
return 0;
}
