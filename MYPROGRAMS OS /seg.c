#include<stdio.h>
#include<stdlib.h>



int main(void)
{
 /*   main();
    return 0;*/




char *p1 = NULL;           // Null pointer
char *p2;                  // Wild pointer: not initialized at all.
char *p3  = malloc(10 * sizeof(char));  // Initialized pointer to allocated mem                                     // (assuming malloc did not fail)
free(p3);  
}
